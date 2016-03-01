#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;
void SelectSort(int r[])
{   int temp;
int selected;
int i,j;
for (j=0;j<10;j++)
{
	selected=j;//初始化最小元素，从无序区起头开始。
	for (i=j;i<10;i++)//从无序区开始
	{
		if (r[i]<r[selected])
		{
			//如果找到更小的 记录当前的索引
			selected=i;
		}

	}
	//将无序区最小元素放在无序区第一个，有序取加1

	temp=r[j];
	r[j]=r[selected];
	r[selected]=temp;
	for (int temp=0;temp<10;temp++)
	{
		cout<<r[temp]<<" ";
	}
	cout<<endl;
}

}
int main()
{
	int SeqList[10]={2,4,6,8,10,20,13,16,17,18};
	SelectSort(SeqList);
	for (int temp=0;temp<10;temp++)
	{
		cout<<SeqList[temp]<<" ";
	}
}