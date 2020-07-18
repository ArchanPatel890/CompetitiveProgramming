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
     * Copys all elements to the next available slot in the array.
     * Replaces all instances of @param val in the beginning of the
     * array.
     */
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())  {
            return 0;
        }

        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[idx] = nums[i];
                ++idx;
            }
        }

        return idx;
    }


    /**
     * Avoids all elements in the array by swaping all instances of 
     * @param val with the end of the array. The result puts all
     * instances of @param val at the end.
     */
    int removeElementRare(vector<int>& nums, int val) {
        if (nums.empty())  {
            return 0;
        }

        int idx = 0;
        for (int i = nums.size(); i > idx;) {
            if (nums[i] == val) {
                nums[idx] = nums[i-1];
                --i;
            } else {
                ++idx;
            }
        }

        return idx;
    }
};