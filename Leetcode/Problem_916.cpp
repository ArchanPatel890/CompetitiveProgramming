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
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char, int> char_count;
        size_t bSize = B.size();
        for (int i = 0; i < bSize; ++i) {
            auto word_count = count_chars(B[i]);
            for (auto it = word_count.begin(); it != word_count.end(); ++it) {
                char_count[it->first] = max(char_count[it->first], word_count[it->first]);
            }
        }

        size_t aSize = A.size();
        vector<string> ans;
        for (int i = 0; i < aSize; ++i) {
            auto word_count = count_chars(A[i]);
            bool print = true;
            for (auto it = char_count.begin(); it != char_count.end(); ++it) {
                if (word_count[it->first] < it->second) {
                    print = false;
                    break;
                }
            }
            if (print) {
                ans.push_back(A[i]);
            }
        }

        return ans;
    }

    unordered_map<char, int> count_chars(string s) {
        unordered_map<char, int> word_count;
        int len = s.size();
        for (int j = 0; j < len; ++j) {
            word_count[s[j]]++;
        };
        return word_count;
    }
};
