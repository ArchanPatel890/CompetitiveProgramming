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
    double myPow(double x, int n) {
        double ans = 1;
        long absN = abs((long)n);
        while (absN > 0) {
            if (absN & 1) ans *= x;
            absN >>= 1;
            x *= x;
        }
        return n < 0 ?  1/ans : ans;
    }
};