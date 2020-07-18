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
    int numTrees(int n) {
        int* memo = new int[n+1];
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; ++i) {
            memo[i] = 0;
            for (int j = 0; j < i/2; ++j) {
                cout << "i: " << i << " j: " << j << endl;
                memo[i] += 2 * memo[j] * memo[i-j-1];
            }
            if (i & 1) {
                memo[i] += memo[i/2] * memo[i/2];
            }
        }

        return memo[n];
    }

    /**
     * The number of unique binary trees can be obtained via the Catalan numbers.
     */
    int numTreesCatalan(int n) {
        if (n < 0) {
            return -1;
        }
        // Memo the factorial
        int* fact = new int[n+1];
        fact[0] = 1;
        fact[1] = 1;

        for (int i = 2; i <= n; ++i) {
            fact[i] = i * fact[i-1];
        }
        
        return 0;
    }
};