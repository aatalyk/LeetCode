# 997. Find the Town Judge

In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

## Solution

So intuition for this problem is the fact that *judge* trusts no other person and everyone trusts judge. Based on this we can determine the judge in the town. So first criteria should be 0 and second criteria should be N - 1. 

```cpp
for (vector<int> t : trust) {
    count[t[0]-1]--;
    count[t[1]-1]++;
}
```