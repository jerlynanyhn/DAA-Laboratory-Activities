#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    if (n == 1)
    {
        cout << "Number of distinct ways: 1";
        return 0;
    }

    int a = 1, b = 2, c;

    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    cout << "Number of distinct ways: " << b;

    return 0;
}