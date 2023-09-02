/*有 C 头奶牛进行日光浴，第 i 头奶牛需要 minSPF[i] 到 maxSPF[i] 单位强度之间的阳光。
每头奶牛在日光浴前必须涂防晒霜，防晒霜有 L 种，涂上第 i 种之后，身体接收到的阳光强度就会稳定为 SPF[i]，第 i 种防晒霜有 cover[i] 瓶。
求最多可以满足多少头奶牛进行日光浴。*/
/*第一行输入整数 C 和 L。
接下来的 C 行，按次序每行输入一头牛的 minSPF 和 maxSPF 值，即第 i 行输入 minSPF[i] 和 maxSPF[i]。
再接下来的 L 行，按次序每行输入一种防晒霜的 SPF 和 cover 值，即第 i 行输入 SPF[i] 和 cover[i]。*/
/*  3 2
    3 10                        2
    2 5
    1 5
    6 2
    4 1*/

// 贪心     以minSPF从大到小遍历，每次选择能用的防晒霜中 SPF 值最大的防晒霜来用 相当于给n个区间，m个点，最多能有几个区间内填入点
// 遍历n    二分查找log₂n    O(nlog₂n)
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> PII;

const int N = 2510;
int n,m;
PII cows[N];        // 存minSPF和maxSPF

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++) scanf("%d%d",&cows[i].first,&cows[i].second);
    
    map<int,int> spfs;          // 阳光强度SPF和cover瓶
    for(int i = 0;i < m;i++){
        int spf,cover;
        scanf("%d%d",&spf,&cover);
        spfs[spf] += cover;     // 有重复种类应该相加
    }
    
    sort(cows,cows + n);    // 根据minSPF大小排序
    int res = 0;
    for(int i = n - 1;i >= 0;i--){      // minSPF从大到小遍历
        auto spf = spfs.upper_bound(cows[i].second);    // upper_bound()返回在数组中大于一个数的的最小数的下标
        spf--;      // 下标减去1以后就是符合区间的点
        if(spf->first >= cows[i].first && spf->first <= cows[i].second){    // 如果符合区间要求
            res++;          // 满足条件的牛增加
            if(--spf->second == 0) spfs.erase(spf);         // 防晒霜数量减少，如果该种防晒霜用完，删去该防晒霜
        }
    }
    
    printf("%d",res);
    return 0;
}