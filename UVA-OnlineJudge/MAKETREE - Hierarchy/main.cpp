#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
typedef vector<int> vi;

vector<vi> adj;
vi visited;
vi res;
vi parent;

void topological_sort(int i)
{
    if (visited[i])
        return;
    visited[i] = true;
    for (auto child : adj[i]) {
        topological_sort(child);
    }
    res.push_back(i+1);
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    visited.resize(n);
    parent.resize(n, -1);

    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            b--;
            adj[i].push_back(b);
        }
    }
    for (int i = 0; i < n; i++)
        topological_sort(i);
    reverse(all(res));

    int position = 0;
    for (int i = n-1; i >= 0; i--) {
        int student = res[i];
        parent[student] = position;
        position = student;
    }
    for (int i = 1; i <= n; i++)
        cout << parent[i] << "\n";
    return 0;
}
