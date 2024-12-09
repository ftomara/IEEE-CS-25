#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
const string moves = "DULR";

struct State
{
    int x, y, time;
};

bool is_valid(int x, int y, int n, int m, const vector<string> &grid)
{
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.';
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    queue<State> monster_queue;
    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));

    int start_x, start_y;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'M')
            {
                monster_queue.push({i, j, 0});
                monster_time[i][j] = 0;
            }
            else if (grid[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    while (!monster_queue.empty())
    {
        State current = monster_queue.front();
        monster_queue.pop();

        for (const auto &dir : directions)
        {
            int nx = current.x + dir.first;
            int ny = current.y + dir.second;

            if (is_valid(nx, ny, n, m, grid) && monster_time[nx][ny] > current.time + 1)
            {
                monster_time[nx][ny] = current.time + 1;
                monster_queue.push({nx, ny, current.time + 1});
            }
        }
    }

    queue<State> player_queue;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    player_queue.push({start_x, start_y, 0});
    visited[start_x][start_y] = true;

    while (!player_queue.empty())
    {
        State current = player_queue.front();
        player_queue.pop();

        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1)
        {
            cout << "YES" << endl;

            string path;
            int x = current.x, y = current.y;
            while (parent[x][y] != -1)
            {
                int dir = parent[x][y];
                path += moves[dir];
                x -= directions[dir].first;
                y -= directions[dir].second;
            }

            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = current.x + directions[i].first;
            int ny = current.y + directions[i].second;

            if (is_valid(nx, ny, n, m, grid) && !visited[nx][ny] && current.time + 1 < monster_time[nx][ny])
            {
                visited[nx][ny] = true;
                parent[nx][ny] = i;
                player_queue.push({nx, ny, current.time + 1});
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
