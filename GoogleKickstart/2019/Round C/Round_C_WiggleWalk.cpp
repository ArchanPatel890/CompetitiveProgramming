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

string pairToString(int a, int b) {
    return to_string(a) + "," + to_string(b);
}


void travelDirection(char dir, unordered_set<string> visited, int& s_r, int& s_c) {
    do
    {
        switch (dir)
        {
            case 'N':
                --s_r;
                break;
            case 'S':
                ++s_r;
                break;
            case 'E':
                ++s_c;
                break;
            case 'W':
                --s_c;
                break;
            default:
                break;
        }
    } while (visited.find(pairToString(s_r, s_c)) != visited.end());
}

tuple<int, int> solve(int r, int c, int s_r, int s_c, string directions) {
    unordered_set<string> visited;

    visited.insert(pairToString(s_r, s_c));
    for (char const &c: directions) {
        travelDirection(c, visited, s_r, s_c);
        visited.insert(pairToString(s_r, s_c));
    }

    return make_tuple(s_r, s_c);
}


int main() {
    //freopen("Test_WiggleWalk.txt","r",stdin);
    int T;
    cin >> T;   
    for (int i = 1; i <= T; ++i) {
        // Get the input
        int N, R, C, S_r, S_c;
        cin >> N >> R >> C >> S_r >> S_c;
        --S_r;
        --S_c;
        string directions;
        getline(cin >> ws, directions);
        
        tie(S_r, S_c) = solve(R, C, S_r, S_c, directions);
        ++S_r;
        ++S_c;
        printf("Case #%d: %d %d\n", i, S_r, S_c);
    }

    return 0;
}