#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n,t,h,m=1;
double ans=0;
struct coin
{
    int m, v;
    double p;
};

coin c[1001];
int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &c[i].m, &c[i].v);
        c[i].p = (double)c[i].v / c[i].m;
    }
    sort(c + 1, c + n + 1, [](coin a, coin b) { return a.p > b.p; });
    while(m<=n&&h+c[m].m<=t){
        h+=c[m].m;
        ans+=c[m].v;
        m++;
    }
    if(h<t){
        ans+=c[m].p*(t-h);
    }
    printf("%.2f\n", ans); 
    return 0;
}
