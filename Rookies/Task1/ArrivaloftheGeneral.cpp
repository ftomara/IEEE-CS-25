#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, maximum = INT_MIN, minimum = INT_MAX, posmx = -1, posmn = -1;
    cin >> n;
    vector<int> a;
    while (n--)
    {
        cin >> c;
        a.push_back(c);
      
    }
    for (size_t i = 0; i < a.size(); i++)
    {
        if (a[i] > maximum)
        {
            maximum = a[i];
            posmx = i;
        }
        if (a[i] <= minimum)
        {
            minimum = a[i];
            posmn = i;
        }
    }
    n = a.size();
    // cout << posmx << " " << posmn << " " << posmx + (n - 1 - posmn) << endl;
    int swapcount = (posmx == posmn) ? 0 : (posmx + (n - 1 - posmn));
    if (posmx > posmn)
        swapcount--;

    cout << swapcount << endl;

    return 0;
}
