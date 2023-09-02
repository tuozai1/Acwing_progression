/*地图上有 N 个目标，用整数 Xi,Yi 表示目标在地图上的位置，每个目标都有一个价值 Wi
有一种新型的激光炸弹，可以摧毁一个包含 R×R 个位置的正方形内的所有目标。
激光炸弹的投放是通过卫星定位的，但其有一个缺点，就是其爆炸范围，即那个正方形的边必须和 x，y 轴平行。
求一颗炸弹最多能炸掉地图上总价值为多少的目标*/
/*  2 1                         1
    0 0 1
    1 1 1*/

#include <iostream>
using namespace std;

const int N = 5010;
int n,r;
int s[N][N];

int main(){
    scanf("%d%d",&n,&r);
    r = min(5001,r);        // r最大可以取1e9，地图最大5000
    while(n--){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        a++,b++;            // 使得初始坐标为(1,1)
        s[a][b] += w;
    }
    
    int m = 5001;
    for(int i = 1;i <= m;i++)
        for(int j = 1;j <= m;j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    
    int res = 0;
    for(int i = r;i <= m;i++)
        for(int j = r;j <= m;j++)
            res = max(res,s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
    
    printf("%d",res);
    return 0;
}