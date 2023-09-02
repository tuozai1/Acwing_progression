#include <iostream>
using namespace std;

int n,m;

void dfs(int u,int x,int state){                // u表示第几个数字，x表示当前的数字
    if(u > m){
        for(int i = 1;i <= n;i++)
            if(state >> i & 1)
                printf("%d ",i);
        puts("");
        return;
    }
    if(x > n) return;
    
    for(int i = x;i <= n;i++)                   // 保证字典序
        dfs(u + 1,i + 1,state | (1 << i));
}

int main(){
    scanf("%d%d",&n,&m);
    dfs(1,1,0);
    return 0;
}