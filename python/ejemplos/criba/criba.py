def algunoDivide(l, n):
    for i in l:
        if n % i == 0: return True
    return False

def criba(n):
    if n<2: return []
    res = [2]
    for i in range(3,n+1,2):
        if algunoDivide(res, i): continue
        res.append(i)
    return res
    
    
