#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int MOD = 1000000007;
    int numOfArrays(int n, int m, int k) {
        if (k > m) {
            return 0;
        }

        vector<vector<vector<long long>>> ways(n+1, vector<vector<long long>>(m+1, vector<long long>(k+1, 0)));
        for (int b = 1; b <= m; b++) {
                ways[1][b][1] = 1;
        }

        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= m; ++b) {
                for (int c = 1; c <= k; ++c) {
                    long long comb = 0;
                    
                    // Append a smaller or equal number than b to the end of the array
                    comb = (comb + b * ways[a-1][b][c]) % MOD;  

                    // Append b to the end of the array.
                    for (int i = 1; i < b; ++i) {
                        comb = (comb + ways[a-1][i][c-1]) % MOD;
                    }

                    ways[a][b][c] = (ways[a][b][c] + comb) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int j = 1; j <= m; j++) {
            ans = (ans + ways[n][j][k]) % MOD;
        }
        
        return ans;
    }
};
