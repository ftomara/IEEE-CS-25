#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set> 
#include <algorithm>
using namespace std;

vector<string> v;

void solve(string n) {
    queue<string> q;       
    set<string> s; 

    q.push(n); 
    s.insert(n);

    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        for (int i = 0; i < curr.size(); i++) {
            for (int j = i + 1; j < curr.size(); j++) {
                string temp = curr;
                swap(temp[i], temp[j]); 

                if (s.find(temp) == s.end()) {
                    s.insert(temp);
                    q.push(temp);
                }
            }
        }
    }

    v.assign(s.begin(), s.end());

    sort(v.begin(), v.end());
}

int main() {
    string n;
    cin >> n;

    solve(n);

    cout << v.size() << endl;
    for (const string &str : v) {
        cout << str << endl;
    }

    return 0;
}
