#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int sum = 0;
    while (t--) {
        int a;
        cin >> a;
        sum += a;
    }
    if (sum == 14) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
