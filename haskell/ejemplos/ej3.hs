mcd :: Integer -> Integer -> Integer
mcd a b | b > a = mcd b a
        | b == 0 = a
        | otherwise = mcd b (mod a b)

f b = mcd 350 (5*b^183 + 49)
