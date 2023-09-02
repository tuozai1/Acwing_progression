// STL方法
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
int n,a[N];

void dfs(int x){
    do{
        for(int i = 1;i <= n;i++) printf("%d ",a[i]);
        puts("");
    }
    while(next_permutation(a + 1,a + n + 1));
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) a[i] = i;
    dfs(1);
    return 0;
}