#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<bool> vis(n + 1, false);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj_list[u])
        {
            if (!vis[v])
            {
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;
    int node = n;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (auto x : path)
        cout << x << " ";
    cout << "\n";

    return 0;
}
