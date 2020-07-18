#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
// #include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

const int MAX_SQUARE = 350;

int solve(int A[], int N) {
    int count = 0, currSum = 0;
    unordered_map<int, int> hashMap;
    hashMap.emplace(0, 1);
    auto squares = new int[MAX_SQUARE];
    for (int i = 0; i < MAX_SQUARE; ++i) {
        squares[i] = i*i;
    }

    for (int i = 0; i < N; ++i) {
        currSum += A[i];
        for (int j = 0; j < MAX_SQUARE; ++j) {
            int key = currSum - squares[j];
            if (hashMap.find(key) != hashMap.end()) {
                count += hashMap[key];
            }
        }
        if (hashMap.find(currSum) != hashMap.end())
            hashMap[currSum] = 1 + hashMap[currSum];
        else 
            hashMap[currSum] = 1;
    }

    return count;
}


int main() {
    //freopen("Test_Perfect_Subarray.txt","r",stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        auto A = new int[N];
        for (int i = 0; i < N; ++i) {
			cin >> A[i];    
		}

        int ans = solve(A, N);
        printf("Case #%d: %d\n", t, ans);
    }

    return 0;
}