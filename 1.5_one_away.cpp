#include <math.h>
using namespace std;

bool palind_permu (string s1, string s2)
{
    int sub = s1.length() - s2.length();
    int dif = abs (sub);
    if (dif > 1) {
            return false;
    }
    int i;
    bool flag = false;
    unordered_map<char, int> umap;
    for (i = 0; i < s1.length(); i++) {
            umap[s1[i]]++;
    }
    for (i = 0; i < s2.length(); i++) {
            umap[s2[i]]--;
    }
    for (auto itr = umap.begin(); itr != umap.end(); itr++) {
            cout << itr->first << ", " << itr->second << endl;
            if (itr->second) {
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
    string s1, s2;
    cin >> s1;
    if (palind_permu (s1, s2)) {
            cout << "YES";
    } else {
            cout << "NO";
    }
    cout << endl;
    return 0;
}
