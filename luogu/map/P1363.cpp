#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m, a[1501][1501];
char x;
int ans = 0;
queue<pair<int, int>> q;
int visited[1501][1501], px[1501][1501], py[1501][1501];

void bfs()
{
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = u + dx[i];
            int ny = v + dy[i];
            int xx = ((nx - 1) % n + n) % n + 1;
            int yy = ((ny - 1) % m + m) % m + 1;
            if (a[xx][yy] == 1)
            {
                if (visited[xx][yy] == 0)
                {
                    visited[xx][yy] = 1;
                    q.push(make_pair(nx, ny));
                    px[xx][yy] = nx;
                    py[xx][yy] = ny;
                }
                else if (visited[xx][yy] == 1)
                {
                    if (px[xx][yy] != nx || py[xx][yy] != ny)
                    {
                        ans = 1;
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) == 2)
    {
        ans = 0;

        while (!q.empty())
            q.pop();

        memset(visited, 0, sizeof(visited));
        memset(px, 0, sizeof(px));
        memset(py, 0, sizeof(py));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf(" %c", &x);
                if (x == '#')
                    a[i][j] = 0;
                else if (x == 'S')
                {
                    a[i][j] = 1;
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    px[i][j] = i;
                    py[i][j] = j;
                }
                else if (x == '.')
                    a[i][j] = 1;
            }
        }
        bfs();
        if (ans == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
