tieneDivisorEntre :: Integer -> Integer -> Integer -> Bool
tieneDivisorEntre n j k
    | j > k = False
    | mod n j == 0 = True
    | otherwise = tieneDivisorEntre n (j+1) k
    
floorSqrt :: Integer -> Integer -> Integer
floorSqrt n i
    | i * i > n = i - 1
    | otherwise = floorSqrt n (i+1)

esprimo :: Integer -> Bool
esprimo n = not (tieneDivisorEntre n 2 (floorSqrt n 1))
