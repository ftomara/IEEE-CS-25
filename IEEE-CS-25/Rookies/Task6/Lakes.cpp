#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set> 
#include <algorithm>
using namespace std;


const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    visited[x][y] = true;
    int volume = grid[x][y];

    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] > 0) {
            volume += dfs(nx, ny, grid, visited);
        }
    }
    return volume;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        int maxV = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxV = max(maxV, dfs(i, j, grid, visited));
                }
            }
        }

        cout << maxV << endl;
    }

    return 0;
}