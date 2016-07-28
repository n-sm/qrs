tablita :: Integer -> Integer -> [Integer]
tablita modu 1 = [0..modu-1]
tablita modu pot = map (\x -> mod x modu) $ multLst [0..modu-1] $ tablita modu  $ pot - 1 

multLst :: [Integer] -> [Integer] -> [Integer]
multLst (x:xs) (y:ys) = x*y : multLst xs ys
multLst _ _ = []

tablitaPotenciasAux :: Integer -> Integer -> Integer -> [Integer]
tablitaPotenciasAux n pot modu =
  mod (n^pot) modu : tablitaPotenciasAux n (pot+1) modu

tablitaPotencias :: Integer -> Integer -> [Integer]
tablitaPotencias n modu =
  sinRep $ tablitaPotenciasAux n 1 modu

sinRepAux :: [Integer] -> [Integer] -> [Integer]
sinRepAux laux [] = laux
sinRepAux laux (x:xs)
  | elem x laux = laux
  | otherwise = sinRepAux (x:laux)  xs

sinRep :: [Integer] -> [Integer]
sinRep l = reverse $ sinRepAux [] l
