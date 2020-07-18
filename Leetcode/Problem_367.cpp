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
    bool isPerfectSquare(int num) {
        int i=1;
        while (num > 0) {
            num -= i;
            i +=2;
            if( !num ) return true;
        }
        return false;
    }
};
