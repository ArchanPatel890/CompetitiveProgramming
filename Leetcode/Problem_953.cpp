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
    bool isAlienSorted(vector<string> &words, string order) {
        size_t indices[26]{};
        for (size_t i = 0; i < order.size(); ++i) {
            indices[order[i] - 'a'] = i;
        }
        return is_sorted(words.begin(), words.end(), [&indices](
                const string &w1,
                const string &w2
        ) {
            auto l1 = w1.size(), l2 = w2.size();
            for (auto i = 0; i < min(l1, l2); ++i) {
                auto c1 = w1[i], c2 = w2[i];
                if (c1 != c2) {
                    return indices[c1 - 'a'] < indices[c2 - 'a'];
                }
            }
            return l1 < l2;
        });
    }
};