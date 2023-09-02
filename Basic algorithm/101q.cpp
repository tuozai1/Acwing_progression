/*有 N 头牛站成一行，被编队为 1、2、3…N，每头牛的身高都为整数。当且仅当两头牛中间的牛身高都比它们矮时，两头牛方可看到对方。
现在，我们只知道其中最高的牛是第 P 头，它的身高是 H ，剩余牛的身高未知。
但是，我们还知道这群牛之中存在着 M 对关系，每对关系都指明了某两头牛 A 和 B 可以相互看见。求每头牛的身高的最大可能值是多少*/
/*第一行输入整数 N,P,H,M，数据用空格隔开。
接下来 M 行，每行输出两个整数 A 和 B ，代表牛 A 和牛 B 可以相互看见，数据用空格隔开 #此题中给出的关系对可能存在重复*/
/*  9 3 5 5                         5
    1 3                             4
    5 3                             5
    4 3                             3
    3 7                             4
    9 8                             4
                                    4
                                    5
                                    5*/

#include <iostream>
using namespace std;

const int N = 5010;
int a[N];
bool st[N][N];          // 用于判断关系是否重复

int main(){
    int n,p,h,m;        // 本题p没有作用
    scanf("%d%d%d%d",&n,&p,&h,&m);
    
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l > r) swap(l,r);
        if(!st[l][r]){          // 关系不重复，则进行操作
            a[l + 1]--,a[r]++;
            st[l][r] = true;    // 标记关系已使用
        }
    }
    
    a[0] = h;
    for(int i = 1;i <= n;i++){
        a[i] += a[i - 1];
        printf("%d\n",a[i]);
    }
    return 0;
}