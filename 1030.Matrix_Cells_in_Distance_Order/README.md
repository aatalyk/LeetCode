# 1030. Matrix Cells in Distance Order

We are given a matrix with R rows and C columns has cells with integer coordinates (r, c), where 0 <= r < R and 0 <= c < C.

Additionally, we are given a cell in that matrix with coordinates (r0, c0).

Return the coordinates of all cells in the matrix, sorted by their distance from (r0, c0) from smallest distance to largest distance.  Here, the distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance, |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that satisfies this condition.)

## How to solve this problem?

This problem asks to find all nearest points to the given coordinate. Distance is calculated using Manhattan distance. This problem is classic BFS meaning that from the given point we will go to all its ancestors. Each time we check all 4 directions if it is valid meaning that its inside given range and was not processed before.

> Time Complexity O(n)
> Space Complexity O(n)

```cpp
for (int i = 0; i < dirs.size(); ++i) {
    int r = pos[0] + dirs[i][0];
    int c = pos[1] + dirs[i][1];
    
    if (r < 0 || r >= R || c < 0 || c >= C) {
        continue;
    }
    
    q.push({r, c});
}
```