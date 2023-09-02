/*25 盏灯排成一个 5×5 的方形。每一个灯都有一个开关，游戏者可以改变它的状态。每一步，游戏者可以改变某一个灯的状态。
游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。
我们用数字 1 表示一盏开着的灯，用数字 0 表示关着的灯。*/
/*下面这种状态

10111
01101
10111
10000
11011
在改变了最左上角的灯的状态后将变成：

01111
11101
10111
10000
11011*/
/*  3
    00111                               3
    01011
    10001
    11010
    11100

    11101                               2
    11101
    11110
    11111
    11111

    01111                               -1
    11111
    11111
    11111
    11111*/

// O(2^n * n^2 * n)
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e5;
int n;
char g[10][10];
int dx[] = {0,1,-1,0,0},dy[] = {0,0,0,1,-1};

void turn(int x,int y){                         // 对(x,y)的按钮进行操作
    for(int i = 0;i < 5;i++){
        int a = x + dx[i],b = y + dy[i];
        if(a >= 0 || a < 5 || b >= 0 || b < 5) continue;        // 处理边界
        g[a][b] = '0' + !(g[a][b] - '0');           // 将1改为0，0改为1     也可以用异或操作
    }
}

int work(){
    int ans = INF;                          // 由于固定每一行就固定了下一行，因此将第一行固定则可以推出所有数组
    for(int k = 0;k < 1 << 5;k++){          // 枚举第一行32种按法，把第一行所有情况遍历
        int res = 0;
        char backup[10][10];
        memcpy(backup,g,sizeof g);              // 把原始数组备份一下，然后操作g，操作完了还原，然后再操作
        
        for(int j = 0;j < 5;j++){       // 第一行的按法
            if(k >> j & 1){
                res++;                  // 按钮次数增加
                turn(0,j);
            }
        }
        
        for(int i = 0;i < 4;i++)        // 对第一行到倒数第二行的0进行操作
            for(int j = 0;j < 5;j++)
                if(g[i][j] == '0'){
                    res++;
                    turn(i + 1,j);      // 处理0就是将该位置的下一行按按钮
                }
                    
        bool successful = true;
        for(int j = 0;j < 5;j++){
            if(g[4][j] == '0'){         // 最后一行遍历到0，无法使所有灯变亮
                successful = false;
                break;
            }
        }
        
        if(successful) ans = min(ans,res);          // 比较出最小次数
        
        memcpy(g,backup,sizeof backup);
    }
    
    if(ans > 6) return -1;          // 6 步以内无法使所有灯变亮，则输出 −1
    return ans;
}

int main(){
    scanf("%d",&n);
    while(n--){
        for(int i = 0;i < 5;i++) scanf("%s",g[i]);          // 按行输入，把每一行当成一个字符串
        printf("%d\n",work());
    }
    return 0;
}