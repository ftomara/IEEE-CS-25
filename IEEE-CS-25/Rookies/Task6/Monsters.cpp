#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 1005;
const int INF = 1e9;

int n, m;
char grid[MAX_N][MAX_N];
int dist_monsters[MAX_N][MAX_N];
int dist_player[MAX_N][MAX_N];
pair<int, int> parent[MAX_N][MAX_N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string dir = "DURL";

void bfs_monsters(vector<pair<int, int>> &monsters)
{
    queue<pair<int, int>> q;
    for (auto &monster : monsters)
    {
        q.push(monster);
        dist_monsters[monster.first][monster.second] = 0;
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist_monsters[nx][ny] == INF)
            {
                dist_monsters[nx][ny] = dist_monsters[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

bool bfs_player(pair<int, int> start)
{
    queue<pair<int, int>> q;
    q.push(start);
    dist_player[start.first][start.second] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
        {
            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && dist_player[nx][ny] == INF)
            {
                if (dist_player[x][y] + 1 < dist_monsters[nx][ny])
                {
                    dist_player[nx][ny] = dist_player[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

void print_path(pair<int, int> start, pair<int, int> end)
{
    vector<char> path;
    while (end != start)
    {
        auto [x, y] = end;
        auto [px, py] = parent[x][y];
        for (int i = 0; i < 4; ++i)
        {
            if (px + dx[i] == x && py + dy[i] == y)
            {
                path.push_back(dir[i]);
                break;
            }
        }
        end = {px, py};
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (char c : path)
    {
        cout << c;
    }
    cout << endl;
}

int main()
{
    cin >> n >> m;
    vector<pair<int, int>> monsters;
    pair<int, int> start;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            dist_monsters[i][j] = INF;
            dist_player[i][j] = INF;
            if (grid[i][j] == 'M')
            {
                monsters.push_back({i, j});
            }
            else if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
        }
    }
    bfs_monsters(monsters);
    if (bfs_player(start))
    {
        cout << "YES" << endl;
        pair<int, int> end;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && dist_player[i][j] != INF)
                {
                    end = {i, j};
                    break;
                }
            }
        }
        print_path(start, end);
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}