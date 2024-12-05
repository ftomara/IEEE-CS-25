#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{

    int c, t;
    cin >> c >> t;
    vector<int> cities(c), towers(t);
    for (int i = 0; i < c; i++)
    {
        cin >> cities[i];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> towers[i];
    }
    int maxR = INT_MIN;
    for (int i = 0; i < c; i++)
    {
        int minD = INT_MAX;
        int left = 0;
        int right = t - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int dist = abs(cities[i] - towers[mid]);
            minD = min(minD, dist);
            if (towers[mid] < cities[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        maxR = max(maxR, minD);
    }
    cout << maxR << endl;

    return 0;
}