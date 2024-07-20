class Solution {
public:
    static vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int r=rowSum.size(), c=colSum.size();
        vector<vector<int>> arr(r, vector<int>(c, 0));
        for (int i=0, j=0; i<r && j<c ; i+=(rowSum[i]==0), j+=(colSum[j]==0)){
            int x=min(rowSum[i], colSum[j]);
            arr[i][j]=x;
            rowSum[i]-=x;
            colSum[j]-=x;
        }
        return arr;
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
