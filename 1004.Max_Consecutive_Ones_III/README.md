# 1004. Max Consecutive Ones III

Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

## How to solve this problem?

This problem is relatively simple if you understand what do you need find exactly. So in this case we are given an array of 0s and 1s we can flip K number of 0s to 1 to get max number of consequetive 1s. So we need to find the longest subsequence with 1s and at most K 0s which we can flip. For this problem we will use sliding window approach. First count all 0s and if nunber of 0s is greater than required value of K then move our window towards right.

```cpp
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
```