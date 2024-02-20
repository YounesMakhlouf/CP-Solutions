#include <bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))

vector<long long> ladies;

int lower(long long x) {
    int start = 0, end = sz(ladies) - 1;
    while (start < end) {
        int mid = start + (end - start + 1) / 2;
        if (ladies[mid] < x) start = mid;
        else if (ladies[mid] >= x) end = mid - 1;
    }
    return start;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
       int a;
       cin >> a;
       ladies.push_back(a);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        long long height;
        cin >> height;

        if (height > ladies[0])
            cout << ladies[lower(height)] << " ";
        else
            cout << "X ";
        auto it = upper_bound(all(ladies), height);
        if (it != ladies.end()) {
            cout << *it << "\n";
        } else
            cout << "X\n";
    }
    return 0;
}