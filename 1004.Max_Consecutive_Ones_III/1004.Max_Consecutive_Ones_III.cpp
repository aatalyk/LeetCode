class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count = 0, i = 0, j = 0, ans = 0;
        
        /*       0 1 2 3 4 5
            A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
                 0 0 0 1 2 3
                  0 1 2 3 4 5 6 7 8 9 10
                 [0,0,1,1,1,0,0,1,1,1,1]
1
        
                [0,0,1,1,1,0,0]
                 1
        */
        
        while (i < A.size()) {
            count += A[i] == 0;
            while (count > K) {
                count -= A[j++] == 0;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        
        return ans;
    }
};
