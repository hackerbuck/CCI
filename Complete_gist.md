* GCD of 2 numbers

```
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

* In-built function for GCD `__gcd (a,b)`

* LCM of 2 numbers : (a * b)/gcd (a,b)

* Array roataion  `[(N-1)- (d % N) + 1] + 1 ---> N and 0 -> [(N-1)- (d % N) + 1]`

* To compare string in c++ --> a == b , a < b (tells u about lexicographicaly order) [TODO : compare(), string slicing]

* TODO: read about radix sort

* **Sorting** in C++ : 

```
sort (arr, arr+n)
sort (vector.begin(), vector.end())
*(max_element(arr, arr+n))

bool modsort(const pair<int,int> &a, const pair<int,int> &b) {
    int x = a.first % k;
    int y = b.first % k;
    if (x == y) {
        return a.second < b.second;
    } else {
        return x < y;
    }
}

sort (vector.begin(), vector.end(), modsort);

int pos = s.find(":")
string sub = s.substr(pos,len);

itr  ======== itr->first , itr->second

pair ======== pair.first , pair.second

map.insert(make_pair(a,b))

#### multinap 

** Iter-over keys :

for (auto itri = multmap.begin(); itri != multmap.end();itri = multmap.upper_bound(itri->first)) {}

** Iter all values for the key

auto range_pair = order.equal_range(itri->first);

for (auto itrj = range_pair.first; itrj != range_pair.second; itrj++){}

```

```
Bubble Sort : 2 - nested loop , swap adjacent elements

Maximum freq diff + sorted height order in O(nlogn) [I was able to come up only with O(n2)]

1) sort height, freq pair in acending order
2) Maintain max freq diff between 2 heights 
3) Maintain min freq + repeat 1-3

```

* Longest Common Prefix 
   * Using word by word  `prefix = arr[0]  ; for(){ prefix = common(prefix,arr[i])}`  --- O(MN)
   * using Character by Character Matching  -- O(MN) but usefull when there are lot of strings
         ![LCS](https://www.geeksforgeeks.org/wp-content/uploads/longest_common_prefix5.jpg)
```
	 int findMinLength(string arr[], int n) 
{ 
    int min = arr[0].length(); 
  
    for (int i=1; i<n; i++) 
        if (arr[i].length() < min) 
            min = arr[i].length(); 
  
    return(min); 
} 
  
// A Function that returns the longest common prefix 
// from the array of strings 
string commonPrefix(string arr[], int n) 
{ 
    int minlen = findMinLength(arr, n); 
  
    string result; // Our resultant string 
    char current;  // The current character 
  
    for (int i=0; i<minlen; i++) 
    { 
        // Current character (must be same 
        // in all strings to be a part of 
        // result) 
        current = arr[0][i]; 
  
        for (int j=1 ; j<n; j++) 
            if (arr[j][i] != current) 
                return result; 
  
        // Append to result 
        result.push_back(current); 
    } 
  
    return (result); 
} 
```
* Reverse a string or array

![rev](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/arra34.jpg)

```
void rvereseArray(int arr[], int start, int end) 
{ 
    while (start < end) 
    { 
        int temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}  
```

* Array rotation O(1) space 

```
/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n) 
{ 
    rvereseArray(arr, 0, d-1); 
    rvereseArray(arr, d, n-1); 
    rvereseArray(arr, 0, n-1); 
} 
```

* Minimum number of swaps required to sort an array (Usinf pairs)

![min_swap](https://github.com/hackerbuck/CCI/blob/master/images/b-1.png)

`ans = Σi = 1k(cycle_size – 1)`

```cpp
int minSwaps(int arr[], int n)
{
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}
	// Sort the array by array element values to
	// get right position of every element as second
	// element of pair.
	sort(arrPos, arrPos + n);
        bool vis[n] = {false};
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = true;

			// move to next node as shown in picture!
			j = arrPos[j].second;
			cycle_size++;
		}
		ans += (cycle_size - 1);
	}

	// Return result
	return ans;
}

```

* Minimum swaps to make two arrays identical (Array permutation -- transformation)

```
arrA[] = {3, 6, 4, 8}
arrB[] = {4, 6, 8, 3}

iter -- > map[a[i]] = i
b[i] = map[b[i]]

b[] = {2, 1, 3, 0}

Then find minimum no of swap to sort the modified array , using  Σi = 1k(cycle_size – 1)` method
```

* Minimum number of swaps required to sort an array if only adjacent swap possible ==> **Inversion count**

* Inversion count using merge sort  O(log (n))

