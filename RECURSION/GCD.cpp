#include <bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    findGCD(b, a % b);
}

int main()
{
    int a, b;
    cout << "Enter 1st number : ";
    cin >> a;
    cout << "Enter 2nd number : ";
    cin >> b;
    cout << "GCD of " << a << " and " << b << " is " << findGCD(a, b);
}