# 986. Interval List Intersections

Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

![Example](https://assets.leetcode.com/uploads/2019/01/30/interval1.png)

## Solution

This problem looks similar other problems related to intervals merging. In this case we need to find intersections of two intervals. We consider three cases:

* Intervals do not intersect or have similar edges
* Intervals do not intersect but have similar edges
* Intervals intersect

We will iterate through two intervals having two pointers ***i*** and ***j*** respectively. But how to choose which pointer we should move? So its intuitive if *start* of interval is greater than *end* of second interval then move pointer of first interval.

```cpp
while (i < A.size() && j < B.size()) {
    if (A[i][0] > B[j][1]) {
    } else if (B[j][0] > A[i][1]) {  
    } else if (A[i][0] == B[j][1]) {
        res.push_back({A[i][0], A[i][0]});
    } else if (B[j][0] == A[i][1]) {
        res.push_back({B[j][0], B[j][0]});
    } else {
        res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
    }
    if (A[i][1] >= B[j][1]) {
        j++;
    } else {
        i++;
    }
}
```