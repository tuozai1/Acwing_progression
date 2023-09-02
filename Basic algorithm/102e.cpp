/*农夫约翰的农场由 N 块田地组成，每块地里都有一定数量的牛，其数量不会少于 1 头，也不会超过 2000 头。
约翰希望用围栏将一部分连续的田地围起来，并使得围起来的区域内每块地包含的牛的数量的平均值达到最大。
围起区域内至少需要包含 F 块地，其中 F 会在输入中给出。
在给定条件下，计算围起区域内每块地包含的牛的数量的平均值可能的最大值是多少*/
/*输出一个整数，表示平均值的最大值乘以 1000 再 向下取整 之后得到的结果*/
/*  10 6    
    6                       6500
    4
    2
    10
    3
    8
    5
    9
    4
    1*/

#include <iostream>
using namespace std;

const int N = 100010;
int n,f;
int cow[N];
double sum[N];

bool check(double avg){
    for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + cow[i] - avg;   // 计算前缀和，每个前缀和减去二分值
    
    double mins = 0;
    for(int i = f,j = 0;i <= n;i++,j++){    // 双指针
        mins = min(mins,sum[j]);        // 存储sum[i]所遍历到的最小值
        if(sum[i] - mins >= 0) return true; // 用sum[j]去减去minv的话，就能得到我们的最优解，如果这个最优解>= 0 那么就满足我们的指定条件
    }
    return false;            // 如果所有的都不满足，那么这个平均数就一定不满足
}

int main(){
    scanf("%d%d",&n,&f);
    double l = 0,r = 0;
    for(int i = 1;i <= n;i++){
        scanf("%d",&cow[i]);
        r = max(r,(double)cow[i]);          // 右端点取到牛数量最大值
    }
    
    while(r - l > 1e-5){            // 由于答案要 * 1000向下取整,精度要1e-5
        double mid = (l + r) / 2;       // 实数不能 >> 1
        if(check(mid)) l = mid;         // 将问题转变为判定问题
        else r = mid;
    }
    
    printf("%d",(int)(r * 1000));
    return 0;
}