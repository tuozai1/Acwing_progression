// 状态压缩递归
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void dfs(int u,int state){                  // state表示选的情况
    if(u > n){
        for(int i = 1;i <= n;i++)
            if(state >> i & 1)
                printf("%d ",i);
            puts("");
        return;
    }
    
    dfs(u + 1,state);                       // 不使用u
    dfs(u + 1,state | (1 << u));            // 使用u
}

int main(){
    scanf("%d",&n);
    dfs(1,0);
    return 0;
}