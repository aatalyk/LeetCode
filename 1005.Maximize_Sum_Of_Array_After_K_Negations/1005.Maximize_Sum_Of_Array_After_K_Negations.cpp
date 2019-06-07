class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (int a : A) {
            q.push(a);
        }
        
        for (int k = 0; k < K; ++k) {
            int top = q.top();
            q.pop();
            q.push(-top);
        }
        
        int sum = 0;
        
        while (!q.empty()) {
            sum += q.top();
            q.pop();
        }
        
        return sum;
    }
};
