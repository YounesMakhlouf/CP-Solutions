#include <bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
typedef vector<int> vi;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<int> x(n), y(n), goodness(n);
    map<double, int> radiuses;

    // Input
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];
    for (int i = 0; i < n; ++i)
        cin >> goodness[i];

    // Calculate goodness for each distance
    for (int i = 0; i < n; ++i) {
        double distance = (double) x[i] * x[i] + (double) y[i] * y[i];
        radiuses[distance] += goodness[i];
    }

    // Compute cumulative goodness
    vi results;
    for (auto &e: radiuses)
        results.push_back(e.second);
    for (int i = 1; i < n; ++i)
        results[i] += results[i - 1];

    // Output
    cout << max(0, *max_element(all(results)));
    return 0;
}