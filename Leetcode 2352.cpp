class Solution {
public:
    int equalPairs(vector<vector<int>> &grid)
{
    int n = grid.size();
    int count = 0;
    map<vector<int>, int> row, col;
    for (int i = 0; i < n; i++)
    {
        row[grid[i]]++;
    }

    vector<int> dummy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dummy.push_back(grid[j][i]);
        }
        if (row.find(dummy) != row.end())
        {
            count += row[dummy];
        }
        dummy.clear();
    }
    return count;
}
};
           
 


