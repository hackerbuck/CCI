#include <bits/stdc++.h>
using namespace std;

bool palind_permu (string s)
{
    int n = s.length();
    int i;
    bool flag = false;
    unordered_map<char, int> umap;
    for (i = 0; i < n; i++) {
            if (s[i] != ' ') {
                umap[tolower(s[i])]++;
            }
    }
    for (auto itr = umap.begin(); itr != umap.end(); itr++) {
            cout << itr->first << ", " << itr->second << endl;
            if ((itr->second % 2) != 0) {
                    if (flag) {
                            return false;
                    } else {
                            flag = true;
                    }
            }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    if (palind_permu (s)) {
            cout << "YES";
    } else {
            cout << "NO";
    }
    cout << endl;
