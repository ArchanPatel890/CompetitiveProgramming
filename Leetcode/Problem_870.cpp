#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> nums;
        for (auto c : A) {
            nums.insert(c);
        }

        multiset<int>::iterator it;
        vector<int> ans;
        for (int i : B) {
            it = nums.upper_bound(i);
            auto ptr = it != nums.end() ? it : nums.begin();
            ans.push_back(*ptr);
            nums.erase(ptr);
        }

        return ans;
    }
};
