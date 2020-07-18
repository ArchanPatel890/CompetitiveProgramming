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
    /**
     * We are given a list of words.
     *  The words are guaranteed to be unique
     *  The letters are all lowercase
     * @param words A list of strings that are words.
     * @return All words that are substrings of any other word in the list of words.
     */
    vector<string> stringMatching(vector<string>& words) {
        return stringMatchingBruteForce(words);
    }

    /**
     * Uses a brute force comparison of strings. 
     * O (k^2 n^2), k = max length of the words ** time complexity not exact.
     * 
     * The c++ find can be optimized to used KMP or another linear time string
     * search algorithm to achieve better asymptotic complexity.
     * O (kn^2)
     */
    vector<string> stringMatchingBruteForce(vector<string>& words) {
        // First sort the words by length
        sort(words.begin(), words.end(), []
            (const string& first, const string& second){
                return first.size() < second.size();
            });
        
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            for (int j = i + 1; j < n; ++j) {
                if (words[j].find(word) != string::npos) {
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }

    /**
     * We can build a suffix tree of all of the words to find substrings in linear time 
     * in the sum total length of all of the strings. O(kn), k = max length of word
     *  We can build the tree with Ukkonen's Algorithm in O(kn) and search the tree for subsets 
     *  in O(k) per word.
     */
    vector<string> stringMatchingSuffixTree(vector<string>& words) {
        vector<string> ans;
        return ans;
    }
};