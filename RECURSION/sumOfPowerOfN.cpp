#include <bits/stdc++.h>
using namespace std;

int sumOfPower(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * n + sumOfPower(n - 1);
}

int main()
{
    int n;
    cout << "Enter n value : ";
    cin >> n;

    cout << "Sum of Square of " << n << " numbers is " << sumOfPower(n);
}