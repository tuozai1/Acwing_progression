/*给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。
Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。*/
/*  5                       第 i 行第 j 个整数表示点 i 到 j 的距离
    0 2 4 5 1                           18
    2 0 6 5 3
    4 6 0 8 3
    5 5 8 0 5
    1 3 3 5 0*/

// 状态压缩DP    最短Hamilton路径
#include <iostream>
#include <cstring>
using namespace std;

const int N = 20,M = 1 << N;
int n;  
int f[M][N],w[N][N];                    // f表示所有从0走到j,走过的所有点的情况是i的所有路径；w表示的是无权图

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            scanf("%d",&w[i][j]);
            
    memset(f,0x3f,sizeof f);
    f[1][0] = 0;                            // 因为零是起点,所以f[1][0] = 0;
    
    for(int i = 0;i < 1 << n;i++)           // i表示所有的情况，由二进制数表示
        for(int j = 0;j < n;j++)            // j表示走到哪一个点
            if(i >> j & 1)
                for(int k = 0;k < n;k++)            // k表示走到j这个点之前,以k为终点的最短距离
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j],f[i - (1 << j)][k] + w[k][j]);    // 与到达k点，然后加上从k到j的长度的总长比较
            
    printf("%d",f[(1 << n) - 1][n - 1]);    // (1 << n) - 1代表二进制n-1个1，表示0~n-1都走过，停留在n-1
    return 0;
}