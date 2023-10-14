def max_area(height):
    w = len(height) - 1
    l, r = 0, w
    res = min(height[l],height[r]) * w
    # [1 8 6 2 5 4 8 3 7]
    #. ^               ^
    while l < r:
        lh = height[l]
        rh = height[r]
        checkmax = min(lh,rh) * w
        if checkmax > res:
            res = checkmax
        w -= 1
        if lh < rh:
            l+=1
        else:
            r-= 1

    return res
