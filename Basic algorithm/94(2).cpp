#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
int n;

void dfs(int u,int state){
    if(u > n){
        for(auto x : path) cout << x << ' ';
        puts("");
        return;
    }
    
    for(int i = 1;i <= n;i++){
        if(!(state >> i & 1)){
            path.push_back(i);
            dfs(u + 1,state | (1 << i));
            path.pop_back();
        }
    }
}

int main(){
    scanf("%d",&n);
    dfs(1,1);
    return 0;
}