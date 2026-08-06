#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n,t,h,m;
int ans=0;
struct comp
{
    int start, end;
};

comp c[1000001];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d", &c[i].start, &c[i].end);
    }
    sort(c + 1, c + n + 1, [](comp a, comp b) { return a.end < b.end; });
    for(int i = 1; i <= n; i++){
        if(c[i].start >= h){
            h = c[i].end;
            ans++;
        }
    }
    
    printf("%d\n", ans); 
    return 0;
}
