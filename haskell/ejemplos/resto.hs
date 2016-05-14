
restoEnN' :: Integer -> Integer -> Integer
restoEnN' a b | a < b = a
              | otherwise = restoEnN (a-b) b


reductor :: Integer -> Integer -> Integer
reductor a d
  | a < d = 0
  | d == 1 = a
  | a <= d*d = d
  | otherwise = reductor a (d*d)

reducir' :: Integer -> Integer -> Integer
reducir' a d
  | a - (reductor a d) < d = a - (reductor a d)
  | otherwise = reducir' (a - reductor a d) d
             

reducir :: Integer -> Integer -> Integer
reducir a d
  | redu < d = redu 
  | otherwise = reducir redu d
    where redu = a - reductor a d

test a d = ("Con mod:", mod a d, "Con reducir:", reducir a d)


restoEnN :: Integer -> Integer -> Integer
restoEnN a d | a < d = a
             | otherwise = restoEnN (a - reductor a d) d

main = putStr (show (restoEnN (199^9) 7))
