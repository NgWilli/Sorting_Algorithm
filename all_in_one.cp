#include<stdio.h>
#include <iostream>
#include <iostream>
#include<algorithm>
#include<vector>
#define N 100
#define RADIX_10 10;
using namespace std;
void select_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (a[j] < a[k])
                k = j;
        swap(a[i], a[k]);
    }
}
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
void quicksort(int v[], int left, int right)
{
    if(left < right){
        int key = v[left];
        int low = left;
        int high = right;
        while(low < high){
            while(low < high && v[high] > key){
                high--;
            }
            v[low] = v[high];
            while(low < high && v[low] < key){
                low++;
            }
            v[high] = v[low];
        }
        v[low] = key;
        quicksort(v,left,low-1);
        quicksort(v,low+1,right);
    }
}

//合并函数
void Merge(int a[], int l, int m, int r)
{
    int i = l, j = m+1, k = l;
    int b[N];//n=100;
    while(i <= m && j <= r)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    
    if(i > m)
    {
        for(int p = j; p <= r; p ++)
        {
            b[k++] = a[p];
        }
    }
    else
    {
        for(int p = i; p <= m; p ++)
        {
            b[k++] = a[p];
        }
    }
    
    //把b[]中排好的元素copy到a[]中
    for(int q = l; q <= r; q ++)
    {
        a[q] = b[q];
    }
}

//  归并排序 递归算法表示
void MergeSort(int a[], int left, int right)
{
    if(left < right)    //数组至少要有两个元素
    {
        int i = (right + left)/2;
        MergeSort(a, left, i);
        MergeSort(a, i+1, right);
        Merge(a, left, i, right); //把left到right的元素排序好
    }
}


void HeapAdjust(int *a,int i,int size)  //调整堆
{
    int lchild=2*i;       //i的左孩子节点序号
    int rchild=2*i+1;     //i的右孩子节点序号
    int max=i;            //临时变量
    if(i<=size/2)          //如果i是叶节点就不用进行调整
    {
        if(lchild<=size&&a[lchild]>a[max])
        {
            max=lchild;
        }
        if(rchild<=size&&a[rchild]>a[max])
        {
            max=rchild;
        }
        if(max!=i)
        {
            swap(a[i],a[max]);
            HeapAdjust(a,max,size);    //避免调整之后以max为父节点的子树不是堆
        }
    }
}

void BuildHeap(int *a,int size)    //建立堆
{
    int i;
    for(i=size/2;i>=1;i--)    //非叶节点最大序号值为size/2
    {
        HeapAdjust(a,i,size);
    }
}

void HeapSort(int *a,int size)    //堆排序
{
    int i;
    BuildHeap(a,size);
    for(i=size;i>=1;i--)
    {
        //cout<<a[1]<<" ";
        swap(a[1],a[i]);           //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面
        //BuildHeap(a,i-1);        //将余下元素重新建立为大顶堆
        HeapAdjust(a,1,i-1);      //重新调整堆顶节点成为大顶堆
    }
}
void shellsort(int a[], int n)
{
    int i, j, gap;
    
    for (gap = n / 2; gap > 0; gap /= 2) //步长 按照二倍递减
        for (i = 0; i < gap; i++)        //直接插入排序  对于0-gap内的每一个数就是后面每一组的第一个数 所以又 gap个组 分别进行插入排序
        {
            for (j = i + gap; j < n; j += gap)
                if (a[j] < a[j - gap])
                {
                    int temp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > temp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = temp;
                }
        }
}
void radix_sort(int a[], int n, int L)//L为最多有多少位 就是需要排序多少次
{
    int *bucket = new int[n];//
    int count[10];//引用计数
    int power = 1;
    
    for (int k = 1; k <= L; ++k)
    {
        memset(count, 0, sizeof(count[0]) * n);
        //统计每个桶的右边界
        for (int i = 0; i < n; ++i) ++count[(a[i]/power)%10];//如果某个数个位为3，那么count[3]+1
        for (int i = 1; i < 10; ++i) count[i] += count[i-1];
        //装桶,这里从后往前扫描是因为边界值是从右往左递减的
        for (int i = n-1; i >= 0; --i) bucket[--count[(a[i]/power)%10]] = a[i];
        //收集
        memcpy(a, bucket, sizeof(a[0]) * n);
        power *= 10;
    }
    delete bucket;
}
int GetNumInPos(int num,int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;
    
    return (num / temp) % 10;
}
void RadixSort2(int* pDataArray,int iDataNum)
{
    int *radixArrays[10];    //分别为0~9的序列空间
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }
    
    for (int pos = 1; pos <= 10; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < iDataNum; i++)    //分配过程
        {
            int num = GetNumInPos(pDataArray[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = pDataArray[i];
        }
        for (int i = 0,j =0; i < 10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                pDataArray[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
}

int main()
{
    int a[]={5,2,4,10,3};
    //select_sort(a, 5);
    insert_sort2(a, 5);
    //buble_sort(a, 5);
    //quicksort(a, 0,4);
    //MergeSort(a, 0, 4);
    //shellsort(a, 5);
    // radix_sort(a, 5, 2);
    RadixSort2(a, 5);
    for (int i=0; i<5; i++) {
        cout<<a[i];
    }
    cout<<endl;
    int b[]={0,5,2,4,6,3};
    HeapSort(b, 5);
    for (int i=1; i<6; i++) {
        cout<<b[i];
    }
    cout<<endl;
    return 0;
}