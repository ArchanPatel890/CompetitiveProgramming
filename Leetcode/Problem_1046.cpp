#include <iostream>  
#include <iomanip>
#include <fstream>
#include <cmath>
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
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if (n == 0)
            return 0;

        make_heap(stones.begin(), stones.end());
        int remaining = 0;
        while(stones.size() >= 2) {
            int one = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int two = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            stones.push_back(abs(one-two));
            push_heap(stones.begin(), stones.end());
        }

        return stones.front();
    }
};