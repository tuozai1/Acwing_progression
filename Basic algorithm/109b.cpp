/*给定一个整数 M，对于任意一个整数集合 S，定义“校验值”如下:
从集合 S 中取出 M 对数(即 2×M 个数，不能重复使用集合中的数，如果 S 中的整数不够 M 对，则取到不能取为止)，
使得“每对数的差的平方”之和最大，这个最大值就称为集合 S 的“校验值”。
现在给定一个长度为 N 的数列 A 以及一个整数 T。
我们要把 A 分成若干段，使得每一段的“校验值”都不超过 T。求最少需要分成几段。*/
/*  2
    5 1 49                          2
    8 2 1 7 9                       1
    5 1 64
    8 2 1 7 9*/

// 倍增     本题复杂度要求严苛，要过应用归并排序，分为排序过和为排过最后归并
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 500010;
int n, m;
int cnt;
LL T;
LL w[N],t[N];

LL sq(LL x)
{
    return x * x;
}

LL get(int l, int r) 
{
    int k = 0;
    for(int i = l;i < r;i++) t[k++] = w[i];
    sort(t,t + k);          // 排序
    LL sum = 0;
    for(int i = 0; i < m && i < k;i++,k--) sum += sq(t[i] - t[k - 1]);  // 每次目前最大的数减去最小的数平方之和就是校验数
    return sum;
}

int main()
{
    int K;
    scanf("%d",&K);
    while (K--)
    {
        scanf("%d%d%lld",&n,&m,&T); 
        for(int i = 0;i < n;i++) scanf("%lld",&w[i]);
        cnt = 0;
        int l = 0,r = 0;          // 左右端点初始为0
        while(r < n)
        {
            int len = 1;                 
            while(len)               // 倍增
            {
                if(r + len <= n && get(l, r + len) <= T){       // 不大于T且数字没有用完
                    r += len;
                    len <<= 1;
                }
                else len >>= 1;        
            }
            l = r;              // 分段后更新左端点 
            cnt++;              // 分段数增加
        }
        printf("%d\n",cnt);
    }
    return 0;
}