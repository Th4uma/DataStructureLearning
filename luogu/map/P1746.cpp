#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, a[1001][1001], x1, y1, x2, y2, cnt[1000010];
char s[1001];

queue<pair<int, int>> q;

int bx[4] = {-1, 1, 0, 0};
int by[4] = {0, 0, -1, 1};

void bfs(int mb)
{
    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = u + bx[i];
            int ny = v + by[i];
            if (nx == x2 && ny == y2)
            {
                cnt[nx * n + ny] = cnt[u * n + v] + 1;
                return;
            }
            if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
            if (a[nx][ny] == 1)
                continue;
            if (cnt[nx * n + ny] == 0)
            {
                cnt[nx * n + ny] = cnt[u * n + v] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    q.push(make_pair(x1, y1));
    cnt[x1 * n + y1] = 1;
    bfs(1);

    printf("%d\n", cnt[x2 * n + y2]-1 );
    return 0;
}