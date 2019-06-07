# 1005. Maximize Sum Of Array After K Negations

Given an array A of integers, we must modify the array in the following way: we choose an i and replace A[i] with -A[i], and we repeat this process K times in total.  (We may choose the same index i multiple times.)

Return the largest possible sum of the array after modifying it in this way.

## Solution

To solve this problem every time we need to choose one value to negate. Then repeat this operation K times to get maximum value. Intuition is always to choose the smallest value then update it. So *priority_queue* works perfect for this problem. So it was solved using pq.

```cpp
for (int k = 0; k < K; ++k) {
    int top = q.top();
    q.pop();
    q.push(-top);
}
```