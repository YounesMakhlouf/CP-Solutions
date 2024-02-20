#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

bool mat[25][25];
bool visited[25][25] = {false};

bool valid (int a, int n)
{
    return ((a >= 0) && (a < n));
}

void markEagles(int r, int c, int n)
{
    if ((!valid(r, n)) || (!valid(c, n)) || (mat[r][c] == 0) || (visited[r][c])) {
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
    ifstream is ("eagles.txt");
    ofstream os;
    os.open ("result.txt");
    if (is.fail()) {
        cout << "input error";
        exit(1);
    }
    if (os.fail()) {
        cout << "output error";
        exit(1);
    }
    string s;
    int image = 0;
    while (getline(is, s)) {
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
            (getline(is, s));
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
        os << "Image number " << image << " contains " << cnt << " war eagles \n";
    }
    is.close();
    os.close();
    return 0;
}
