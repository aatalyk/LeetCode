# 955. Delete Columns to Make Sorted II

We are given an array A of N lowercase letter strings, all of the same length.

Now, we may choose any set of deletion indices, and for each string, we delete all the characters in those indices.

For example, if we have an array A = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef","vyz"].

Suppose we chose a set of deletion indices D such that after deletions, the final array has its elements in lexicographic order (A[0] <= A[1] <= A[2] ... <= A[A.length - 1]).

Return the minimum possible value of D.length.

## Solution

To solve this problem we need to consider several cases:

* keep track of sorted strings in the array meaning if prev is less than next, this works for cases when characters for current index violates sorting but we want to be sure about prev characters too.
* when char from prev string is greater than char in current string & prev sorted stayed will not affect current state -> we will increment counter.
* when char from prev string is equal to char in current string -> go to the next value if array reaches the end update array of sorted strings.

```cpp
if (!sorted[i] && A[i][j] < A[i-1][j]) {
    count++;
    break;
} 
```