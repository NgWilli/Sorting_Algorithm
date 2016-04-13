#include<stdio.h>
#include <iostream>
#include <iostream>
#include<algorithm>
#include<vector>
#define N 100
#define RADIX_10 10;
using namespace std;

void buble_sort(int a[], int n)
{
    for (int k = 1; k <= n - 1; ++k)//交换的次数 N个数一共需要冒泡n-1次
    {
       int noswap = 1; //表示这一次没有交换 一旦某一次没有交换 直接退出程序即可
        for (int j = n - 1; j >= k; --j)
            if (a[j] < a[j-1])
            {
                swap(a[j], a[j-1]);
               noswap = 0;// 0代表交换了
            }
        if (noswap) break;
    }
}
int main()
{
    int a[]={5,2,4,10,3};
    
    buble_sort(a, 5);
      for (int i=0; i<5; i++) {
        cout<<a[i];
    }
    cout<<endl;
       return 0;
}