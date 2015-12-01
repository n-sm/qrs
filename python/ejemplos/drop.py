def drop(n, elts):
    while n > 0 and elts:
        n = n - 1
        elts = elts[1:]
    return elts
    
