#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<pair<char, pair<int, int> > > tl;

    for (int i = 0; i < n; i++) {
        char c;
        int p, t;
        cin >> c >> p >> t;
        tl.push_back(make_pair(c, make_pair(p, t)));
    }

    int time = 0, pos = 0, i = 0, prev = 0;
    while (i != n) {
        pos += tl[i].second.first - prev;
        time += tl[i].second.first - prev;

        //update the light
        if ((time / tl[i].second.second) % 2 != 0) {
            if (tl[i].first == 'G') {
                tl[i].first = 'R';
            } else tl[i].first = 'G';
        }

        if (tl[i].first == 'R') {
            int remaining = tl[i].second.second - (time % tl[i].second.second);
            time = time + remaining;
        }
        prev = tl[i].second.first;
        i++;
    }

    time = time + (x - tl[i - 1].second.first);
    cout << time;
    return 0;
}