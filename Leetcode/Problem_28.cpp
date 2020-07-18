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
    int strStr(string haystack, string needle) {
        
        if (haystack.length() == 0 && needle.length() == 0) return 0;
        
        for (int i=0; haystack.length()-i >= needle.length(); i++) {
            int j;
            for (j=0; j < needle.length(); j++) {
                if (needle[j] != haystack[i+j]) {
                    break;
                }
            }
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }
};
