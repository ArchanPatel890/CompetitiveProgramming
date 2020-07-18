#include <iostream>  
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length();
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            else {
                --right;
                ++left;
            }
        }
        return true;
    }
};
