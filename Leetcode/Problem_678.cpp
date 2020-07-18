#include <iostream>  
#include <iomanip>
#include <fstream>
#include <sstream>
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
    bool checkValidString(string s) {
        return checkForward(s) && checkReverse(s);
    }

    bool checkForward(string s) {
        int n = s.size();
        int starCnt = 0;
        int net = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                --net;
            }
            else if (s[i] == ')') {
                ++net;
            }
            else if (s[i] == '*') {
                ++starCnt;
            }
            if (net > 0) {
                if (starCnt < net) {
                    return false;
                }
                else {
                    starCnt -= net;
                    net = 0;
                }
            }
        }

        return true;
    }

    bool checkReverse(string s) {
        int n = s.size();
        int starCnt = 0;
        int net = 0;
        for (int i = n-1; i >= 0; --i) {
            if (s[i] == ')') {
                --net;
            }
            else if (s[i] == '(') {
                ++net;
            }
            else if (s[i] == '*') {
                ++starCnt;
            }
            if (net > 0) {
                if (starCnt < net) {
                    return false;
                }
                else {
                    starCnt -= net;
                    net = 0;
                }
            }
        }

        return true;
    }
};
