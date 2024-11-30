#include <iostream>
#include <vector>
using namespace std;

void LuckyNumbers(int current, int limit, vector<int> &luckyNumbers)
{
    if (current > limit)
        return;
    if (current != 0)
        luckyNumbers.push_back(current);
    // cout<<"current : "<<current<<endl;
    LuckyNumbers(current * 10 + 4, limit, luckyNumbers);
    LuckyNumbers(current * 10 + 7, limit, luckyNumbers);
}

int main()
{
    int n;
    cin >> n;

    vector<int> luckyNumbers;
    LuckyNumbers(0, 1000, luckyNumbers);
    // for (int lucky : luckyNumbers)
    // {
    //     cout << lucky << " ";
    // }

    for (int lucky : luckyNumbers)
    {
        if (n % lucky == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
