## C++ STL libraries

`#include <bits/stdc++.h>`

* vector 

```C++
vector <int> arr;

for (i = 0; i < n;i++) {
   arr.push_back(ele);  // .pop_back() for removing !
}

for (i = 0; i < arr.size();i++) {
   cout << arr[i];
}
```
` string s1 (str) ; // makes a copy of str to s1 `

* unordered_map

```C++
 unordered_map<string, int> umap; // decleration
 
 umap["He"] = 3; // intializing
 umap.insert(make_pair("He", 3)); // another way
 
 if (umap.find(key) == umap.end()) {
    cout << "Unable to find value for given key" << endl ;
} else {
    cout << "Found Key" << endl ;
} 

for (auto itr = umap.begin(); itr != umap.end(); itr++){
    cout << "Key : " << itr->first << "Value : " << itr->second << endl;
}
 
```
* unorderd_set

```C++
unordered_set<string> uset;
uset.insert("random_values");

if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n";
else
        cout << "Found " << key << endl;
        
for (auto itr = stringSet.begin(); itr != stringSet.end(); itr++)
        cout << (*itr) << endl;
}

```
