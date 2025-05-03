#include <bits/stdc++.h>
using namespace std;

void TOH(int N, int from, int aux, int dest)
{
    if (N == 1)
    {
        cout << "Move disk " << N << " from " << from << " to " << dest << endl;
        return;
    }
    TOH(N - 1, from, dest, aux);
    cout << "Move disk " << N << " from " << from << " to " << dest << endl;
    TOH(N - 1, aux, from, dest);
}

int main()
{
    int n;
    cout << "Enter number of disks : ";
    cin >> n;
    TOH(n, 1, 2, 3);
    cout << "Steps required : " << pow(2, n) - 1;
}