#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
void bfs(int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int n : adj[node])
        {
            if (!visited[n])
            {
                q.push(n);
                visited[n] = true;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, r;
    cin >> c >> r;
    vector<vector<int>> adj(c + 1);
    vector<bool> visited(c + 1, false);
    for (int i = 0; i < r; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> groups;
    for (int i = 1; i <= c; i++)
    {
        if (!visited[i])
        {
            groups.push_back(i);
            bfs(i, adj, visited);
        }
    }
    cout << groups.size() - 1 << endl;
    for (int i = 0; i < groups.size() - 1; i++)
    {
        cout << groups[i] << " " << groups[i + 1] << endl;
    }
    return 0;
}