```
// Merge two sorted subarrays arr[low .. mid] and arr[mid + 1 .. high]
int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;
    int inversionCount = 0;
    
    // While there are elements in the left and right runs
    while (i <= mid && j <= high) 
    {
        if (arr[i] <= arr[j]) {
            aux[k++] = arr[i++];
        }
        else {
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);    // NOTE
        }
    }

    // Copy remaining elements
    while (i <= mid)
        aux[k++] = arr[i++];

    // Don't need to copy second half

    // copy back to the original array to reflect sorted order
    for (int i = low; i <= high; i++)
        arr[i] = aux[i];
        
    return inversionCount;
}

// Sort array arr [low..high] using auxillary array aux
int MergeSort(int arr[], int aux[], int low, int high)
{
    // Base case
    if (high == low)    // if run size == 1
        return 0;

    // find mid point
    int mid = (low + ((high - low) >> 1));
    int inversionCount = 0;
    
    // recursively split runs into two halves until run size == 1,
    // then merge them and return back up the call chain

    inversionCount += MergeSort(arr, aux, low, mid);      // split / merge left  half
    inversionCount += MergeSort(arr, aux, mid + 1, high); // split / merge right half
    inversionCount += Merge(arr, aux, low, mid, high);    // merge the two half runs

    return inversionCount;
}
```

* Inversion count using **set** STL O(n*n)

```
// Returns inversion count in arr[0..n-1]
int getInvCount(int arr[],int n)
{
    // Create an empty set and insert first element in it
    set<int> set1;
    set1.insert(arr[0]);
 
    int invcount = 0; // Initialize result
 
    set<int>::iterator itset1; // Iterator for the set
 
    // Traverse all elements starting from second
    for (int i=1; i<n; i++)
    {
        // Insert arr[i] in set (Note that set maintains
        // sorted order)
        set1.insert(arr[i]);
 
        // Set the iterator to first greater element than arr[i]
        // in set (Note that set stores arr[0],.., arr[i-1]
        itset1 = set1.upper_bound(arr[i]);
 
        // Get distance of first greater element from end
        // and this distance is count of greater elements
        // on left side of arr[i]
        invcount += distance(itset1, set1.end());
    }
 
    return invcount;
}
```

* Maximium sum of pairs with difference K

```
// Method to return maximum sum we can get by
// finding less than K difference pairs
int maxSumPairWithDifferenceLessThanK(int arr[], int N, int k)
{
	int maxSum = 0;

	// Sort elements to ensure every i and i-1 is closest
	// possible pair
	sort(arr, arr+N);

	// To get maximum possible sum, iterate from largest to
	// smallest, giving larger numbers priority over smaller
	// numbers.
	for (int i=N-1; i>0; --i)
	{
		// Case I: Diff of arr[i] and arr[i-1] is less then K,
		//		 add to maxSum
		// Case II: Diff between arr[i] and arr[i-1] is not less
		//		 then K, move to next i since with sorting we
		//		 know, arr[i]-arr[i-1] < arr[i]-arr[i-2] and
		//		 so on.
		if (arr[i]-arr[i-1] < k)
		{
			//Assuming only positive numbers.
			maxSum += arr[i];
			maxSum += arr[i-1];

			//When a match is found skip this pair
			--i; // xD see above we are going from top to bottom !
		}
	}

	return maxSum;
}
```


* Minimum Number of Platforms Required for a Railway (Maximum intersection of interval), using multimap

```
/*
Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
There are at-most three trains at a time 
(time between 11:00 to 11:20)

 Time     Event Type     Total Platforms Needed at this Time                               
 9:00       Arrival                  1
 9:10       Departure                0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                  3 
 11:20      Departure                2
 11:30      Departure                1
 12:00      Departure                0
 15:00      Arrival                  1
 18:00      Arrival                  2 
 19:00      Departure                1
 20:00      Departure                0
 
*/

#include <bits/stdc++.h>
using namespace std;
 
int findPlatform(int arr[], int dep[], int n)
{
    // Insert all the times (arr. and dep.)
    // in the multimap., achieving sorted array of arrival and dep
    multimap<int, char> order;
    for (int i = 0; i < n; i++) {
 
        // If its arrival then second value
        // of pair is 'a' else 'd'
        order.insert(make_pair(arr[i], 'a'));
        order.insert(make_pair(dep[i], 'd'));
    }
 
    int result = 0;
    int plat_needed = 0;
 
    multimap<int, char>::iterator it = order.begin();
 
    // Start iterating the multimap.
    for (; it != order.end(); it++) {
 
        // If its 'a' then add 1 to plat_needed
        // else minus 1 from plat_needed.
        if ((*it).second == 'a')
            plat_needed++;
        else
            plat_needed--;
 
        if (plat_needed>result)
            result = plat_needed;
    }
    return result;
}
 
```

