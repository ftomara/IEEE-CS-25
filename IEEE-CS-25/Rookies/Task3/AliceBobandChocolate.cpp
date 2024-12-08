#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i];
    }

    int left = 0, right = n - 1;
    int timeAlice = 0, timeBob = 0;
    int countAlice = 0, countBob = 0;

    while (left <= right)
    {
        if (timeAlice <= timeBob)
        {
            timeAlice += t[left];
            ++countAlice;
            ++left;
        }
        else
        {
            timeBob += t[right];
            ++countBob;
            --right;
        }
    }

    cout << countAlice << " " << countBob << "\n";
    return 0;
}
