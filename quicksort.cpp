#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;
int partition(int r[],int i,int j)//对区间从i到j的位置进行partation
{
	int pivot=r[i];//使用第一个元素当做pivot
	while(i<j)
	{
	while (j>i&&pivot<r[j])
	{
		j--;//后面的不懂，指针向前移动
	}
	//不满足上述循环，j>i或者pivot<r[j]
	if (j>i)//交换
	{
		r[i]=r[j];//r[i]存的是没用的信息
		i++;
	}

	//此时r[j]里面的信息是没用的
	while (j>i&& r[i]<pivot)
	{
		i++;
	}
	if (j>i)
	{
		r[j]=r[i];
		j--;
	}
	}
	//如果到这里说明i=j,可以将pivot就可以了
	r[i]=pivot;
	return i;

}
void QuickSort(int r[],int low,int high)
{
	int pivot;
	if (low<high)//如果只有一个元素，那么直接返回
	{
		pivot=partition(r,low,high);
		QuickSort(r,low,pivot-1);
		QuickSort(r,pivot+1,high);

	}
}
int main()
{
	int SeqList[10]={2,4,6,8,10,20,13,16,17,18};
	QuickSort(SeqList,0,9);
	for (int temp=0;temp<10;temp++)
	{
		cout<<SeqList[temp]<<" ";
	}
}
