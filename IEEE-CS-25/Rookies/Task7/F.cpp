#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vector<long long> a(k), b(k), qr(q);
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < q; i++)
        {
            cin >> qr[i];
        }
        vector<double> velocity(k);
        velocity[0] = (double)(a[0]) / b[0];
        for (int i = 1; i < k; i++)
        {
            velocity[i] = (double)(a[i] - a[i - 1]) / (b[i] - b[i - 1]);
        }
        for (int i = 0; i < q; i++)
        {
            long long d = qr[i];
            if (d == 0)
            {
                cout << 0 << " ";
                continue;
            }
            int labelIndex = upper_bound(a.begin(), a.end(), qr[i]) - a.begin();
            if (labelIndex != 0)
            {
                labelIndex--;
                long long time = floor(b[labelIndex] + ((qr[i] - a[labelIndex]) / velocity[labelIndex+1]));
                cout << time << " ";
            }
            else
            {
                double time = (double)d / velocity[0];
                cout << (long long)time << " ";
            }
        }
        cout << endl;
    }

    return 0;
}