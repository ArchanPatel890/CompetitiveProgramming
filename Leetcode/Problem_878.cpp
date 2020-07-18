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
    int MOD = 1000000007;
    int nthMagicalNumber(int N, int A, int B) {
        int lcm = A * B / gcd(A, B);
        long cntPerLcm = lcm / A + lcm / B - 1;
        long cntLcm = N / cntPerLcm;
        long remain = N % cntPerLcm;
        
        double nearest = remain / (1./A + 1./B);
        int remainIdx = (int)min(ceil(nearest / A) * A, ceil(nearest / B) * B);
        return (int)((cntLcm * lcm + remainIdx) % MOD);
    }

    int gcd (int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
};
