def get_hours_for_fair_team(case_num):
    n, p = list(map(int, input().split()))
    students = list(map(int, input().split()))
    students.sort()
    summed = students.copy()

    for i in range(1, n):
        summed[i] += summed[i-1]
    summed.insert(0, 0)

    min_hours = float('inf')
    for s_i in range(p - 1, n):
        hours = students[s_i] * p - (summed[s_i + 1] - summed[s_i - p + 1])

        if hours < min_hours:
            min_hours = hours

    print("Case #{}: {}".format(case_num, min_hours))


num_test_cases = int(input())
for case in range(num_test_cases):
    get_hours_for_fair_team(case + 1)
