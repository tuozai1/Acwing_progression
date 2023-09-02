/*假设海岸是一条无限长的直线，陆地位于海岸的一侧，海洋位于另外一侧。每个小岛都位于海洋一侧的某个点上。
雷达装置均位于海岸线上，且雷达的监测范围为 d，当小岛与某雷达的距离不超过 d 时，该小岛可以被雷达覆盖。
我们使用笛卡尔坐标系，定义海岸线为 x 轴，海的一侧在 x 轴上方，陆地一侧在 x 轴下方。
现在给出每个小岛的具体坐标以及雷达的检测范围，请你求出能够使所有小岛都被雷达覆盖所需的最小雷达数目。*/
/*  3 2 个数和半径
    1 2                     2
    -3 1
    2 1*/

// 贪心 对于任意一个小岛 (x,y)，我们都可以在海岸线上求出能覆盖该小岛的建造雷达的区间 [a,b]（以小岛为圆心，d为半径作圆）
// 将所有小岛转化成区间后，问题转化为：给定 n 个区间，在 x 轴上选择尽量少的点，使得所有区间至少包含一个点
/*  1.将所有区间按右端点从小到大排序；
    2.依次考虑每个区间：
        如果当前区间包含最后一个选择的点，则直接跳过；
        如果当前区间不包含最后一个选择的点，则在当前区间的右端点的位置选一个新的点；*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double,double> PDD;

const int N = 1010;
const double INF = 1e4;
int n,d;
PDD seg[N];

int main(){
    scanf("%d%d",&n,&d);
    bool success = true;
    for(int i = 0;i < n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(y > d){          // 如果y > d，则无法在x轴上找到区间
            success = false;
            break;
        }
        
        auto len = sqrt(d * d - y * y);     // 算出在x轴上的垂直平分弦
        seg[i] = {x + len,x - len};         // 右端点和左端点
    }
    
    if(!success) puts("-1");
    else{
        sort(seg,seg + n);      // 根据右端点排序
        int res = 0;
        double last = -INF;
        for(int i = 0;i < n;i++){
            if(seg[i].second > last){   // 如果当前区间不包含最后一个选择的点，则在当前区间的右端点的位置选一个新的点
                res++;
                last = seg[i].first;    // 更新右端点
            }
        }
        printf("%d",res);
    }
    return 0;
}