-- Ejercicio 1

restoEnN :: Integer -> Integer -> Integer
restoEnN a b | a < b = a
             | otherwise = restoEnN (a-b) b

esMult :: Integer -> Integer -> Bool
esMult a b | a < 0 = esMult (-a) b
           | b < 0 = esMult a (-b)
           | otherwise = restoEnN b a == 0


-- Ejercicio 2

intercalar :: [a] -> [a] -> [a]
intercalar a b | length a < 2 = a ++ b
               | otherwise = head a : head b : intercalar (tail a) (tail b)

-- Ejercicio 3

quitarlos :: Integer -> [Integer] -> [Integer]
quitarlos x xs | xs == [] = xs
               | x == head xs = quitarlos x (tail xs)
               | otherwise = head xs : quitarlos x (tail xs)

-- Ejercicio 4
freqinit :: Integer ->  [Integer] -> Integer
freqinit i l | length l == 0 =  0
             | head l == i = 1 + freqinit i (tail l)
             | otherwise = 0
             


tailn n l | n == 0 = l
          | otherwise = tailn (n-1) (tail l)
            
comprimir :: [Integer] -> [(Integer, Integer)]
comprimir l | length l == 0 = []
            | otherwise = (head l, freqinit (head l ) l) : comprimir (tailn (freqinit (head l) l) l)
