#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,a,b,lon[1000010],cnt[1000010];
vector<int> adj[1000010];
queue<int> q;

void map(int u,int v){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void bfs(int mb){
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(lon[v]==-1){
                lon[v]=lon[u]+1;
                cnt[v]=cnt[u];
                q.push(v);
            }
            else if(lon[v]==lon[u]+1){
                cnt[v]=(cnt[u]+cnt[v])%100003;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        map(a,b);
    }
    for(int i=1;i<=n;i++){
        lon[i]=-1;    }
    q.push(1);
    lon[1]=0;
    cnt[1]=1;
    bfs(1);
    for(int i=1;i<=n;i++){
        printf("%d\n",cnt[i]);
    }
    printf("\n");
    return 0;
}