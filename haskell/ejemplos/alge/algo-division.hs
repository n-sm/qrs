restoEnN :: Integer -> Integer -> Integer

restoEnN a d | a < d = a
             | otherwise = restoEnN (a - d) d

resto a d | a > 0 && d > 0 = restoEnN a d
          | otherwise = 0
            
cocienteEnN :: Integer -> Integer -> Integer

cocienteEnN a d | a < d = 0
                | otherwise = 1 + cocienteEnN (a - d) d



