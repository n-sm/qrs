fact0 :: Integer -> Integer
fact0 n = if n == 0 then 1 else factorial (n - 1) * n

fact1 :: Integer -> Integer
fact1 n | n == 0 = 1
        | otherwise = n * fact( n -1 )
fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n-1)
