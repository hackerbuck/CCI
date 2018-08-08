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
