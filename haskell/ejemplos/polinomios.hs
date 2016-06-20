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

modu :: Compl -> Float
modu (a, b) = sqrt(a*a + b*b)

inv :: Compl -> Compl
inv z@(a, b) = (a/m2, -b/m2)
  where m2 = a*a + b*b
