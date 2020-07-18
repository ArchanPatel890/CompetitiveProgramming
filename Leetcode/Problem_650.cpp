#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n <= 0) {
            return 0;
        }

        return minStepsRecursive(n);
    }
    
    // Find the prime factorization of n and sum it.
    int minStepsRecursive(int n) {
        if (n == 1) {
            return 0;
        }
        int i = 2;
        for (; i <= n; ++i) {
            if (n % i == 0) {
                break;
            }
        }
        return i + minStepsRecursive(n/i);
    }

    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};
