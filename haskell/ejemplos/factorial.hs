fact0 :: Integer -> Integer
fact0 n = if n == 0 then 1 else fact0 (n - 1) * n

fact1 :: Integer -> Integer
fact1 n | n == 0 = 1
        | otherwise = n * fact1( n -1 )
f :: Integer -> Integer
f 0 = 1
f n = n * f(n-1)
