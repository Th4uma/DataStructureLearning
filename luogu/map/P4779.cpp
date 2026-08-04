#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, u, v, w, s, lon[1000010], vis[1000010];

struct edge
{
    int to;
    int w;
};

vector<edge> adj[1000010];

priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>>
    q;

void map(int u, int v, int w)
{
    adj[u].push_back({v, w});
}

void bfs()
{
    while (!q.empty())
    {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();

        if (vis[u] == 0)
            vis[u] = 1;
        else
            continue;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].to;
            int w = adj[u][i].w;
            if (d + w < lon[v] || lon[v] == -1)
            {
                lon[v] = d + w;
                q.push({lon[v], v});
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        map(u, v, w);
    }
    for (int i = 1; i <= n; i++)
    {
        lon[i] = -1;
    }
    q.push({0, s});
    lon[s] = 0;

    bfs();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", lon[i]);
    }
    printf("\n");
    return 0;
}

