palp [] = True
palp [x] = True
palp (x:xs)
    | x == last xs = palp (init xs)
    | otherwise  = False