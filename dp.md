## Dynamic Programming

Main goal : dont compute from first 

1) fibanoci 

* Memoniztion method (Top down)

```
if (mapi.find(n) == mapi.end()) {
     if (n <= 1) {
          return n;
     }
     mapi[n] = fib(n-1) + fib(n-2);
}
return mapi.find(n);
```

* Tabulation method (Bottom up)

```
vectior<int> arr;
arr[0] = 0;
arr[1] = 1;
for (int i = 2; i < n; i++) {
    arr[i] = arr[i-1] + arr[i-2]
}
return arr[n];
```


1) Longest Increasing Subsequence

![LIS](https://github.com/sivaramaaa/CCI/blob/master/images/Screenshot%20from%202018-11-11%2022-08-30.png)


* Intialize 1D array with all values as 1

```
int lis( int arr[], int n )  
{  
    int lis[n]; 
   
    lis[0] = 1;    
  
    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )  
    { 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ )   
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)  # max than current lis[i]
                lis[i] = lis[j] + 1;  
    } 
  
    // Return maximum value in lis[] 
    return *max_element(lis, lis+n); 
}  
```
2) Longeset common subsequence :

![LCS](https://github.com/sivaramaaa/CCI/blob/master/images/Screenshot%20from%202018-11-11%2023-43-12.png)

* intialize arr[m+1][n+1]  && sigma x0 , 0y = 0 
* IF 2 char's match include is therfore +1
* Else max (only-including-a,only-including-b)

```
{ 
   int L[m+1][n+1]; 
   int i, j; 
   
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n]; 
} 
```


* Longeste path in matrix 

```
#include<bits/stdc++.h> 
#define n 3 
using namespace std; 
  
// Returns length of the longest path beginning with mat[i][j]. 
// This function mainly uses lookup table dp[n][n] 
int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n]) 
{ 
    // Base case 
    if (i<0 || i>=n || j<0 || j>=n) 
        return 0; 
  
    // If this subproblem is already solved 
    if (dp[i][j] != -1) 
        return dp[i][j]; 
  
    // Since all numbers are unique and in range from 1 to n*n, 
    // there is atmost one possible direction from any cell 
    if (j<n-1 && ((mat[i][j] +1) == mat[i][j+1])) 
       return dp[i][j] = 1 + findLongestFromACell(i,j+1,mat,dp); 
  
    if (j>0 && (mat[i][j] +1 == mat[i][j-1])) 
       return dp[i][j] = 1 + findLongestFromACell(i,j-1,mat,dp); 
  
    if (i>0 && (mat[i][j] +1 == mat[i-1][j])) 
       return dp[i][j] = 1 + findLongestFromACell(i-1,j,mat,dp); 
  
    if (i<n-1 && (mat[i][j] +1 == mat[i+1][j])) 
       return dp[i][j] = 1 + findLongestFromACell(i+1,j,mat,dp); 
  
    // If none of the adjacent fours is one greater 
    return dp[i][j] = 1; 
} 
  
// Returns length of the longest path beginning with any cell 
int finLongestOverAll(int mat[n][n]) 
{ 
    int result = 1;  // Initialize result 
  
    // Create a lookup table and fill all entries in it as -1 
    int dp[n][n]; 
    memset(dp, -1, sizeof dp); 
  
    // Compute longest path beginning from all cells 
    for (int i=0; i<n; i++) 
    { 
      for (int j=0; j<n; j++) 
       { 
          if (dp[i][j] == -1) 
             findLongestFromACell(i, j, mat, dp); 
  
          //  Update result if needed 
          result = max(result, dp[i][j]); 
       } 
     } 
  
     return result; 
} 
```
