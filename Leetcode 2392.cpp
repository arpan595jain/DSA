class Solution {
public:
        vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
{
    vector<int> adj1[k], adj2[k];
    vector<int> indegree1(k, 0), indegree2(k, 0);
    for (auto it : rowConditions)
    {
        int u = it[0] - 1;
        int v = it[1] - 1;
        adj1[u].push_back(v);
        indegree1[v]++;
    }

    for (auto it : colConditions)
    {
        int u = it[0] - 1;
        int v = it[1] - 1;
        adj2[u].push_back(v);
        indegree2[v]++;
    }

    vector<int> order1, order2;
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (indegree1[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order1.push_back(node);

        for (auto it : adj1[node])
        {
            indegree1[it]--;
            if (indegree1[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (order1.size() < k)
    {
        return {};
    }

    for (int i = 0; i < k; i++)
    {
        if (indegree2[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        order2.push_back(node);

        for (auto it : adj2[node])
        {
            indegree2[it]--;
            if (indegree2[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if (order2.size() < k)
    {
        return {};
    }

    vector<pair<int, int>> v(k);
    for (int i = 0; i < order1.size(); i++)
    {
        v[order1[i]].first = i;
    }

    for (int i = 0; i < order2.size(); i++)
    {
        v[order2[i]].second = i;
    }

    vector<vector<int>> ans(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        ans[x][y] = i + 1;
    }

    return ans;
}
};
