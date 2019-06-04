# 1052. Grumpy Bookstore Owner

Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

## How to solve this problem?

This problem can interpreted as "Find subarray such that sum of customers at grumpy moment is max".

So we need to find such subarray. We can surely return sum of values when not grumpy. So lets find subarray of size X where sum is max.

Basically, we have window of size X where value is max.

        customers = [1,0,1,2,1,{1,7,5}]
        
        grumpy =    [0,1,0,1,0,{1,0,1}] 
                     0 1 2 3 4 5 6 7
        X = 3

So we will set window of size X then will move it steadily as we iterate through the array of customers.

        customers = [*1,0,1*,2,1,1,7,5]
        
        grumpy =    [*0,1,0*,1,0,1,0,1] 

        window = 0
        -------------------------------
        customers = [1,*0,1,2*,1,1,7,5]
        
        grumpy =    [0,*1,0,1*,0,1,0,1] 

        window = 2
        -------------------------------
        customers = [1,0,*1,2,1*,1,7,5]
        
        grumpy =    [0,1,*0,1,0*,1,0,1] 

        window = 2
        -------------------------------
        customers = [1,0,1,*2,1,1*,7,5]
        
        grumpy =    [0,1,0,*1,0,1*,0,1] 

        window = 3
        -------------------------------
        customers = [1,0,1,2,*1,1,7*,5]
        
        grumpy =    [0,1,0,1,*0,1,0*,1] 

        window = 1
        -------------------------------
        customers = [1,0,1,2,1,*1,7,5*]
        
        grumpy =    [0,1,0,1,0,*1,0,1*] 

        window = 6

Max window value is *6*.


