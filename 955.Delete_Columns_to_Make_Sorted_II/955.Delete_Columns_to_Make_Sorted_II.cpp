class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int count = 0;
        vector<bool> sorted(A.size(), false);
        
        for (int j = 0, i; j < A[0].size(); ++j) {
            for (i = 1; i < A.size(); ++i) {
                if (!sorted[i] && A[i][j] < A[i-1][j]) {
                    count++;
                    break;
                } 
            }
            if (i < A.size()) {
                continue;
            }
            for (int i = 1; i < A.size(); ++i) {
                sorted[i] = sorted[i] || A[i][j] > A[i-1][j];
            }
        }
        
        return count;
    }
};
