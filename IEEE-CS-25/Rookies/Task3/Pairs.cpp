#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    unordered_set<int> elements;
    int count = 0;

    for (int num : arr)
    {
        elements.insert(num);
    }

    for (int num : arr)
    {
        if (elements.count(num + k))
        {
            ++count;
        }
        if (elements.count(num - k))
        {
            ++count;
        }
        elements.erase(num);
    }
    cout << count << endl;
    return 0;
}
