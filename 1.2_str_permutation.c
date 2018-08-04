/* O(n) complexity */


#include <iostream>
using namespace std;

bool is_permu(string s, string b) {
    int i, j;
    int len = s.length();
    int blen = b.length();
    if (len != blen) {
            return false;
    }
    int chset[256] = {0};
    for (i = 0;i < len; i++) {
        chset[int(s[i])] += 1;
        chset[int(b[i])] -= 1;
    }
    for (i = 0; i < 256; i++) {
            if (chset[i]) {
                    return false;
            }
    }
    return true;
}



int main() {
    string small, big;
    cin >> small;
    cin >> big;
    if (is_permu(small, big)) {
            cout << "Contains permutation of given string" << endl;
    } else {
            cout << "nope!" << endl;
    }
}
