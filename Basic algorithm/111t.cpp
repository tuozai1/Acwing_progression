/*有 N 头牛在畜栏中吃草。每个畜栏在同一时间段只能提供给一头牛吃草，所以可能会需要多个畜栏。
给定 N 头牛和每头牛开始吃草的时间 A 以及结束吃草的时间 B，每头牛在 [A,B] 这一时间段内都会一直吃草。
当两头牛的吃草区间存在交集时（包括端点），这两头牛不能被安排在同一个畜栏吃草。
求需要的最小畜栏数目和每头牛对应的畜栏方案。*/
/*第 1 行：输入一个整数 N。
第 2..N+1 行：第 i+1 行输入第 i 头牛的开始吃草时间 A 以及结束吃草时间 B，数之间用空格隔开。*/
/*  5                   4
    1 10                1
    2 4                 2
    3 6                 3
    5 8                 2
    4 7                 4*/       

// 贪心 相当于906题 n个区间，分为若干组，组内部两两之间没有交集，输出最小组数 本题还要求输出方案，需要id数组   O(nlog₂n) 
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int,int> PII;

const int N = 500010;
int n;
int id[N];
pair<PII,int> cows[N];

int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d%d",&cows[i].first.first,&cows[i].first.second);   // 每头牛的开始吃草时间和结束吃草时间
        cows[i].second = i;               // 第i头牛
    }
    
    sort(cows,cows + n);        // 根据牛的开始吃草时间排序
    priority_queue<PII,vector<PII>,greater<PII>> heap;      // 小根堆 堆根据结束时间排序
    for(int i = 0;i < n;i++){
        if(heap.empty() || heap.top().first >= cows[i].first.first){    // 堆为空或堆顶的结束时间大于第i头牛的开始时间，区间相交
            PII stall = {cows[i].first.second,heap.size()};     // stall记录结束时间和分组编号
            id[cows[i].second] = stall.second;          // 第i个牛对应的分组
            heap.push(stall);
        }
        else{           // 与堆顶的区间不相交，合并组
            auto stall = heap.top();
            heap.pop();
            stall.first = cows[i].first.second;     // 更新合并后的结束时间
            id[cows[i].second] = stall.second;     
            heap.push(stall);       // 将更新后的分组，重新添加入堆
        }
    }
    
    printf("%d\n",heap.size());
    for(int i = 0;i < n;i++) printf("%d\n",id[i] + 1);  // 数组从0开始，id + 1
    return 0;
}