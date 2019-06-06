class Solution {
public:
    vector<int> graph[10010];
    vector<int> colors;
    
    bool dfs(int v, int type) {
        colors[v] = 0;
        
        for (int i = 0; i < graph[v].size(); ++i) {
            int to = graph[v][i];
            
            if (colors[to] == type) {
                return false;
            }
        }
        
        colors[v] = type;
        return true;
    }
    
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        
        colors.assign(N, 0);
        
        for (vector<int> &path : paths) {
            graph[path[0]-1].push_back(path[1]-1);
            graph[path[1]-1].push_back(path[0]-1);
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= 4; ++j) {
                if (dfs(i, j)) {
                    break;
                }
            }
        }
        
        return colors;
    }
};
