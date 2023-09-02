/*从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案*/
/*  5 3                             1 2 3 
                                    1 2 4 
                                    1 2 5 
                                    1 3 4 
                                    1 3 5 
                                    1 4 5 
                                    2 3 4 
                                    2 3 5 
                                    2 4 5 
                                    3 4 5 */

#include <iostream>
using namespace std;

const int N = 30;
int n,m;
int a[N];
bool st[N];

void dfs(int u,int x){          // u表示第几个数字，x表示当前的数字
    if(u > m){
        for(int i = 1;i <= m;i++) printf("%d ",a[i]);
        puts("");
        return;
    }
    
    for(int i = x;i <= n;i++){          // 保证字典序
        if(!st[i]){
            st[i] = true;
            a[u] = i;
            dfs(u + 1,i + 1);
            st[i] = false;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1);
    return 0;
}