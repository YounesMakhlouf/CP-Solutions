#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, c;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        vector<double> v;
        double s = 0;
        for (int i = 0; i < n; i++) {
            double el;
            cin >> el;
            s += el;
            v.push_back(el);
        }
        sort(v.rbegin(), v.rend());
        int i = 0;
        double beauty = 0;
        while (c > 0 && i < n) {
            if (c >= 100) {
                beauty += 100 * v[i];
                c -= 100;
            } else {
                beauty += v[i] * c;
                c = 0;
            }
            i++;
        }
        double res = beauty / s;
        cout << fixed << setprecision(10) << res << endl;
    }
    return 0;
}