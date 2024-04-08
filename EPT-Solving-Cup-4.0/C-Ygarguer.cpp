#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (n == 1) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        long long total = (n + k - 1) * (n + k - 2);
        long long res = total - (n - 1) * (n - 2);
        long long g = gcd(total, res);
        cout << res / g << " " << total / g << endl;
    }
    return 0;
}