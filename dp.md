## Dynamic Programming

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
