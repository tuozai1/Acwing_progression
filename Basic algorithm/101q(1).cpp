// 同样思路，上面是用二位数组记录
#include <iostream>
#include <set>
using namespace std;

const int N = 5010;
int a[N];

int main(){
    int n,p,h,m;
    scanf("%d%d%d%d",&n,&p,&h,&m);
    set<pair<int,int>> existed;
    a[0] = h;
    for(int i = 0,l,r;i < m;i++){
        scanf("%d%d",&l,&r);
        if(l > r) swap(l,r);
        if(!existed.count({l,r})){
            existed.insert({l,r});
            a[l + 1]--,a[r]++;
        }
    }
    
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
        printf("%d\n",a[i]);
    }
    return 0;
}