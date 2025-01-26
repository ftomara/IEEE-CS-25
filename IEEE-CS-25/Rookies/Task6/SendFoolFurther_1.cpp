#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int maxCost = 0;

void dfs(int u, int currentCost) {
    visited[u] = true;
    maxCost = max(maxCost, currentCost);
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int cost = edge.second;
        if (!visited[v]) {
            dfs(v, currentCost + cost);
        }
    }
    visited[u] = false;
}

int main() {
    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n, false);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    dfs(0, 0);
    cout << maxCost << endl;
    return 0;
}