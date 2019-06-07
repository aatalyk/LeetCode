class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        //check criteria 1
        vector<int> count(N, 0);
        
        for (vector<int> t : trust) {
            count[t[0]-1]--;
            count[t[1]-1]++;
        }
        
        for (int i = 0; i < N; ++i) {
            if (count[i] == N-1) {
                return i+1;
            }
        }
        
        return -1;
    }
};
