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
    string longestPalindrome(string s) {
        if(s.size() <= 1)return s;
        int curLen = 0, index = -1;
        bool type = true;
        for(int i = 0; i < s.size() - 1; i++){
            int len = lenOfPalindromic(s, i, i+1);
#define CMP(b) {curLen=len;index=i;type=b;}
            if(curLen < len)CMP(true)
            if(i < s.size() - 2){
                len = lenOfPalindromic(s, i, i+2);
                if(curLen < len)CMP(false)
            }
        }
        if(curLen == 0)return s.substr(0, 1);
        return type? s.substr(index - curLen/2 + 1, curLen):s.substr(index-(curLen-1)/2 + 1, curLen);
    }
    
    int lenOfPalindromic(string& str, int l, int r){
        int ret = 0;
        bool flag = (l == r-1);
        while(l >= 0 && r < str.size() && str[l--] == str[r++])ret++;
        return ret*2+(flag? 0 : 1);
    }
};