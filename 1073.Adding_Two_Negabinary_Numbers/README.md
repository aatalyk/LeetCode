# 1073. Adding Two Negabinary Numbers

Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zeros.

## How to solve the problem?

We can use the solution for Base2 as a base for this problem. So particularly we add two digits from both of arrays and use Base2. So lets solve the problem for Base2.

> arr1 = [1, 0, 1] = 5

> arr2 = [1, 1] = 3 

> expected = [1,0,0,0] = 8

> res = [1,0,0,0]

Lets start iteration from the end of arrays and keep carry for remainder from Base2.

1)

carry = 0

carry = 1 + 1 + carry = 1 + 1 + 0 = 2 ~ 10

res <- carry & 1 = 0

carry = carry >> 1 ~ carry = 1

2)

carry = 1

carry = 0 + 1 + carry = 0 + 1 + 1 = 2 ~ 10

res <- carry & 1 = 0

carry = carry >> 1 ~ carry = 1

3)

carry = 1

carry = 1 + carry = 1 + 1 = 2 ~ 10

res <- carry & 1 = 0

carry = carry >> 1 ~ carry = 1

4)

Add left carry

carry = 1

## Lets consider following approach for Base-2

> arr1 = [1, 0, 1] = 5

1 * 2^2 - 0 * 2^1 + 1 * 2^0
        - 1 * 2^1 + 1 * 2^0

> arr2 = [1, 1] = -1

> expected = [1,0,0] = 4

> res = [1,0,0]



The main difference of Base-2 from Base2 is the fact that for every odd position of binary rep of number it uses -2.

So for every odd position change sign of carry.

1)

carry = 0

carry = 1 + 1 + carry = 1 + 1 + 0 = 2

res <- carry & 1 = 0

carry = -(carry >> 1) = -1
