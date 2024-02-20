#include<bits/stdc++.h>

using namespace std;

int main()
{
    int res = 0, pos = 0;
    ifstream inputStream ("2015_1.txt");
    if (inputStream.fail()) {
        cout << "error";
        exit(1);
    }
    char ch;
    while (inputStream >> ch && res != -1) {
        pos ++;
        if (ch == '(')
            res += 1;
        else if (ch == ')')
            res -= 1;
    }
    if (res == -1)
        cout << pos <<endl;
    inputStream.close();
    cout << res;
    return 0;
}
