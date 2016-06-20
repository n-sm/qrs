mcd :: Integer -> Integer -> Integer
mcd a b | b > a = mcd b a
        | b == 0 = a
        | otherwise = mcd b (mod a b)
