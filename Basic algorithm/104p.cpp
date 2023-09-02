/*在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。
现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。
为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。*/
/*  4
    6 2 9 1                                     12*/

// 绝对值不等式
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,q[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++) scanf("%d",&q[i]);
    
    sort(q,q + n);
    
    int res = 0;
    for(int i = 0;i < n;i++) res += abs(q[i] - q[n / 2]);   // 对于两个点选址问题，最短距离之和是两点之间，推广到n个商店，应该选最中间
                                                            // 的两个点之间，商店个数为奇数时中位数只有一个，偶数是中位数两个，由于可以取
    printf("%d",res);                                       // 闭区间的任何一个点，n / 2向下取整，选其中一个中位数
    return 0;
}