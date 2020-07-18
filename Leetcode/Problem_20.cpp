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
    bool isValid(string s) {
        if (s.empty())
            return true;
        
        stack<char> mystack; 
        for (char c : s) {
            switch(c){
                case '(': case '{': case '[':
                    mystack.push(c);
                    break;
                case ')':
                    if (!checkChar(mystack, '('))
                        return false;
                    break;
                case '}':
                    if (!checkChar(mystack, '{'))
                        return false;
                    break;
                case ']':
                    if (!checkChar(mystack, '['))
                        return false;
                    break;
                default:
                    return false;
            }
        }

        if (mystack.size())
            return false;
        return true;
    }

    bool checkChar(stack<char>& stack, char c) {
        if (!stack.size() || stack.top() != c)
            return false;
        stack.pop();
        return true;
    }
};