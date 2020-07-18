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

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n+1, 0);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i-1] * i;
        }

        vector<int> digits;
        for (int i = 1; i <= n; ++i) {
            digits.push_back(i);
        }
        
        stringstream ss;
        k = k - 1;
        for (int i = n; i > 0; i--) {
            int place = k / factorial[i-1];
            ss << digits[place];
            digits.erase(digits.begin() + place);
            k = k % factorial[i-1];
        }

        return ss.str();
    }
};
