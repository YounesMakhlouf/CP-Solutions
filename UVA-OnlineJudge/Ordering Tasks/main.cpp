#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

vector<vi> adj;
vector<bool> visited;
stack<int> res;

void dfs(int i)
{
    if (visited[i])
        return;
    visited[i] = true;
    for (auto num : adj[i]) {
        dfs(num);
    }
    res.push(i+1);
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        visited.assign(n, false);
        adj.assign(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--,
            adj[a].push_back(b);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i);
        }
        while (!res.empty()) {
            cout << res.top();
            res.pop();
            if (!res.empty())
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
