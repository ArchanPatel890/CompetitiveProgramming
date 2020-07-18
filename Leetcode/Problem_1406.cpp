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

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (n == 0) {
            return false;
        }

        vector<bool> visited(n);
        return canReach(arr, start, visited);
    }

    bool canReach(vector<int>& arr, int curr, vector<bool>& visited) {
        if (curr >= 0 && curr < arr.size() && !visited[curr]) {
            visited[curr] = true;
            return 
                arr[curr] == 0 
                || canReach(arr, curr + arr[curr], visited)
                || canReach(arr, curr - arr[curr], visited);
        }
        return false;
    }
};