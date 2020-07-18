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
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> combination;
        combinationSum(target, 0, candidates, combination, ans);
        return ans;
    }
private:
    void combinationSum(int target, int begin, vector<int>& candidates, vector<int>& combination, vector<vector<int>>& ans) {
        if (!target) {
            ans.push_back(combination);
            return;
        }

        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            if(i && candidates[i] == candidates[i-1] && i > begin) 
                continue;
            combination.push_back(candidates[i]);
            combinationSum(target - candidates[i], i+1, candidates, combination, ans);
            combination.pop_back();
        }
    }
};