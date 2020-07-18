#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Numbers of ways to climb n stairs if you can take either 1 or 2 steps up.
     * @param n the number of stairs to climb.
     * 
     * This DP problem boils down to finding the nth fibonacci number.
     */
    int climbStairs(int n) {
        if (n <= 0)  {
            return 1;
        }
        else if (n == 1) {
            return 1;
        }

        int* step = new int[n+1];
        step[0] = 1;
        step[1] = 1;
        for (int i = 2; i <= n; ++i) {
            step[i] = step[i-1] + step[i-2];
        }
        return step[n-1];
    }
};