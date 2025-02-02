#include <iostream>
#include <vector>
using namespace std;

long long countVaction(long long m, long long k)
{
    if (m < k)
        return 0;
    long long valid = (m - k + 1);
    return valid * (valid + 1) / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long count = 0, length = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] <= q)
            {
                length++;
            }
            else
            {
                count += countVaction(length, k);
                length = 0;
            }
        }
        count += countVaction(length, k);
        cout << count << "\n";
    }
    return 0;
}
