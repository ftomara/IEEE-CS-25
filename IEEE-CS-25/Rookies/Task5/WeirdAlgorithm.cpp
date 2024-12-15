#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
void solve(long long n)
{
    if (n == 1)
    {
        // cout << n << endl;
        return;
    }
    else if (n % 2 == 0)
    {
        cout << (n / 2) << " ";
        solve(n / 2);
    }
    else
    {
        cout << (n * 3) + 1 << " ";
        solve((n * 3) + 1);
    }
}
int main()
{

    long long n;
    cin >> n;
    cout<<n<<" ";
    solve(n);
    return 0;
}
