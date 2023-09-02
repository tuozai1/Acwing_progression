/*求 a 的 b 次方对 p 取模的值*/
/*3 2 7                          2*/

// O(log₂n)
#include <iostream>
using namespace std;
typedef long long LL;

int main(){
    int a,b,p;
    scanf("%d%d%d",&a,&b,&p);

    LL res = 1 % p;                 // 防止p为1的情况，导致答案为0，输出为1
    while(b){
        if(b & 1) res = (LL)res * a % p;        // 快速幂，转化为a^2k
        a = (LL)a * a % p;
        b >>= 1;
    }

    printf("%lld",res);
    return 0;
}