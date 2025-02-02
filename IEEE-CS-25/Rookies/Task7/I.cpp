#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    vector<int> piles(t);
    cin >> piles[0];
    for (int i = 1; i < t; i++)
    {
        cin >> piles[i];
        piles[i] = piles[i] + piles[i - 1];
    }
    for (auto i : piles)
        cout << i << endl;
    cin >> n;
    vector<int> labels(n);
    for (int i = 0; i < n; i++)
    {
        cin >> labels[i];
    }

    for (int i = 0; i < n; i++)
    {
        int label = labels[i];
        int pileIndex = lower_bound(piles.begin(), piles.end(), label) - piles.begin();
        cout << pileIndex + 1 << endl;
    }
    return 0;
}