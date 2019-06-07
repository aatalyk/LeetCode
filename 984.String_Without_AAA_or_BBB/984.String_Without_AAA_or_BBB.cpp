class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";
        int i = 0;
        
        while (A > 0 && B > 0) {
            if (i > 1 && res[i-1] == res[i-2]) {
                if (res[i-1] == 'a') {
                    res += "b";
                    B--;
                } else {
                    res += "a";
                    A--;
                }
                cout<<"hey";
            } else {
                if (A > B) {
                    res += "a";
                    A--;
                } else {
                    res += "b";
                    B--;
                }
            }
            i++;
        }
        
        while (A > 0) {
            res += "a";
            A--;
        }
        
        while (B > 0) {
            res += "b";
            B--;
        }
        
        return res;
    }
};
