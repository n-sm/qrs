mcd' :: Integer -> Integer -> Integer
mcd' a b | b > a = mcd' b a
         | b == 0 = a
         | otherwise = mcd' b (mod a b)

mcd :: Integer -> Integer -> Integer
mcd a 0 = a
mcd a b = mcd b (mod a b)
