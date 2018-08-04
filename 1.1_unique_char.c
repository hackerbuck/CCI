/* O(n) complexity */

#include <iostream>
using namespace std;

bool is_unique(string s) {
    int i;
    int len = s.length();
    bool chset[256] = {0};
    if (len > 256) {
        return false;
    }
    for (i = 0;i < len; i++) {
        if (chset[int(s[i])] == true) {
            return false;
        }
        chset[int(s[i])] = true;
    }
    return true;
}



int main() {
    string str ;
    cin >> str;
    if (is_unique(str)) {
            cout << "Unique string";
    } else {
            cout << "nope!";
    }
}

/* for a-z (of count 26) we can 

bool uniqueCharacters(string str) {
     
    // Assuming string can have characters 
    // a-z, this has 32 bits set to 0
    int checker = 0;
     
    for (int i = 0; i < str.length(); i++) {
         
        int bitAtIndex = str[i] - 'a';
         
        // if that bit is already set in
        // checker, return false
        if ((checker & (1 << bitAtIndex)) > 0) {
            return false;
        }
         
       // otherwise update and continue by
       // setting that bit in the checker
       checker = checker | (1<<bitAtIndex);
    }
     
    // no duplicates encountered, return true
    return true;
}

*/
