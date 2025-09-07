class Solution
{
public:
    bool vis[1005];

    void bfs(int src, vector<vector<int>> &rooms)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty())
        {
            int par = q.front();
            q.pop();

            cout << par << " ";

            for (auto child : rooms[par])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        memset(vis, false, sizeof(vis));

        bfs(0, rooms);

        for (int i = 0; i < rooms.size(); i++)
        {
            if (!vis[i])
                return false;
        }
        return true;
    }
};