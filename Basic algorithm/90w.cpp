/*求 a 乘 b 对 p 取模的值*/
/*  3                               2
    4
    5*/
// O(log₂n)
#include <iostream>
using namespace std;
typedef unsigned long long ULL;

ULL a,b,p;

int main(){
    scanf("%lld%lld%lld",&a,&b,&p);
    
    ULL res = 0;
    while(b){
        if(b & 1) res = (res + a) % p;      // 转化为a*2k
        a = (a + a) % p;
        b >>= 1;
    }
    
    printf("%lld",res);
    return 0;
}