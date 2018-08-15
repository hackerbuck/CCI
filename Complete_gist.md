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

* **Sorting** in C++ : 

```
sort (arr, arr+n)
sort (vector.bigin(), vector.end())
```

* Minimum number of swaps required to sort an array

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

* Array rotation by d elements (using reversal algorithm, nahh not necessary!) 

```
  rvereseArray(arr, 0, d-1);
  rvereseArray(arr, d, n-1);
  rvereseArray(arr, 0, n-1);
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
