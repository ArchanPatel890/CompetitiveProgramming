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
#include <cmath>

using namespace std;

class Solution {
public:
    int ALPHABET_SIZE = 26;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> count(ALPHABET_SIZE);
        for (char c : letters) {
            count[c - 'a']++;
        }

        return maxScoreWordsDFS(words, count, score, 0);
    }

    int maxScoreWordsDFS(vector<string>& words, vector<int>& count, vector<int>& score, int idx) {
        if (idx > words.size()) {
            return 0;
        }

        int skip = maxScoreWordsDFS(words, count, score, idx+1);
        vector<int> count_next(count.begin(), count.end());
        bool used = true;
        int word_score;
        for (auto c : words[idx]) {
            if (--count_next[c - 'a'] < 0) {
                used = false;
            }
            word_score += score[c - 'a'];
        }

        return max(skip, used ? word_score + maxScoreWordsDFS(words, count_next, score, idx+1) : 0);
    }
};
