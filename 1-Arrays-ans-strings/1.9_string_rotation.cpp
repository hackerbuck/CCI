#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void str_rot (string s1 , string s2)
{
    string parent = s1 + s1;
    int idx = parent.find(s2);
    if (idx) {
            cout << "String Rotation";
    } else {
            cout << "Nope!";
    }
}

int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    str_rot (s1, s2);
    cout << endl;
    return 0;
}
