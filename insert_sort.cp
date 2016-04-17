#include<stdio.h>
#include <iostream>
#include <iostream>
#include<algorithm>
#include<vector>
#define N 100
#define RADIX_10 10;
using namespace std;
void insert_sort2(int a[],int n)
{

    for(int i=1;i<n;i++)
    {
    if(a[i]<a[i-1])//must use sort
    {
        int temp=a[i];
        int k=i-1;
        while (k>=0 && temp<a[k]) {
            a[k+1]=a[k];
            --k;
        }
        a[k+1]=temp;
    }
    }
}
void insert_sort(int a[], int n)
{
    for (int cur = 1; cur < n; ++cur)
    {
        int j = cur - 1;
        int t = a[cur];
        while (j >= 0)
        {
            if (a[j] > t)
                a[j+1] = a[j];
            else
                break;
            --j;
        }
        a[j+1] = t;
    }
}

int main()
{
    int a[]={5,2,4,10,3};
   
    insert_sort2(a, 5);
   
   
    for (int i=0; i<5; i++) {
        cout<<a[i];
    }
    cout<<endl;
       return 0;
}