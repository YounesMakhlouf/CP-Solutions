#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    unsigned int t;
    while (cin >> t && t != 0) {
        unsigned int s = (int) sqrt(t);
        cout << (s * s == t ? "yes\n" : "no\n");
    }
    return 0;
}
