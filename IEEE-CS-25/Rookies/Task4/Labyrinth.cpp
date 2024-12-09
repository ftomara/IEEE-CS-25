#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
// #include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // U, D, L, R
string dir_chars = "UDLR";

bool isValid(int x, int y, vector<vector<char>> &adj, vector<vector<bool>> &visited) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && adj[x][y] != '#';
}

void bfs(pair<int, int> start, pair<int, int> end, vector<vector<char>> &adj) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second) {
            cout << "YES\n";

            string path;
            pair<int, int> current = end;
            while (current != start) {
                auto [px, py] = parent[current.first][current.second];
                for (int i = 0; i < 4; i++) {
                    if (px + directions[i].first == current.first && py + directions[i].second == current.second) {
                        path += dir_chars[i];
                        break;
                    }
                }
                current = parent[current.first][current.second];
            }

            reverse(path.begin(), path.end());
            cout << path.size() << "\n" << path << "\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;
            if (isValid(nx, ny, adj, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(m));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 'A') {
                start = {i, j};
            } else if (adj[i][j] == 'B') {
                end = {i, j};
            }
        }
    }

    bfs(start, end, adj);

    return 0;
}
