#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    char dir;
    cin >> dir;
    string message;
    cin >> message;
    map<char, pair<char, char> > mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
            mp[s[i]] = make_pair('0', s[i + 1]);
        else if (i == s.size() - 1)
            mp[s[i]] = make_pair(s[i - 1], '0');
        else
            mp[s[i]] = make_pair(s[i - 1], s[i + 1]);
    }
    string result = "";
    for (int i = 0; i < message.size(); i++)
    {
        if (dir == 'R')
        {
            result += (mp[message[i]].first == '0') ?: mp[message[i]].first;
        }
        else
            result += (mp[message[i]].second == '0') ?: mp[message[i]].second;
    }
    cout << result << endl;
    return 0;
}
