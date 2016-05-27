tacharMultiplosDe :: Integer -> [Integer] -> [Integer]
tacharMultiplosDe _ [] = []
tacharMultiplosDe 0 l = l
tacharMultiplosDe n (x:xs)
    | mod x n == 0 = tacharMultiplosDe n xs
    | otherwise = x : tacharMultiplosDe n xs


tacharMultiplosDeHead :: [Integer] -> [Integer]
tacharMultiplosDeHead [] = []
tacharMultiplosDeHead (x:xs) = x : tacharMultiplosDe x xs

cribaDeEratostenes :: Integer -> [Integer] -> [Integer]
cribaDeEratostenes n (x:xs)
    | x <= floorSqrt n 1 = x : cribaDeEratostenes n
      (tacharMultiplosDeHead xs)
    | otherwise = x:xs

criba :: Integer -> [Integer]
criba n = cribaDeEratostenes n [1..n]

floorSqrt :: Integer -> Integer -> Integer
floorSqrt n i
    | i * i > n = i - 1
    | otherwise = floorSqrt n (i+1)
