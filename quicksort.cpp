#include<iostream>  
#include<vector>
#include<algorithm>
#include <string> 
#include <sstream>
#include <set>
using namespace std;
int partition(int r[],int i,int j)//�������i��j��λ�ý���partation
{
	int pivot=r[i];//ʹ�õ�һ��Ԫ�ص���pivot
	while (j>i&&pivot<r[j])
	{
		j--;//����Ĳ�����ָ����ǰ�ƶ�
	}
	//����������ѭ����j>i����pivot<r[j]
	if (j>i)//����
	{
		r[i]=r[j];//r[i]�����û�õ���Ϣ
		i++;
	}

	//��ʱr[j]�������Ϣ��û�õ�
	while (j>i&& r[i]<pivot)
	{
		i++;
	}
	if (j>i)
	{
		r[j]=r[i];
		j--;
	}
	//���������˵��i=j,���Խ�pivot�Ϳ�����
	r[i]=pivot;
	return i;

}
void QuickSort(int r[],int low,int high)
{
	int pivot;
	if (low<high)//���ֻ��һ��Ԫ�أ���ôֱ�ӷ���
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