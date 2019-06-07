class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> res;
        
        queue<vector<int>> q;
        q.push({r0, c0});
        
        bool used[R][C];
        
        memset(used, false, sizeof(used));
        
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            
            if (used[pos[0]][pos[1]]) {
                continue;
            }
            
            res.push_back(pos);
            used[pos[0]][pos[1]] = true;
            
            for (int i = 0; i < dirs.size(); ++i) {
                int r = pos[0] + dirs[i][0];
                int c = pos[1] + dirs[i][1];
                
                if (r < 0 || r >= R || c < 0 || c >= C) {
                    continue;
                }
                
                q.push({r, c});
            }
        }
        
        return res;
    }
};
