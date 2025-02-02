#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t, score = 0, streak = 0;
    cin >> t;
    vector<int> matches(t);
    for (int i = 0; i < t; i++)
    {
        cin >> matches[i];
    }
    for (int i = 0; i < matches.size(); i++)
    {
        if (matches[i] == 1)
        {
            score++;
            streak++;
        }
        else
        {

            score--;
            streak = 0;
        }
        if (streak >= 3 and matches[i] == 1)
            score++;
    }
    cout << score;

    return 0;
}