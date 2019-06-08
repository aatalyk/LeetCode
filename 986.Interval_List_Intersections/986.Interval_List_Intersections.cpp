class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        
        int i = 0, j = 0;
        
        while (i < A.size() && j < B.size()) {
            if (A[i][0] > B[j][1]) {
            } else if (B[j][0] > A[i][1]) {  
            } else if (A[i][0] == B[j][1]) {
                res.push_back({A[i][0], A[i][0]});
            } else if (B[j][0] == A[i][1]) {
                res.push_back({B[j][0], B[j][0]});
            } else {
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            }
            if (A[i][1] >= B[j][1]) {
                j++;
            } else {
                i++;
            }
        }
        
        return res;
    }
};
