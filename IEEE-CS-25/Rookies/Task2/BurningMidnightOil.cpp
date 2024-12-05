#include <iostream>
using namespace std;

long long TLcalc(long long v, int k)
{
    long long total = 0;
    long long current = v;
    while (current > 0)
    {
        total += current;
        current /= k;
    }
    return total;
}
int main()
{
    long long n;
    int k;
    cin >> n >> k;
    long long left = 1, right = n;
    long long result = n;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        if (TLcalc(mid, k) >= n)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << result << endl;
    return 0;
}
