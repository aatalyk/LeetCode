# 935. Knight Dialer

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

## How to solve this problem?

Lets consider the simple case for this problem when N = 1. Meaning that Knight can move only once. N is number of digits in number and N-1 defines how many steps Knight can do assuming that current position of Knight will be counted.

So digits on phone pad is 0 1 2 4 5 6 7 8 9.

We can store possible moves based on the pad cause we already know steps that Knight can take which is basically *L* shape. 

For example, 
from 0 Knight can move to 4 and 6
from 3 Knight can move to 4 and 8
so on...

For this reason we can use adjacency matrix where each value will store its possible next values.

[
    0: [4, 6]
    3: [4, 8]
]

So for each digits from 0 to 9 we can traverse itself and next possible step digits. So this problem falls into DFS.

For example, lets consider the case when N = 2.

We will traverse digits from 0 to 9. Then based on current digits go to next digit. Lets write naive implementation based on current algorithm.

```cpp
int dfs(int N, int v, vector<vector<int>> &moves) {
    if (N == 0) {
        return 1;
    }

    int count = 0;

    for (int i = 0; i < moves[v].size(); ++i) {
        int to = moves[v][i];
        count += dfs(N-1, to, moves);
    }

    return count;
}
```

Lets run the algorithm

Starting from 0

                2,0 (N, digit)                      2,1 (N, digit)
              /      \                            /       \
          1,4           1,6                     1,6         1,8
     /    |   \      /   |   \               /   |   \     /   \
    0,3  0,9  0,7   0,1  0,0  0,7          0,1  0,0  0,7  0,1  0,3

As you can see from the problem graph above we recalculating some of steps several times exponentially. We recalculating [1,6] twice in this example.

Most of the digits can produce two steps so time complexity for this solution may become *2^N*.

In order to solve these issue we need to preserve our current result so we will recalculate it again later. For example, save current state in 2D array.

Based on this memoization

```cpp
int dfs(int N, int v, vector<vector<int>> &moves, vector<vector<int>> &dp) {
    if (N == 0) {
        return 1;
    }

    if (dp[N][v] > 0) {
        return dp[N][v];
    }

    int count = 0;

    for (int i = 0; i < moves[v].size(); ++i) {
        int to = moves[v][i];
        count += dfs(N-1, to, moves);
    }

    dp[N][v] = count;

    return dp[N][v];
}
```

### Time Complexity 

*O(N^2)*

### Space Complexity 

*O(N^2)*

