#include <bits/stdc++.h>
using namespace std;

int nthStair(int n)
{
    if (n == 1 || n == 2)
    {
        return n;
    }
    return nthStair(n - 1) + nthStair(n - 2);
}

int main()
{
    int n;
    cout << "Enter n value : ";
    cin >> n;
    cout << "Number of ways to reach " << n << "th Stair : " << nthStair(n);
}