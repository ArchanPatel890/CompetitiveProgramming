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
    int numberOfSteps (int num) {
        int steps = 0;
        while(num) {
            if (num & 1) {
                num /= 2;
            }
            else {
                --num;
            }
            ++steps;
        }
        
        return steps;
    }
};
