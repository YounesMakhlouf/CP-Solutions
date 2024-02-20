#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)((v).size()))

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore();
    set<string> st;
    while (t--) {
        string s;
        getline(cin, s);
        if (s[0] == 'a') {
            cout << sz(st) << "\n";
        } else if (s[0] == 'r') {
            st.erase(s.substr(3));
        } else if (s[0] == 't') {
            st.insert(s.substr(6));
        }
    }
    return 0;
}