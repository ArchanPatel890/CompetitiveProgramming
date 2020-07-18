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
private:
    static bool compareBuildingsPos(vector<int> a, vector<int> b) 
    { 
        return (a[0] < b[0]); 
    }

    static bool compareBuildingsHeight(vector<int> a, vector<int> b) {
        return (a[2] < b[2]);
    }

public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> ans;
        if (n == 0) {
            return ans;
        }
        sort(buildings.begin(), buildings.end(), compareBuildingsPos);

        priority_queue<vector<int>, vector<vector<int>>, function<bool(vector<int>, vector<int>)>> pq(compareBuildingsHeight);
        int curr = 0;
        int left = 0;
        pq.push(buildings[curr]);
        ++curr;
        while(curr < n) {
            while (curr < n && buildings[curr][0] == left) {
                pq.push(buildings[curr]);
                ++curr;
            }

            // Get the top building
            auto top = pq.top();
            if (ans.back()[1] != top[2]) {
                ans.push_back({ top[0], top[2] });
            }

            if (curr < n) {
                auto next = buildings[curr];
                left = next[0];
                while (left > top[1]) {
                    pq.pop();
                    if (!pq.empty()) {
                        auto next_top = pq.top();
                        if (top[1] < next_top[0]) {
                            ans.push_back({top[0], next_top[2]});
                        }
                        top = next_top;
                    }
                    else {
                        ans.push_back({top[1], 0});
                    }
                }
                pq.push(buildings[curr]);
            }
            else {
                while(!pq)
            }

        }   


        return ans;
    }

};