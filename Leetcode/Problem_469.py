from typing import List

def is_convex_polygon(points: List):
    n = len(points)
    
    angle_left = False
    angle_right = False
    for i in range(0, n):
        a = i 
        b = (i + 1) % n
        c = (i + 2) % n
        
        if cross_product_z(
            points[a][0], points[a][1], 
            points[b][0], points[b][1], 
            points[c][0], points[c][1]) >= 0:
            angle_left = True
        else:
            angle_right = True

        if angle_right and angle_left:
            return False
    
    return True

def cross_product_z(ax, ay, bx, by, cx, cy):
    ab_x = ax - by
    ab_y = ay - by
    bc_x = bx - cy
    bc_y = by - cy

    cross_product = (ab_x * bc_y) - (ab_y * bc_x)
    return cross_product

test_cases = [
    [[0,0],[0,1],[1,1],[1,0]],              # True, is convex
    [[0,0],[0,10],[10,10],[10,0],[5,5]]     # False, not
]
for i in range(0, len(test_cases)):
    print("Test Case: {}".format(test_cases[i]))
    print("Answer: {}".format(is_convex_polygon(test_cases[i])))

