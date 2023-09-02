/*题目复杂，去网站看：https://www.acwing.com/problem/content/100/ 困难警告！*/
/*  3 
    1 1 2                           10
    2 16 1                          30   
    3 4 33                          50*/

#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

PLL calc(LL n,LL m){        // n代表城市等级，m为街区编号
    if(!n) return {0,0};
    LL len = 1ll << (n - 1),cnt = 1ll << (2 * n - 2); // n - 1级图构成n级图平移时的单位长度，n - 1级图中所含的元素个数 1ll << (2 * (n - 1))
    auto pos = calc(n - 1,m % cnt);     // 算出在n级图中，编号为m的元素所属块的坐标，(m%cnt)为在n级图中，编号为m的元素在所属块中的编号
    auto x = pos.first,y = pos.second;
    auto z = m / cnt;                   // 在n级图中，编号为m的元素所属块的编号
    if(z == 0) return {y,x};            // 顺时针旋转90，沿x轴翻转
    if(z == 1) return {x,y + len};      // 平移
    if(z == 2) return {x + len,y + len};            // 平移
    return {len * 2 - 1 - y,len - x - 1};           // 逆时针选择90，沿x轴翻转，平移
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL N,A,B;
        scanf("%lld%lld%lld",&N,&A,&B);
        auto ac = calc(N,A - 1);            // 计算A坐标，由于点从1开始，坐标(0,0)开始，A - 1
        auto bc = calc(N,B - 1);            // 计算B坐标
        double x = ac.first - bc.first,y = ac.second - bc.second;     // A与B横坐标和纵坐标的差
        printf("%.0lf\n",sqrt(x * x + y * y) * 10);         // 距离公式，保留整数
    }
    return 0;
}