#include <bits/stdc++.h>
using namespace std;

int power(int n, int x)
{
    if (x == 1)
    {
        return n;
    }
    return n * power(n, x - 1);
}

int main()
{
    int n;
    cout << "Enter n value : ";
    cin >> n;
    int x;
    cout << "Enter x value : ";
    cin >> x;
    cout << n << " Power " << n << " is " << power(n, x);
}