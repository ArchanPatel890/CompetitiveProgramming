def get_prob_memo(w, h):
    memo = [[0 for i in range(w+1)] for j in range(h+1)]
    memo[1][1] = 1

    for i in range(1, h+1):
        for j in range(1, w+1):
            if i != h:
                memo[i][j] += 0.5 * memo[i][j-1]
            else:
                memo[i][j] += memo[i][j-1]
            if j != w:
                memo[i][j] += 0.5 * memo[i-1][j]
            else:
                memo[i][j] += memo[i - 1][j]

    return memo


def solve(width, height, L, U, R, D):
    path_odds = get_prob_memo(width, height)
    p_hole = 0
    # Calculate Upper horizontal Edge
    for i in range(L, R+1):
        if i != width:
            p_hole += path_odds[U-1][i] * 0.5
        else:
            p_hole += path_odds[U-1][i]
    # Calculate Left Vertical Edge
    for i in range(U, D+1):
        if i != height:
            p_hole += path_odds[i][L-1] * 0.5
        else:
            p_hole += path_odds[i][L-1]
    return 1 - p_hole


num_test_cases = int(input())
for case in range(num_test_cases):
    W, H, L, U, R, D = list(map(int, list(input().split())))
    ans = solve(W, H, L, U, R, D)
    print("Case #{}: {}".format(case+1, ans))
