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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        vector<int> ans;
        int carry = 0;
        int i = n-1;
        do {
            int sum = (i >= 0 ? A[i] : 0) + K % 10 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ans.push_back(digit);
            K /= 10;    
            --i;
        } while (K > 0 || carry || i >= 0);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
