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
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();

        vector<int> size(n, 0);
        vector<int> parent(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        int count = n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) {
                    union_sets(i, j, size, parent, count);
                }
            }
        }

        return count;
    }

    int find_set(int v, vector<int>& parent) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v], parent);
    }

    void make_set(int v, vector<int>& size, vector<int>& parent) {
        parent[v] = v;
        size[v] = 1;
    }

    void union_sets(int a, int b, vector<int>& size, vector<int>& parent, int& count) {
        a = find_set(a, parent);
        b = find_set(b, parent);

        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            --count;
        }
    }
};
