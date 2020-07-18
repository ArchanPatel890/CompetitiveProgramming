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
    int myAtoi(string str) {
        if (hasLeadingNonNum(str) || hasNoDigit(str))
            return 0;
        
        if (!isDigitAfterSign(str))
            return 0;
        
        int sign = getSign(str);
        
        string numSub = getNumSub(str);
        
        long result = 0;
        for (char c : numSub)
        {
            result = result * 10 + c - '0';
            
            if (result * sign >= INT_MAX)
                return INT_MAX;
            else if (result * sign <= INT_MIN)
                return INT_MIN;
        }
        
        return static_cast<int>(result * sign);
    }
    
private:
    bool hasLeadingNonNum(string const& str)
    {
        for (char c : str)
        {
            if (!isdigit(c) && c != ' ' && c != '+' && c != '-')
                return true;
            
            if (isdigit(c))
                return false;
        }
        return false;
    }
    
    bool hasNoDigit(string const& str)
    {
        for (char c : str)
            if (isdigit(c))
                return false;
        
        return true;
    }
    
    bool isDigitAfterSign(string const& str)
    {
        int i = 0;
        for (; i < str.length(); i++)
        {
            if (isdigit(str[i]))
                return true;
            
            if (str[i] == '+' || str[i] == '-')
                break;
        }
        
        if (i < str.length() - 1)
            return isdigit(str[i + 1]);
        
        return false;
    }
    
    int getSign(string const& str)
    {
        for (char c : str)
        {
            if (isdigit(c) || c == '+')
                return 1;
            
            if (c == '-')
                return -1;
        }
        
        return 0;
    }
    
    string getNumSub(string const& str)
    {
        int st = 0;
        for (; st < str.length(); st++)
            if (isdigit(str[st]))
                break;
        
        int len = 0;
        while ((st + len) < str.length() && isdigit(str[st + len]))
            len++;
        
        return str.substr(st, len);
    }
};