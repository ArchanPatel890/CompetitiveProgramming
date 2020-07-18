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
#include <cmath>

using namespace std;

class Solution {
public:
    double eps = 1e-6;

    bool judgePoint24(vector<int>& nums) {
        int n = nums.size();
        vector<double>nums_double(n);
        for (int i = 0; i < n; ++i) {
            nums_double[i] = (double)nums[i];
        }

        return judgePoint24(nums_double);
    }

    bool judgePoint24(vector<double>& nums) {
        int n = nums.size();
        if (nums.size() == 1) {
            return fabs(nums[0] - 24.0) < eps;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                double a = nums[i];
                double b = nums[j];
                nums.erase(nums.begin() + j);
                nums.erase(nums.begin() + i-1);
                vector<double> ops = { a + b, a - b, b - a, a * b, a / b, b / a };

                for (double res : ops) {
                    nums.push_back(res);
                    if (judgePoint24(nums)) {
                        return true;
                    }
                    nums.erase(nums.end() - 1);
                }
                nums.insert(nums.begin()+j, b);
                nums.insert(nums.begin()+i, a);
            }
        }

        return false;
    }
};
