#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
typedef vector<int> vi;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a*b)/gcd(a, b);
}

int main ()
{
    cin.tie(0);
    ios :: sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        vector <long long> nums;
        long long n, m, a, d, res = 0;
        cin >> n >> m >> a >> d;
        for (long long i = 0; i < 5; i++) {
            nums.push_back(a + i * d);
        }
        for (long long id1 = 0; id1 < 2; id1 ++)
            for (long long id2 = 0; id2 < 2; id2 ++)
                for (long long id3 = 0; id3 < 2; id3++)
                    for (long long id4 = 0; id4 < 2; id4 ++)
                        for (long long id5 = 0; id5 < 2; id5 ++) {
                            long long r = 1, nbElements = 0;
                            if (id1) {
                                r = lcm(r, nums[0]);
                                nbElements++;
                            }
                            if (id2) {
                                r = lcm(r, nums[1]);
                                nbElements++;
                            }
                            if (id3) {
                                r = lcm(r, nums[2]);
                                nbElements++;
                            }
                            if (id4) {
                                r = lcm(r, nums[3]);
                                nbElements++;
                            }
                            if (id5) {
                                r = lcm(r, nums[4]);
                                nbElements++;
                            }
                            if (nbElements == 0)
                                continue;
                            long long sign = (nbElements & 1) ? 1 : -1;
                            if (!(n % r))
                                res += sign * (((m / r) - (n / r)) + 1);
                            else
                                res += sign * ((m / r) - (n / r));
                        }
        cout << m - n + 1 - res << "\n" ;
    }
    return 0;
}
