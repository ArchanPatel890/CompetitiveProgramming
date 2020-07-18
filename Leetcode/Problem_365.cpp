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
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) {
            return false;
        }
        int divisor = gcd(x, y);
        if (!divisor) {
            if (z) {
                return false;
            }
            return true;
        }
        return z % divisor == 0;
    }

    int gcd (int a, int b) {
        if (b == 0)
            return a;
        else
            return gcd (b, a % b);
    }
};