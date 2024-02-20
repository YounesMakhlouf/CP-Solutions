#include <bits/stdc++.h>
using namespace std;

bool mat[25][25];
bool visited[25][25] = {false};

bool valid (int a, int n)
{
    return ((a >= 0) && (a < n));
}

void markEagles(int r, int c, int n)
{
    if ((!valid(r, n)) || (!valid(c, n)) || (!mat[r][c]) || (visited[r][c])) {
        return;
    }
    visited[r][c] = true;
    for (int i = r-1; i <= r+1; i++) {
        for (int j = c-1; j <= c+1; j++) {
            markEagles(i, j, n);
        }
    }
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    string s;
    int image = 0;
    while (getline(cin, s) && s.length()) {
        image++;
        int n, cnt = 0;
        n = stoi(s);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = false;
                visited[i][j] = false;
            }
        }
        for (int r = 0; r < n; r++) {
            (getline(cin, s));
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    mat[r][i] = true;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mat[i][j] == 1) && (!(visited[i][j]))) {
                    cnt++;
                    markEagles(i, j, n);
                }
            }
        }
        cout << "Image number " << image << " contains " << cnt << " war eagles.\n";
    }
    return 0;
}
