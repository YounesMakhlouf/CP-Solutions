#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    ifstream is ("day3.txt");
    if (is.fail()) {
        cout << "error";
        exit (1);
    }
    string s;
    int sum = 0;
    vector<string> v;
    while (getline(is,s))
        v.push_back(s);
    for (auto it = v.begin(); it != v.end(); it += 3) {
        int pos = 0;
        while (1) {
            if (((int)((*(it+1)).find((*it)[pos])) != -1) && (((int)((*(it+2)).find((*it)[pos])) != -1)))
                break;
            pos ++;
        }
        if ((*it)[pos] >= 'a')
            sum += (*it)[pos] - 'a' + 1;
        else
            sum += (*it)[pos] - 'A' + 27;
    }


    cout << sum << endl;
    is.close();
    return 0;
}
