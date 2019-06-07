# 984. String Without AAA or BBB

Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;

    The substring 'aaa' does not occur in S;

    The substring 'bbb' does not occur in S.

## Solution

This question basically asks to return string of length A + B where there is no *aaa* or *bbb*. The problem falls into gready approach meaning to choose optimal value for current moment. We will iterate till we have no As or Bs. Every time check if previous two chars is equal if they are equal then add different char. If they are not equal check for count of A and B. Then add value that is greater because we need to finish max value first.

If they are remaining chars add it to the end of result. We are guaranteed that we have answer always.

