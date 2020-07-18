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
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string larger = (m > n) ? num1 : num2;
        string smaller = (m <= n) ? num1 : num2;
        int size = larger.size();
        int carry = 0;
        int i = larger.size() - 1;
        int j = smaller.size() - 1;
        stringstream ss;
        do {
            int sum = carry + (larger[i] - '0') + (j >= 0 ? (smaller[j] - '0') : 0);
            int digit = sum % 10;
            carry = sum / 10;
            ss << digit;
            --i;
            --j;
        } while (i >= 0);

        if (carry) {
            ss << carry;
        }

        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
