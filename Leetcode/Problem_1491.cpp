#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        if (!n) {
            return 0.0;
        }
        double sum = salary[0];
        int min = salary[0];
        int max = salary[0];
        for (int i = 1; i < n; ++i) {
            min = fmin(salary[i], min);
            max = fmax(salary[i], max);
            sum += salary[i];
        }

        return (sum - min - max) / (n-2);
    }
};
