#include <bits/stdc++.h>
using namespace std;

char mat [8][8] = {0};
bool visited [8][8] = {false};

int dx[] = {0, 1, -1};
int dy[] = {-1, 0, 0};
string dir[] = {"forth", "right", "left"};
string word= "IEHOVA#";


bool valid(int a, int n)
{
    return ((a >= 0) && (a < n));
}

void dfs (int r, int c, int n, int m, int letter)
{
    if ((visited[r][c]) || (!valid(r, n)) || (!valid(c, m)) || (mat[r][c] == '#'))
        return;
    visited[r][c] = 1;
    for (int k = 0; k < 3; k++)
    {
        int nc =c + dx[k];
        int nr =r + dy[k];
        if ((mat[nr][nc] == word[letter]) && (!visited[nr][nc]))
        {
            cout << dir[k];
            if (letter + 1 != word.size())
            {
                cout << " ";
            }
            dfs(nr, nc, n, m, letter+1);
        }
    }
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, pos_init;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '@')
                    pos_init = j;
            }
        }
        dfs(n-1, pos_init, n, m, 0);
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
    return 0;
}
