def power_int(a, b):
    if b == 0:
        return 1
    if b == 1:
        return a
    if b % 2 == 0:
        return power_int(a * a, b / 2)
    else:
        return a * power_int(a * a, b / 2)


def get_parameter_array(N, x_1, y_1, C, D, E_1, E_2, F):
    A = [(x_1 + y_1) % F]
    E = E_1 + E_2
    for i in range(1, N):
        A_next = ((C+D) * A[i-1] + E) % F
        A.append(A_next)
    A.insert(0, 0)
    return A


def solve(A, N, k):
    power_sum = 0
    gp_sum = k
    for p in range(1, N+1):
        if p != 1:
            gp_sum += (pow(p, k+1) - 1) * pow(p-1, OUTPUT_MOD-2)
            gp_sum %= OUTPUT_MOD
        power_sum += gp_sum * A[p]
        power_sum %= OUTPUT_MOD
    return int(power_sum % OUTPUT_MOD)


OUTPUT_MOD = int(1e9 + 7)
num_test_cases = int(input())
for case in range(num_test_cases):
    N, K, x_1, y_1, C, D, E_1, E_2, F = map(int, input().split(" "))
    parameters = get_parameter_array(N, x_1, y_1, C, D, E_1, E_2, F)
    ans = solve(parameters, N, K)
    print("Case #{}: {}".format(case+1, ans))