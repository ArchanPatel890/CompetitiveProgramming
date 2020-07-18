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
    int total_weight = 0;
    vector<int> weights;

    Solution(vector<int>& w) {
        int n = w.size();
        int total = 0;
        for (int weight : w) {
            total += weight;
        }
        total_weight = total;

        vector<int> p(n);
        int cdf = 0;
        for (int i = 0; i < n; ++i) {
            cdf += w[i];
            p[i] = cdf;
        }

        weights = p;
    }

    int binarySearch(float target, vector<int> w, int left, int right) {
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (w[mid] == target) {
                return mid;
            }
            else if (w[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

    int pickIndex() {
        int sample = rand() % total_weight;
        int n = weights.size();
        int idx = min(n-1, binarySearch(sample, weights, 0, n-1));
        return idx;
    }
};
