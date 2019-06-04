class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = (int)arr1.size() - 1;
        int j = (int)arr2.size() - 1;
        int carry = 0;
        
        vector<int> res;
        
        while (i >= 0 && j >= 0) {
            carry += arr1[i--] + arr2[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (i >= 0) {
            carry += arr1[i--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (j >= 0) {
            carry += arr2[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (carry) {
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        
        while (res.size() > 1 && res.back() == 0) {
            res.pop_back();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
