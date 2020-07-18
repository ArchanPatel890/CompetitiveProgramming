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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> edges;
        wordList.push_back(beginWord);
        
        int nWords = wordList.size();
        for (int i = 0; i < nWords; ++i) {
            vector<string> neighbors;
            for (int j = 0; j < nWords; ++j) {
                if (i != j && isNeighbor(wordList[i], wordList[j])) {
                    neighbors.push_back(wordList[j]);
                }
            }
            edges[wordList[i]] = neighbors;
        }

        unordered_set<string> visited;
        vector<string> path;
        vector<vector<string>> ans;
        path.push_back(beginWord);
        findAnswer(beginWord, endWord, edges, visited, path, ans);
        return ans;
    }

    void findAnswer(
        string curr,
        string endWord, 
        map<string, vector<string>>& graph, 
        unordered_set<string>& visited, 
        vector<string>& path,
        vector<vector<string>>& ans) {
        
        visited.insert(curr);
        for (auto v : graph[curr]) {
            if (visited.find(v) == visited.end()) {
                path.push_back(v);

                if (v == endWord) {
                    while (!ans.empty() && ans.back().size() > path.size()) {
                        ans.pop_back();
                    }
                    
                    if (ans.empty() || ans.back().size() == path.size()) {
                        ans.push_back(vector<string>(path));
                    }
                }
                
                findAnswer(v, endWord, graph, visited, path, ans);
                path.pop_back();
            }
        }
        visited.extract(curr);
    }


    bool isNeighbor(string u, string v) {
        int n = u.length();
        if (n != v.length()) {
            return false;
        }

        int diff = 0;
        for (int i = 0; i < n; ++i) {
            if (u[i] != v[i]) {
                ++diff;
            }
        }

        return diff == 1;
    }
};