* No of anagram pairs in substring (**Hashmap awesomness**)


```C++
int sherlockAndAnagrams(string s) {
    int i,j, res = 0;
    int n = s.length();
    unordered_map<string,int>  mapi;
    
    // Generate Substring
    
    for (i = 0; i < n ; i++) {
        for (j = 1;j <= n - i ; j++) {
            string sub = s.substr(i,j);
            if (j > 1) {
                sort (sub.begin(), sub.end());
            }
	    
	    // Sort the substring and store in map 
	    // so 'ab' and 'ba' have same key
            mapi[sub] += 1;
        }
    }
    for (auto itr = mapi.begin(); itr != mapi.end();itr++) {
        int n = itr->second;
        res += (n * (n - 1)) / 2;
    }
    return res;
}
```

## C++ STL libraries

`#include <bits/stdc++.h>`

### vector 

```C++
vector <int> arr;

for (i = 0; i < n;i++) {
   arr.push_back(ele);  // .pop_back() for removing !
}

for (i = 0; i < arr.size();i++) {
   cout << arr[i];
}
```
### Stacks

```C++
 stack<char> st;
 st.push(s[i]);
 if (st.empty()) {...}
 
 p=st.top();
 st.pop();
 ```

*  Balanced paranthesis
 
 ```C++
bool balance(string s)
{
	char p = '';
	stack<char> st;
	for(int i=0;i<s.size();i++)
	{  
		if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
			st.push(s[i]);
		} else if(st.empty()) {
			return 0;
		} else if(s[i]==')' ||s[i]=='}' || s[i]==']') {
			p=st.top();
			st.pop();
		}
		if(s[i]==')' && p!='(') {
			return 0;
		} else if(s[i]=='}' && p!='{') {
			return 0;
		} else if(s[i]==']' && p!='[')
			return 0;
		}
	}
}
 ```
 
 * Infix to postfix/prefix
 
 ```
void infix2pfix() {
	stack<char> st;
	for (i = 0 ; i < str.size(); i++) {
		if (!operator (str[i])) {
			cout << s[i];
		} else if (s[i] == '(') {
			st.push(s[i]) // push '(' into stack
		}
		else if (s[i] == ')') {
			while (!s.empty() && st.top() != '(') {
				st.pop()
			}
			if (st.top == '(') { 
				st.pop()
			}			
		} else { // an operator is encountered
			while (!s.empty() && Prec(str[i]) <= Prec(st.top())) { // pop all higher prcendece operator from stack 
				cout << st.top()
				st.pop()
			}				
			push(stack, exp[i]);
		}
	}
	while (!st.empty()) { // Take care of remaining elements left in stack
		cout << st.top();
		st.pop()
	}
}
 ```



### unordered_map

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

* Checking note and magazine 

1) freq count of note
2) subtrace freq from map for each word in magazine (**Until value becomes 0**)
3) iterate map and check all freq count is 0

### unorderd_set (Self-Balancing Binary Search Tree)

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
### prioroty queue (min or max heap)

```
empty() – Returns whether the queue is empty
size() – Returns the size of the queue
top() – Returns a reference to the top most element of the queue
push(g) – Adds the element ‘g’ at the end of the queue
pop() – Deletes the first element of the queue
```


### Hashmap + sort + Pair

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
    return p1.second > p2.second; // (a > b gives decending order , a < b assending order)
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
* For above sum , instead of sorting entire hashmap , we can consrtuct **priority queue (max-heap)** and pop k elements 

```
// C++ implementation to find k numbers with most
// occurrences in the given array
#include <bits/stdc++.h>

using namespace std;

// comparison function defined for the priority queue
struct compare
{
	bool operator()(pair<int, int> p1, pair<int, int> p2)
	{
		// if frequencies of two elements are same
		// then the larger number should come first
		if (p1.second == p2.second)
			return p1.first < p2.first;
			
		// insert elements in the priority queue on the basis of
		// decreasing order of frequencies 
		return p1.second < p2.second; 
	}
};

// funnction to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int n, int k)
{
	// unordered_map 'um' implemented as frequency hash table
	unordered_map<int, int> um;
	for (int i = 0; i<n; i++)
		um[arr[i]]++;
	
    // priority_queue<type,container,compare>
    
	priority_queue<pair<int, int>, vector<pair<int, int> >, 
						compare> pq(um.begin(), um.end());
	
	// display the the top k numbers
	cout << k << " numbers with most occurrences are:\n";
	for (int i = 1; i<= k; i++)
	{
		cout << pq.top().first << " ";
		pq.pop();
	}		 
}

```
