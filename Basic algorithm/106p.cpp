/*依次读入一个整数序列，每当已经读入的整数个数为奇数时，输出已读入的整数构成的序列的中位数*/
/*对于每个数据集，第一行输出两个整数，分别代表数据集的编号以及输出中位数的个数（应为数据个数加一的二分之一），数据之间用空格隔开。
数据集的剩余行由输出的中位数构成，每行包含 10 个数据，最后一行数据量可能少于 10 个，数据之间用空格隔开。输出中不应该存在空行。*/
/*  3                                                           1 5
    1 9                                                         1 2 3 4 5
    1 2 3 4 5 6 7 8 9                                           2 5
    2 9                                                         9 8 7 6 5
    9 8 7 6 5 4 3 2 1                                           3 12
    3 23                                                        23 23 22 22 13 3 5 5 3 -3 
    23 41 13 22 -3 24 -31 -11 -8 -7                             -7 -3
    3 5 103 211 -311 -45 -67 -73 -81 -99 
    -33 24 56*/

/*对顶堆算中位数    小于中位数的都放在大根堆，大于中位数的都放在小根堆，如果说，一个堆的个数大于了当前序列的1/2，
那么就将多余的数移过去，直到两个堆数量相等*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int t;          // 数据集个数
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        priority_queue<int> max_heap;           // 大根堆
        priority_queue<int,vector<int>,greater<int>> min_heap;          // 小根堆
        
        printf("%d %d\n",m,(n + 1) / 2);            // 输出编号和中位数个数
        int cnt = 0;                // 用于分隔输出,每十个数一行
        for(int i = 0;i < n;i++){
            int x;
            scanf("%d",&x);
            max_heap.push(x);       // 插入大根堆
            if(min_heap.size() && min_heap.top() < max_heap.top()){     // 小根堆不为空且大根堆堆顶大于小根堆堆顶
                auto a = min_heap.top(),b = max_heap.top();
                min_heap.pop(),max_heap.pop();
                min_heap.push(b),max_heap.push(a);
            }
            
            if(max_heap.size() > min_heap.size() + 1){      // 大根堆数量大于小根堆加1，将大根堆堆顶添加入小根堆
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            
            if(!(i & 1)){
                printf("%d ",max_heap.top());       // 每插入奇数个数就输出一次中位数
                if(++cnt % 10 == 0) puts("");       // 每10个数就换行
            }
        }
        if(cnt % 10) puts("");       // 不是整十数行,就手动输入一个空行
    }
    return 0;
}