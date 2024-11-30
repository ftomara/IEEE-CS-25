#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    string dirs;
    cin >> dirs;

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    int min_time = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        if (dirs[i] == 'R' && dirs[i + 1] == 'L') {
            int time = (pos[i + 1] - pos[i]) / 2;
            min_time = min(min_time, time);
        }
    }

    if (min_time == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << min_time << endl; 
    }

    return 0;
}
