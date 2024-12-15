#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
vector<long long> v(31);
long long solve(long long n)
{
    if (n == 0)
        return v[0];
    if (n == 1)
        return v[1];
    else
        return v[n] = solve(n - 1) + solve(n - 2);
}
// 0 1 2 3 4 5 6
// 0 1 1 2 3 5 8
int main()
{

    v[0] = 0;
    v[1] = 1;
    long long n;
    cin >> n;
    cout << solve(n);
    return 0;
}
