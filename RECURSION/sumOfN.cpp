#include <bits/stdc++.h>
using namespace std;

int sumOfN(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + sumOfN(n - 1);
}

int main()
{
    int n;
    cout << "Enter n value : ";
    cin >> n;
    cout << "Sum of " << n << " numbers is " << sumOfN(n);
}