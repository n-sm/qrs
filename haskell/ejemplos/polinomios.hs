type Poli =  [Integer]
type Compl = (Float, Float)

f = [0,2,2,1,3]
g = [1,2,0,3]

suma :: Poli -> Poli -> Poli
suma [] p = p
suma p [] = p
suma (x:xs) (y:ys) = x + y : suma xs  ys


prodes :: Integer -> Poli -> Poli
prodes 0 _ = []
prodes n [] = []
prodes n (p:ps) = n*p : prodes n ps

prod :: Poli -> Poli -> Poli
prod [] _ = []
prod (x:xs) p = suma (prodes x p) (0 : prod xs p)

sumac :: Compl -> Compl -> Compl
sumac (a, b) (c, d) = (a+b, c+d)

prodc :: Compl -> Compl -> Compl
prodc (a, b) (c, d) = (a*c - b*d, a*d+c*b)

moduc :: Compl -> Float
moduc (a, b) = sqrt(a*a + b*b)

invc :: Compl -> Compl
invc z@(a, b) = (a/m2, -b/m2)
  where m2 = a*a + b*b

mod2pi :: Float -> Float
mod2pi a
 | a < 0 = mod2pi (a+2*pi) 
 | a < 2*pi = a
 | otherwise = mod2pi (a - 2*pi)
 
arg :: Compl -> Float
arg (a, b)
   | a >= 0 && b /= 0 = mod2pi (asin (b / moduc (a, b)))
   | a <= 0 && b /= 0 = pi - asin (b / moduc (a, b))


enpi :: Float -> Float
enpi a = a/pi

expc :: Compl -> Float -> Compl
expc z@(a, b) n = prodc ((moduc z) **n, 0)  (cos alpha , sin alpha)
  where alpha = mod2pi (n * arg z)
