def solve(nums, N, K):
    curr = K
    count = 0
    for i in range(0, N):
        if nums[i] == curr:
            curr -= 1
        else:
            curr = K
            if nums[i] == curr:
                curr -= 1
        if curr == 0:
            count += 1
            curr = K
    return count


num_test_cases = int(input())
for case in range(num_test_cases):
    N, K = list(map(int, input().split()))
    nums = list(map(int, input().split()))
    ans = solve(nums, N, K)
    print("Case #{}: {}".format(case+1, ans))