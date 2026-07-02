#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    switch (n % 2)
    {
    case 0:
        cout << n << ' ' << "is even" << '\n';
        break;
    case 1:
        cout << n << ' ' << "is odd" << '\n';
        break;
    }
    return 0;
}