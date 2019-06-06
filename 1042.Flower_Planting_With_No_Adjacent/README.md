# 1042. Flower Planting With No Adjacent

You have N gardens, labelled 1 to N.  In each garden, you want to plant one of 4 types of flowers.

paths[i] = [x, y] describes the existence of a bidirectional path from garden x to garden y.

Also, there is no garden that has more than 3 paths coming into or leaving it.

Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.

Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)-th garden.  The flower types are denoted 1, 2, 3, or 4.  It is guaranteed an answer exists.

## How to solve this problem?

We have set of gardens and 4 types of flowers that we need to place so no adjacent gardens have the same flower type. This means that everytime when putting a new flower we need to check if its fit with its neighbor gardens. Lets consider a simple example

    Input: N = 3, paths = [[1,2],[2,3],[3,1]]
    Output: [1,2,3]

           1
          / \     
        2  -  3

    In this case our gardens have to have all different flower types. Lets change this example a little bit.

           1
          / \     
        2     3
    
    Output: [1, 2, 2]

    First we put type 1 into garden 1. Then for 2 garden type 1 violates the rule so we go type 2. For 3 garden we check type 1 which is also not an option. So we will then choose 2 and check if it is ok. If its ok then type 2 will be selected. 
