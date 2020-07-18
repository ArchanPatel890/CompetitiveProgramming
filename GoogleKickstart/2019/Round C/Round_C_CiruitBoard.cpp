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
typedef long long ll;

int solve() {
    return 0;
}

int main() {
    freopen("Test_CircuitBoard.txt","r",stdin);
    int A[300][300];

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // Get the input
        int K, R, C;
        cin >> R >> C >> K;
        for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> A[i][j];
			}
		}
        
        
        int ans = solve();
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}