class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int add = 0, sub = 0, maxSub = 0;
        
        /*
        customers = [1,0,1,2,1,1,7,5]
        grumpy =    [0,1,0,1,0,1,0,1] 
                     0 1 2 3 4 5 6 7
        X = 3
        
        add = 1 + 1 + 1 + 7 = 10
        sub = 2
        
        */
        
        for (int i = 0; i < customers.size(); ++i) {
            add += grumpy[i] == 0 ? customers[i] : 0;
            sub += grumpy[i] == 1 ? customers[i] : 0;
            if (i >= X) {
                sub -= grumpy[i-X] == 1 ? customers[i-X] : 0;
            } 
            maxSub = max(maxSub, sub);
        }
        
        return add + maxSub;
    }
};
