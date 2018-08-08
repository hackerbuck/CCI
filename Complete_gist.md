* GCD of 2 numbers

```
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

* LCM of 2 numbers : (a * b)/gcd (a,b)

* Array rotation by d elements (useing reversal algorithm) 

```
  rvereseArray(arr, 0, d-1);
  rvereseArray(arr, d, n-1);
  rvereseArray(arr, 0, n-1);
```

* Sort an array in C++ : `sort (arr, arr+n)`


* Hashmap + sort + Pair

```
// C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>
 
using namespace std;
 
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    // if frequencies of two elements are same
    // then the larger number should come first
    if (p1.second == p2.second)
        return p1.first > p2.first;
         
    // sort on the basis of decreasing order
    // of frequencies    
    return p1.second > p2.second; // (a > b then gives decending order , a < b assending order)
}

void print_N_mostFrequentNumber(int arr[], int n, int k)
{
    // unordered_map 'um' implemented as frequency hash table
    unordered_map<int, int> um;
    for (int i = 0; i<n; i++)
        um[arr[i]]++;
         
    // store the elements of 'map' in the vector 'freq_arr'    
    vector<pair<int, int> > freq_arr(um.begin(), um.end());
     
    // sort the vector 'freq_arr' on the basis of the
    // 'compare' function
    sort(freq_arr.begin(), freq_arr.end(), compare);
     
    // display the the top k numbers
    for (int i = 0; i<k; i++)
        cout << freq_arr[i].first << " ";
}
```