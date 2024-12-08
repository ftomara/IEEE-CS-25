#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long l, r;
        cin >> n >> l >> r;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        long long count = 0;

        for (int i = 0; i < n; ++i)
        {
            int left = i + 1, right = n - 1, low = -1, high = -1;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (a[i] + a[mid] >= l)
                {
                    low = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            left = i + 1, right = n - 1;

            while (left <= right)
            {
                int mid = (left + right) / 2;
                if (a[i] + a[mid] <= r)
                {
                    high = mid;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            if (low != -1 && high != -1 && low <= high)
            {
                count += (high - low + 1);
            }
        }

        cout << count << "\n";
    }
    return 0;
}
