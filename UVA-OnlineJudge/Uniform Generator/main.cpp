#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

int gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    if (a == 0) {
        return b;
    }
    return a;
}

int main ()
{
    int t;
    while (cin >> t) {
        int n;
        cin >> n;
        printf("%10d%10d    ", t, n);
        if (gcd(n, t) == 1)
            cout << "Good Choice\n";
        else
            cout << "Bad Choice\n";
        cout << "\n";
    }
    return 0;
}
