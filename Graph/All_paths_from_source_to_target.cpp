// DFS
class Solution
{
public:
    int start, end;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        start = 0, end = graph.size() - 1;

        vector<vector<int>> store;
        vector<int> path;

        dfs(store, path, graph);

        return store;
    }

    void dfs(vector<vector<int>> &store, vector<int> &path, vector<vector<int>> graph, int start = 0)
    {
        path.push_back(start);

        if (start == end)
        {
            store.push_back(path);
            path.pop_back();
            return;
        }

        for (auto &s : graph[start])
            dfs(store, path, graph, s);

        path.pop_back();
    }
};

// BFS
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        int n = graph.size(), s = 0, e = n;
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
            for (auto g : graph[i])
                adj[i].push_back(g);

        queue<vector<int>> q;
        vector<int> path;
        q.push({0});
        while (!q.empty())
        {
            path = q.front();
            q.pop();
            if (path.back() == n - 1)
                result.push_back(path);

            for (auto ele : adj[path.back()])
            {
                vector<int> temp = path;
                temp.push_back(ele);
                q.push(temp);
            }
        }
        return result;
    }
};