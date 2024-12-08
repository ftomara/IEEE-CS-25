#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int start = 0, maxTeamSize = 0;
    for (int end = 0; end < n; ++end)
    {
        while (a[end] - a[start] > 5)
        {
            ++start;
        }
        maxTeamSize = max(maxTeamSize, end - start + 1);
    }

    cout << maxTeamSize << "\n";
    return 0;
}
