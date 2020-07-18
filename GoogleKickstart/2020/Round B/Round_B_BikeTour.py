def solve(heights):
    peaks = 0
    i = 1
    while i < len(heights)-1:
        if heights[i] > heights[i-1] and heights[i] > heights[i+1]:
            peaks += 1
            i += 1
        i += 1
    return peaks


num_test_cases = int(input())
for case in range(num_test_cases):
    N = int(input())
    heights = list(map(int, list(input().split())))
    ans = solve(heights)
    print("Case #{}: {}".format(case+1, ans))
