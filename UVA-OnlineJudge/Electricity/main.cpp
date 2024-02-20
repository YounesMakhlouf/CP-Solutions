#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year)
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int numberOfDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int t;
    while (cin >> t && t) {
        int num = 0, res = 0;
        long long days[t];
        long long consumptions[t];
        for (int i = 0; i < t; i++) {
            int m, y, c, d;
            cin >> d >> m >> y >> c;
            numberOfDays[1] = isLeapYear(y) ? 29 : 28;
            days[i] = d + accumulate(numberOfDays, numberOfDays + m - 1, 0) + (y - 1900) * 365;
            for (int j = 1900; j < y; j++)
                if (isLeapYear(j))
                    days[i]++;
            consumptions[i] = c;
        }
        for (int i = 0; i < t-1; i++) {
            if (days[i] == days[i+1] - 1) {
                num++;
                res += consumptions[i+1] - consumptions [i];
            }
        }
        cout << num << " " << res << "\n";
    }
    return 0;
}
