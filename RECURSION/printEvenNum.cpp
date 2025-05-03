#include <bits/stdc++.h>
using namespace std;

void printEvenNum(int num, int n)
{
    if (num > n)
    {
        return;
    }
    cout << num << " ";
    printEvenNum(num + 2, n);
}

int main()
{
    int n;
    cout << "Enter n value : ";
    cin >> n;
    printEvenNum(2, n);
}