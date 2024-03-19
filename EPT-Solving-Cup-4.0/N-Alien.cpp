#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        long long mid = (n + 1) / 2;
        if ((long long) (k + mid - 1) >= (long long) (mid * (n - mid + 1))) // We can show by calculating the derivative of the villager power that it's maximum is for the villager at index mid
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}