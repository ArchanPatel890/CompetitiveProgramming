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
    int MOD = 1000000000 + 7;
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int t = target - A[i];
            count = (count + twoSum(A, t, i+1, n-1)) % MOD;
        }

        return count;
    }

    int twoSum(vector<int>& A, int target, int l, int r) {
        int count = 0;
        while (l < r) {
            int sum = A[l] + A[r];
            if (sum == target) {
                if (A[l] == A[r]) {
                    int f = 1;
                    while (l < r  && A[l] == A[l+1]) {
                        ++f;
                        ++l;
                    }
                    count = (count + f * (f-1) / 2) % MOD;
                }
                else {
                    int f = 1;
                    int s = 1;
                    while (l < r  && A[l] == A[l+1]) {
                        ++f;
                        ++l;
                    }
                    while (l < r && A[r] == A[r-1]) {
                        ++s;
                        --r;
                    }
                    ++l;
                    --r;
                    count = (count + f * s) % MOD;
                }
            }
            else if (sum < target) {
                ++l;
            }
            else {
                --r;
            }
        }

        return count;
    }
};
