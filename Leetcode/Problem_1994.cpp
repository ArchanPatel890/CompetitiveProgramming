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
#include <set>

using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    set<int> get_prime_factors(int n, bool &ok) {
        ok = true;
        set<int> factors;
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) factors.insert(i);
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            if (cnt > 1) ok = false;
        }

        return factors;
    }

    bool is_divisible(int n, set<int>& factors) {
        bool ok = false;
        for (auto i : factors) {
            if (n % i == 0) {
                ok = true;
                break;
            }
        };

        return ok;
    }

    long long count_sets(vector<int>& nums, int start, set<int> curr_factors, unordered_map<int, set<int>>& factors, unordered_map<int, int>& dup) {
        int n = nums.size();
        long long cnt = 1;
        int num = nums[start];
        curr_factors.insert(factors[num].begin(), factors[num].end());
        
        for (int i = start+1; i < n; ++i) {
            if (!is_divisible(nums[i], curr_factors)) {
                cnt = (cnt % MOD + count_sets(nums, i, curr_factors, factors, dup) % MOD) % MOD;
            }
        }
        
        return (cnt * (dup[num] % MOD)) % MOD;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        set<int> distinct;
        vector<int> distinct_nums;
        unordered_map<int, set<int>> factors;
        unordered_map<int, int> dup;
        for (int n : nums) {
            if (!distinct.count(n)) {
                bool ok = true;
                factors[n] = get_prime_factors(n, ok);
                if (ok && n != 1) {
                    distinct_nums.push_back(n);
                }
                distinct.insert(n);
            }
            dup[n]++;
        }

        long long ans = 0;
        set<int> curr_factors;
        int cnt = distinct_nums.size();
        for (int i = 0; i < cnt; ++i) {
            ans = (ans + count_sets(distinct_nums, i, curr_factors, factors, dup) % MOD) % MOD;
        }

        long long pow = 1;
        int cnt1 = dup[1];
        for (int i = 0; i < cnt1; ++i) {
            pow = (pow * 2) % MOD;
        }
        
        ans = (pow % MOD * ans % MOD) % MOD;

        return ans;
    }
};