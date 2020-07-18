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
    int minCostToMoveChips(vector<int>& chips) {
        int n = chips.size();
        int oddchips = 0;
        for (auto pos: chips) {
            if (pos & 1)
                ++oddchips;
        }
        
        int evenchips = n - oddchips;
        return oddchips > evenchips ? evenchips : oddchips;
    }
};
