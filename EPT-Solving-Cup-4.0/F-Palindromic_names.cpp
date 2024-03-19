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
        map<char, int> occ;
        int res = 0;
        for (int i = 0; i < n; i++) {
            char letter;
            cin >> letter;
            occ[letter]++;
        }
        for (const auto &e: occ) {
            if (e.second % 2)
                res++;
        }
        cout << res / 2 << endl;
    }
    return 0;
}