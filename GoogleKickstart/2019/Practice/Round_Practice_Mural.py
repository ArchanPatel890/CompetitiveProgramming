def get_max_beauty(N, wall_scores):
    window_size = (N+1)//2
    window = sum(wall_scores[:window_size])
    max_score = window
    for i in range(0, N-window_size):
        window = window - wall_scores[i] + wall_scores[i+window_size]
        if window > max_score:
            max_score = window

    return max_score


num_test_cases = int(input())
for case in range(num_test_cases):
    sections = int(input())
    scores = list(map(int, list(input())))
    score = get_max_beauty(sections, scores)
    print("Case #{}: {}".format(case+1, score))



