#include <bits/stdc++.h>
using namespace std;

void print_freq (string str)
{
    unordered_map<string,int> umap;
    stringstream ss(str); // str.split()
    string word;
    while (ss >> word) {
            umap[word]++;
    }
    unordered_map<string,int> :: iterator itr;
    for (itr = umap.begin(); itr != umap.end() ; itr++) {
            cout << "Freq : " << itr->first << " : " << itr->second << endl;
    }
}

int main()
{
    string s;
    getline (cin, s);
    print_freq (s);
    return 0;
}
