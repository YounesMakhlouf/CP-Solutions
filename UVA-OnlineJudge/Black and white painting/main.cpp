#include <iostream>
using namespace std;

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int n, m, c;
    while (cin >> n >> m >> c && n) {
        int rem = (c == 1);
        cout << ((n - 7) * (m - 7) + rem) / 2 << "\n";
    }
    return 0;
}
