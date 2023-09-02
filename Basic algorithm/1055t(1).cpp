/*题目同上*/

// 线性DP
#include <iostream>
using namespace std;

const int N = 100010;
int f[N][2];        // 第i个股票时是否持有股票的情况的利润最大值，0表示未持有，1表示持有
int n,w[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&w[i]);
    
    f[0][1] = -2e9;
    for(int i = 1;i <= n;i++){
        f[i][0] = max(f[i - 1][0],f[i - 1][1] + w[i]);  // i - 1个股票时持有并在i个1卖出
        f[i][1] = max(f[i - 1][1],f[i - 1][0] - w[i]);  // i - 1个股票时未持有并在i个买入
    }
    
    printf("%d",f[n][0]);       // 最后在第n个股票卖出时为最大值
    return 0;
}