#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    int t, n;
    cin >> t >> n;
    vector<int> cells(t - 1);
    for (int i = 0; i < t - 1; i++)
    {
        cin >> cells[i];
    }
    int i = 1;
    bool found = false;
    while (i <= t - 1)
    {
        i = i + cells[i - 1];
        if (i == n)
        {
            cout << "YES\n";
            found = true;
            break;
        }
        if (i > n)
        {
            cout << "NO\n";
            break;
        }
    }
    // if (!found)
    //     cout << "NO\n";

    return 0;
}