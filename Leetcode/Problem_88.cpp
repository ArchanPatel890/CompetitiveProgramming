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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m-1;
        int second = n-1;
        for (int i = m + n - 1; i >= 0; i--) {
            if (second >= 0 && first >= 0) {
                if (nums1[first] > nums2[second]) {
                    nums1[i] = nums1[first];
                    first--;
                }
                else {
                    nums1[i] = nums2[second];
                    second--;
                }
            }
            else if (second >= 0) {
                nums1[i] = nums2[second];
                second--;
            }
        }
    }
};