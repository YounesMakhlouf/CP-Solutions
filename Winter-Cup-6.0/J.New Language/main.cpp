#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            res += (long long)(1) << a; // Shifting 1 left by 'a' bits is equivalent to pow(2, a)
        }
        cout << res << '\n';
    }
    return 0;
}