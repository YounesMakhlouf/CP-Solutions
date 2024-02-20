#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    ifstream is ("day2.txt");
    if (is.fail()) {
        cout << ("error");
        exit(1);
    }
    int score = 0;
    char a,b;
    while (is >> a >> b) {
        switch (b) {
        case 'X':
            if (a == 'A')
                score += 3;
            else if (a == 'B')
                score++;
            else
                score += 2;
            break;
        case 'Y':
            if (a == 'A')
                score += 4;
            else if (a == 'B')
                score += 5;
            else
                score += 6;
            break;
        case 'Z':
            if (a == 'A')
                score += 8;
            else if (a == 'B')
                score += 9;
            else
                score += 7;
            break;
        }
    }
    cout << score;
    is.close();
    return 0;
}
