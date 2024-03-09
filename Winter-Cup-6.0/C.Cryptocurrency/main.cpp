#include <bits/stdc++.h>

using namespace std;

int highest_contiguous_increase(const int *sequence, int n) {
    int max_increase = 0;
    int start_index = 0;
    int current_increase = 0;

    for (int i = 1; i < n; ++i) {
        if (sequence[i] > sequence[i - 1]) {
            current_increase = sequence[i] - sequence[start_index];
        } else {
            max_increase = max(max_increase, current_increase);
            start_index = i;
            current_increase = 0;
        }
    }
    max_increase = max(max_increase, current_increase); // Check for the last increasing subsequence

    return max_increase;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << highest_contiguous_increase(v, n) << '\n';
    }
    return 0;
}