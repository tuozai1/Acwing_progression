/*把 1∼n 这 n 个整数排成一行后随机打乱顺序，输出所有可能的次序*/
/*3                 1 2 3
                    1 3 2
                    2 1 3
                    2 3 1
                    3 1 2
                    3 2 1*/

// 全排列
#include <iostream>
using namespace std;

const int N = 10;
int n,a[N];
bool st[N];

void dfs(int x){                        
    if(x > n){
        for(int i = 1;i <= n;i++) printf("%d ",a[i]);
        puts("");
    }
    
    for(int i = 1;i <= n;i++){
        if(!st[i]){
            st[i] = true;
            a[x] = i;
            dfs(x + 1);
            st[i] = false;              // 回溯
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}