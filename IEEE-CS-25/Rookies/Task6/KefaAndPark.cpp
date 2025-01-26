#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> cats;
int n, m;
int result = 0;

void dfs(int u, int parent, int consecutive) {
    if (cats[u]) {
        consecutive++;
    } else {
        consecutive = 0;
    }
    if (consecutive > m) {
        return;
    }
    bool isLeaf = true;
    for (int v : adj[u]) {
        if (v != parent) {
            isLeaf = false;
            dfs(v, u, consecutive);
        }
    }
    if (isLeaf && u != 1) {
        result++;
    }
}

int main() {
    cin >> n >> m;
    cats.resize(n + 1);
    adj.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> cats[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, -1, 0);
    cout << result << endl;
    return 0;
}