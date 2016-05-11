esPositivo x = x > 0

ylog True True = True
ylog p q = False


ylog' True p = True
ylog' False p = False

ylog'' True True = True
ylog'' _ _ = False


f n1 n2 n3 | n2 < 10 = n1
           | otherwise = n1 + n3

nand p q = not (ylog p q)


nand' True True = False
nand' p q = True

nor False False = True
nor p q = False

--root a b c | b^2 - 4*a*c < 0 = 
--           | otherwise = (((-b) + sqrt(b^2-4*a*c))/2*a)

root a b c  = (((-b) + sqrt(b^2-4*a*c))/2*a)

--root' a b c  = (((-b) + sqrt(b^2-4*a*c))/2*a)

esPitagorica a b c = a^2 + b^2 == c^2

esPitagorica' a b c = sqrt(a^2 + b^2) == c

doble :: Num a => a -> a
doble x = x + x

crearPar :: a -> b -> (a, b)
crearPar a b = (a, b)

invertir :: (a, b) -> (b, a)
invertir par = (snd par, fst par)

distancia :: (Float, Float) -> (Float, Float) -> Float
distancia x y = sqrt( (fst x - fst y) ^ 2 + (snd x - snd y) ^ 2)

