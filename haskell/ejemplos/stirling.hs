stirling n k | n < k  = 0
             | n == k = 1
             | k == 0 = 0
             | k == 1 = 1
             | k == 2 = 2^(n-1) -1
             | otherwise = k * stirling (n-1) k +
                           stirling (n-1) (k-1)

-- ej.
-- map (\n -> stirling n 4) [0..9]
equivs n = sum ( map (\k -> stirling n k) [1..n])
