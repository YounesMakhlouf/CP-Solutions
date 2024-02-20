#include <bits/stdc++.h>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define l 100000
typedef vector<int> vi;

int main ()
{
    ifstream inputStream("day1.txt");

    if (inputStream.fail()) {
        cout << "error";
        exit(1);
    }
    vi calories(l);
    int pos = 0, sum = 0;
    string s;
    while (getline(inputStream, s)) {
        if (s.empty())
            pos ++;
        else
            calories[pos] += stoi(s);
    }
    for (int i = 0; i < 3; i++) {
        sum += *max_element(all(calories));
        calories.erase(max_element(all(calories)));
    }
    cout << sum;
    inputStream.close();
    return 0;
}
