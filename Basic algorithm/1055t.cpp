/*给定一个长度为 N 的数组，数组中的第 i 个数字表示一个给定股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/
/*  6
    7 1 5 3 6 4                     7*/

/*1.第i天持有股票，如果下一天还涨，w[i] < w[i + 1]，那么应该继续持有，否则以w[i]卖出
  2.第i天不持有股票，如果下一天还涨，那么应该以w[i]买入，否则继续不持有*/
// 贪心
#include <iostream>
using namespace std;

const int N = 100010;
int w[N],n;

int main(){
    scanf("%d",&n);
    int res = 0;
    for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
        
    for(int i = 1;i <= n;i++) res += max(w[i + 1] - w[i],0);    // 归纳后最大利润就是每一段价格上升高度之和
    printf("%d",res);
    return 0;
}