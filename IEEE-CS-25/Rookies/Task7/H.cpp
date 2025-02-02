#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        unordered_map<int, int> freqB, windowFreq;

        for (int &x : a)
            cin >> x;
        for (int &x : b)
        {
            cin >> x;
            freqB[x]++;
        }

        int count = 0, countGood = 0;

        for (int i = 0; i < n; i++)
        {
            if (i >= m)
            {
                int removeElement = a[i - m];
                if (freqB.count(removeElement))
                {
                    if (windowFreq[removeElement] <= freqB[removeElement])
                        count--;
                    windowFreq[removeElement]--;
                }
            }

            if (freqB.count(a[i]))
            {
                if (windowFreq[a[i]] < freqB[a[i]])
                    count++;
                windowFreq[a[i]]++;
            }

            if (i >= m - 1 && count >= k)
                countGood++;
        }

        cout << countGood << '\n';
    }
    return 0;
}
