def solve(movements, mod):
    dx = 0
    dy = 0
    coeff_stack = [1]
    i = 0
    while i < len(movements):
        c = movements[i]
        if c == 'N':
            dy -= coeff_stack[-1]
        elif c == 'S':
            dy += coeff_stack[-1]
        elif c == 'W':
            dx -= coeff_stack[-1]
        elif c == 'E':
            dx += coeff_stack[-1]
        elif c.isdigit():
            coeff_stack.append(coeff_stack[-1] * int(c) % mod)
        elif c == ')':
            coeff_stack.pop()
        i += 1
    return dx, dy


HEIGHT = 1e9
WIDTH = HEIGHT
num_test_cases = int(input())
for case in range(num_test_cases):
    movements = input()
    start = (1, 1)
    dx, dy = solve(movements, HEIGHT)
    x = int(start[0] + dx % HEIGHT)
    y = int(start[1] + dy % WIDTH)
    print("Case #{}: {} {}".format(case+1, x, y))
