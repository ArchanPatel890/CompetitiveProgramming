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

int solve(int N, int K, int A[], int P[]) {
    return 0;
}

int main() {
    freopen("Test_CatchSome.txt","r",stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N, K;
        auto A = new int[N];
        auto P = new int[N];
        cin >> N >> K;
        for (int i = 0; i < N; ++i) {
			cin >> A[i];    
		}
        for (int i = 0; i < N; ++i) {
			cin >> P[i];
		}
        
        int ans = solve(N, K, A, P);
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}