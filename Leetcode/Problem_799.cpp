#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row;
        row.push_back(0);
        row.push_back(poured);
        row.push_back(0);
        for (int i = 1; i <= query_row; ++i) {
            for (int j = row.size()-1; j > 0; --j) {
                row[j] = 0.5 * fmax(0, row[j]-1) + 0.5 * fmax(0, row[j-1]-1);
            }
            row.push_back(0);
        }

        return fmin(1.0, row[query_glass+1]);
    }
};
