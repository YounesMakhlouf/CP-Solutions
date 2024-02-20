#include <bits/stdc++.h>
using namespace std;

char mat[100][100] = {0};
bool visited[100][100] = {false};

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

bool valid (int a, int n)
{
    return ((a >= 0) && (a < n));
}

void count_component(int r, int c, int n)
{
    if ((!valid(r, n)) || (!valid(c, n)) || (visited[r][c]) || (mat[r][c] == '.'))
        return;
    visited[r][c] = true;
    int dc, dr;
    for (int k = 0; k < 4; k++)
    {
        dr = r + dx[k];
        dc = c + dy[k];
        count_component(dr, dc, n);
    }
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((mat[i][j] == 'x') && (!visited[i][j]))
                {
                    cnt++;
                    count_component(i, j, n);
                }
        cout << "Case " << k << ": " << cnt << "\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = 0;
                visited[i][j] = false;
            }
    }
    return 0;
}
