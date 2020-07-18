#include <iostream>  
#include <iomanip>
#include <sstream>
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
    string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i] - '0' : 0;
            --i;
            c += j >= 0 ? b[j] - '0' : 0;
            --j;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};