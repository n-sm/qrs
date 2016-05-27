restoEnN :: Integer -> Integer -> Integer
restoEnN a b | a < b = a
             | otherwise = restoEnN (a-b) b

reductor :: Integer -> Integer -> Integer
reductor a b | b == 1 = 0
             | a < b = a
             | a > b*b = reductor a  (b*b)
             | otherwise = a - b

resto :: Integer -> Integer -> Integer
resto a b  | a == b = 0
           | a < b = a
           | b == 1 = 0
           | otherwise = resto (reductor a b) b


check a b = mod a b - resto a b

redu  :: Integer -> Integer -> Integer -> Integer
redu a d d' | d == 1 = 0
            | a < d = a
            | a < d*d = redu (a - d) d d
            | a < d' = redu (a - d*d) d d
            | a < d' * d' = redu (a - d') d d'
            | otherwise = redu (a - d'*d') d (d'*d') 

red a b = redu a b b
