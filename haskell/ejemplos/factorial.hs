factorial :: Integer -> Integer
factorial n = if n == 0 then 1 else factorial (n - 1) * n