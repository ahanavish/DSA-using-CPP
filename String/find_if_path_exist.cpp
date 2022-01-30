// DFS
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
                if (dfs(adj, vis, start, end))
                    return true;

        return false;
    }

    bool dfs(vector<int> adj[], vector<int> &vis, int start, int end)
    {
        if (end == start)
            return true;

        vis[start] = 1;
        for (auto it : adj[start])
            if (vis[it] == 0)
                if (dfs(adj, vis, it, end))
                    return true;

        return false;
    }
};

// BFS
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> adj[n];
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;

            for (auto a : adj[node])
                if (!vis[a])
                {
                    vis[a] = 1;
                    q.push(a);
                }
        }
        return false;
    }
};