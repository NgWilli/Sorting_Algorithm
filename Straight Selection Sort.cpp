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
	selected=j;//��ʼ����СԪ�أ�����������ͷ��ʼ��
	for (i=j;i<10;i++)//����������ʼ
	{
		if (r[i]<r[selected])
		{
			//����ҵ���С�� ��¼��ǰ������
			selected=i;
		}

	}
	//����������СԪ�ط�����������һ��������ȡ��1

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