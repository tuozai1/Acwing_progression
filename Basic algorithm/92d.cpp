/*从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案*/
/*  3                       3
                            2
                            2 3
                            1
                            1 3
                            1 2
                            1 2 3*/

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;

void dfs(int x){
    if(x > n){
        for(int i = 0;i < a.size();i++) printf("%d ",a[i]);
        puts("");
        return;
    }
    
    dfs(x + 1);             // 不选x
    
    a.push_back(x);         // 选x      记录x已被选择
    dfs(x + 1);
    a.pop_back();           // 还原现场
}

int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}