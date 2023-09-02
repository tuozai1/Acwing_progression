/*给定一个长度为 n 的数列 a1,a2,…,an，每次可以选择一个区间 [l,r]，使下标在这个区间内的数都加一或者都减一。
求至少需要多少次操作才能使数列中的所有数都一样，并求出在保证最少次数的前提下，最终得到的数列可能有多少种*/
/*  4
    1                           1
    1                           2
    2
    2*/

/*差分序列b，题目对序列a的操作，相当于每次可以选出b1,b2…b(n + 1)中的任意两个数，一个加1，另外一个减一，
目标是把b2,b3,…bn变为全0。最终得到的数列a就是由 n 个 b1 构成的。
任选两个数的方法可分为四类
1、2 <= i , j <=n（优先）
2、i = 1, 2 <=j <=n
3、2 <= i <= n , j = n + 1
4、i = 1, j = n + 1（没有意义）
设b2,b3....bn中正数总和为p，负数总和的绝对值为q。首先以正负数匹配的方式尽量执行1类操作，可执行min(p,q)次。
剩余|p - q|个为匹对，每个可以选与b1或b(n + 1)匹配，即执行2 或 3 类操作，共需|p - q|次
最少操作次数为min(p,q) + |p - q|    序列a可能有|p - q| + 1 种*/
#include <iostream>
using namespace std;
typedef long long LL;

const int N = 100010;
int n,a[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = n;i;i--) a[i] -= a[i - 1];
    
    LL pos = 0,neg = 0;
    for(int i = 2;i <= n;i++)               // 分别算出正数和负数的和
        if(a[i] > 0) pos += a[i];
        else neg -= a[i];
        
    printf("%lld\n",min(pos,neg) + abs(pos - neg));     // 进行min(p,q)次1操作，再进行|p - q|次2或3操作，可直接等于max(p,q)
    printf("%lld",abs(pos - neg) + 1);          // 进行|p - q|次2或3操作，可能的a序列有|p - q| + 1种
    return 0;
}