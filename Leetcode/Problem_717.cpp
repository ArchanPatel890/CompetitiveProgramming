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
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while (i < n) {
            if (i == n-1 && !bits[i]) {
                return true;
            }
            if (bits[i]) {
                i += 2;
            }
            else {
                ++i;
            }
        }
        
        return false;
    }
};
