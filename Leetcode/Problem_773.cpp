#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& b) {
        string target="123450",
        begin=to_string(b[0][0])+to_string(b[0][1])+to_string(b[0][2])
             +to_string(b[1][0])+to_string(b[1][1])+to_string(b[1][2]);
        vector<vector<int>> nextMoves{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_set<string> visited{begin};
        queue<string> q; q.push(begin);
        for (int depth=0; !q.empty(); ++depth){
            int size=(int)q.size();
            for (int i=0; i<size; ++i){
                auto curr=q.front(); q.pop();
                if (curr==target) return depth;
                int zero=(int)curr.find("0");
                for (auto next: nextMoves[zero]){
                    auto candidate=curr;
                    swap(candidate[zero],candidate[next]);
                    if (visited.find(candidate)==visited.end()){
                        visited.insert(candidate);
                        q.push(candidate);
                    }
                }
            }
        }
        return -1;
    }
};
