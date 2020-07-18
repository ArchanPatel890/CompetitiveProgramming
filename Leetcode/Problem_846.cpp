#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        multiset<int> tb;
        
        for (auto & a : hand)
            tb.insert(a);
        
        while (tb.size() > 0) {
            int st = *tb.begin();
            
            for (int i = st; i < st + W; ++i) {
                if (tb.count(i) == 0)
                    return false;
                
                tb.erase(tb.find(i));
            }
        }
        
        return true;
    }
};
