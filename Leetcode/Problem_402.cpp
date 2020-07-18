#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
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
     * Remove k digits from num (represented as a string) to make the smallest possible number.
     * @param num is the num e.g. "1432219"
     * @param k the number of digits to remove.
     */
    string removeKdigits(string num, int k) {
        int prev = 0;
        int n = num.size();
        if (n == k) return "0";
        if (k == 0) return num;

        deque<char> digits;
        digits.push_back(num[0]);
        for (int i = 1; i < n; ++i) {
            // Delete a digit that is greater than a following digit
            while (!digits.empty() && digits.back() > num[i] && k > 0) {
                digits.pop_back();
                --k;
            }
            digits.push_back(num[i]);
        }
        
        // Remove any remaining digits.
        for (int i = 0; i < k; ++i) 
            digits.pop_back();
        
        // Remove leading 0s
        while (digits.front() == '0')
            digits.pop_front();
        
        stringstream ss;
        while (!digits.empty()) {
            ss << digits.front();
            digits.pop_front();
        }
        string output = ss.str();
        return output.empty() ? "0" : output;
    }
};