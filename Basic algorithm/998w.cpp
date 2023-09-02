/*防御战线由 n 扇防御门组成。每扇防御门包括一个运算 op 和一个参数 t，其中运算一定是 OR,XOR,AND 中的一种，参数则一定为非负整数。
如果还未通过防御门时攻击力为 x，则其通过这扇防御门后攻击力将变为 x op t。
最终 drd 受到的伤害为对方初始攻击力 x 依次经过所有 n 扇防御门后转变得到的攻击力。
他的初始攻击力只能为 0 到 m 之间的一个整数（即他的初始攻击力只能在 0,1,…,m 中任选，但在通过防御门之后的攻击力不受 m 的限制）。
他希望通过选择合适的初始攻击力使得他的攻击能让 drd 受到最大的伤害，请你帮他计算一下，他的一次攻击最多能使 drd 受到多少伤害*/
/*  3 10
    AND 5                       1
    OR 6
    XOR 7*/

// 位运算应用       一共要判断 logm 次，每次判断是 O(n) 的，所以总的时间复杂度是 O(nlogm)
#include <iostream>
using namespace std;

const int N = 100010;
pair<string,int> a[N];
int n,m;

int calc(int bit,int now){              // 代表现在运算的是二进制的第几位， now有两种情况，需要运算过后返回
    for(int i = 1;i <= n;i++){              // 进行n次操作
        int x = a[i].second >> bit & 1;     // 首先取出第i次运算中的第几位进行二进制运算
        if(a[i].first == "AND") now &= x;
        else if(a[i].first == "OR") now |= x;
        else now ^= x;
    }
    return now;             // 返回运算过后的二进制位
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++) cin >> a[i].first >> a[i].second;
    
    int ans = 0,val = 0;
    for(int i = 29;~i;i--){     // 由于2<=m<=1e9，log₂1e9=3log₂1e3<3*10=30，最多有29个二进制位，直接从高位到低位枚举每一位
        int res0 = calc(i,0);       // 查看填0之后是否变化
        int res1 = calc(i,1);       // 查看填1之后是否变化
        if(val + (1 << i) <= m && res0 < res1){     // 该位填1后，所得到的数不大于m，且填1的情况1比填0大，则填1
            val += 1 << i;                  // 总数增加
            ans += res1 << i;               // 答案增加
        }
        else ans += res0 << i;              // 不能填1，则填0
    }
    
    printf("%d",ans);           
    return 0;
}