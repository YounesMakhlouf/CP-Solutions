#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)((v).size()))

string maximize(string s) {
    if (s.empty() || s.size() == 1)
        return s;
    int n = sz(s);
    char prev = s[0];
    string new_string = s.substr(0, 1);
    for (int i = 1; i < n; i++) {
        if (s[i] == prev && s[i] == '0') {
            new_string[new_string.size() - 1] = '1';
            prev = '1';
        } else {
            new_string += s[i];
            prev = s[i];
        }
    }
    return new_string;
}

string maximize_back(string s) {
    int n = sz(s);
    char prev = s[n - 1];
    string new_string;
    for (int i = n - 2; i > 0; i--) {
        if (s[i] == prev) {
            if (s[i] == '1' && s[i - 1] == '0') {
                s[i] = '2';
                s[i + 1] = '2';
                s[i - 1] = '1';
                prev = '1';
            }
        } else {
            prev = s[i];
        }
    }
    for (char c: s) {
        if (c != '2')
            new_string += c;
    }
    return new_string;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = maximize(s);
        s = maximize_back(s);
        cout << s << endl;
    }
    return 0;
}