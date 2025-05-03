#include <bits/stdc++.h>
using namespace std;

void printNum(int num, int n)
{
    if (num == n)
    {
        cout << num << endl;
        return;
    }
    cout << num << " ";
    printNum(num + 1, n);
}

int main()
{
    int n;
    cout << "Enter upto where you want to print : ";
    cin >> n;
    printNum(1, n);
}