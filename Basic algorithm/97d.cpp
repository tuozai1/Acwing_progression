/*假设现在有两个自然数 A 和 B，S 是 AB 的所有约数之和。请你求出 Smod9901 的值是多少*/
/*  2 3                       15*/

#include <iostream>
using namespace std;

const int mod = 9901;
int A,B;

int qmi(int a,int b,int p){
    a %= p;
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int sum(int p,int k){
    if(k == 0) return 1;        // 边界
    if(k % 2 == 0) return (p % mod * sum(p,k - 1) % mod + 1) % mod;
    return (1 + qmi(p,k / 2 + 1,mod)) % mod * sum(p,k / 2) % mod;       // 
}

int main(){
    scanf("%d%d",&A,&B);
    int res = 1;
    for(int i = 2;i <= A;i++){
        int s = 0;
        while(A % i == 0){              // 质因数分解
            s++;
            A /= i;
        }
        
        if(s) res = res * sum(i,s * B) % mod;
    }
    
    if(!A) res = 0;
    printf("%d",res);
    return 0;
}