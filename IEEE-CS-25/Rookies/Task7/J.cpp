#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
bool isNice(int n)
{
    string num = to_string(n);
    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] != '6' && num[i] != '9')
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i = n;
        while (true)
        {
            if (isNice(i) && i>=n)
            {
                cout << i << endl;
                break;
            }
            i++;    
        }
    }

    return 0;
}