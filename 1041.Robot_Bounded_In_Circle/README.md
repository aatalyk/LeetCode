# 1041. Robot Bounded In Circle

On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

## Solution

The problem requires us to find if there is cycle in the movement of robot. If robot moves only in one direction it will go infinitely towards that. If robot will come to its original position this means that there is no cycle. Other cases are that robot will move towards left or right in up and down fashion 


            __    __
        |__|  |__|  |__

So if robot after some number of steps is forcing initially to north then there is no cycle. We can find direction applying modulus of 4. 

```cpp
if (c == 'L') {
    dir = (dir + 1) % 4;
} else {
    dir = (dir + 3) % 4;
}
```

    0 N
    1 W
    2 S
    3 E



