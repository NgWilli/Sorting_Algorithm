#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;

void Merge(int r[],int low ,int middle ,int high)
{
	vector<int> temp_array;
	int low_pointer=low;
	int high_pointer=middle+1;
	//cout<<"now merging"<<low<<" to "<<middle<<" AND "<<middle+1<<"  to "<<high<<endl;
	while (low_pointer<=middle&&high_pointer<=high)//两组队列都有值
	{
		if (r[low_pointer]>r[high_pointer])
		{
			temp_array.push_back(r[high_pointer]);
			//cout<<r[high_pointer]<<" ";
			high_pointer++;
		}
		else
		{
			temp_array.push_back(r[low_pointer]);
		//	cout<<r[low_pointer]<<" ";
			low_pointer++;
		}
	}

	while (low_pointer<=middle)
	{
		temp_array.push_back(r[low_pointer]);
		//cout<<r[low_pointer]<<" ";
		low_pointer++;
	}

	while (high_pointer<=high)
	{
		temp_array.push_back(r[high_pointer]);
		//cout<<r[high_pointer]<<" ";

		high_pointer++;
	}
	for (int pointer=low;pointer<=high;pointer++)
	{
		r[pointer]=temp_array[pointer-low];
	}
	/*
	    cout<<"now the merged list is :";
		for (int temp=low;temp<=high;temp++)
		{
			cout<<r[temp]<<" ";
		}
		cout<<endl;
		*/
		temp_array.clear();
}


void MergeSort(int array[], int start, int end)
{
	if (start < end)
		{
				int i;
				i = (end + start) / 2;
				// 对前半部分进行排序
				MergeSort(array, start, i);
				// 对后半部分进行排序
				MergeSort(array, i + 1, end);
				// 合并前后两部分
				Merge(array, start, i, end);
		}
}

int main()
{
	int SeqList[10]={5,4,6,8,10,20,17,16,13,22};
	MergeSort(SeqList,0,9);
	int list1[12]={3,6,9,10,13,4,5,11,12,13,15,20};
	//Merge(list1,0,4,11);
	
	for (int temp=0;temp<10;temp++)
	{
		cout<<SeqList[temp]<<" ";
	}
	
}