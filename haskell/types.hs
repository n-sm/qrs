type Racional = (Integer, Integer)

producto :: Racional -> Racional -> Racional
producto (a, b) (c, d) = (a*c,b*d)

igual :: Racional -> Racional -> Bool
igual (a, b) (c, d) =
  a*d == c*b


mayor :: Racional -> Racional -> Bool
mayor (a, b) (c, d)
  |  b*d > 0 = a*d > c*b
  | otherwise = a*d < c*b

potencia (a, b) n = (a^n, b^n)

-- ¿Como definir un nueo tipo?
-- ejemplo

data Dia = Lun | Mar | Mie | Jue | Vie | Sab | Dom deriving Show

esFinde :: Dia -> Bool
esFinde Sab = True
esFinde Dom = True
esFinde _ = False

diaHabil :: Dia -> Bool
diaHabil d = not (esFinde d)

algebra :: [Dia] -> [Dia]
algebra [] = []
algebra (Mie:xs) = Mie : algebra xs
algebra (_:xs) = algebra xs

semana = [Lun , Mar , Mie , Jue , Vie , Sab , Dom]


type Conj = [Integer]

incluido :: Integer -> Conj -> Bool
incluido e [] = False
incluido x (x:xs) = True
incluido e (x:xs)
  | e == x = True
  | otherwise = incluido e xs

union :: Conj -> Conj -> Conj
union [] l = l
union l [] = l
union (x:xs) l
  | elem x l = union xs l
  | otherwise = x: union xs l

intersec :: Conj -> Conj -> Conj
intersec [] l = []
intersec l [] = []
intersec xes@(x:xs) yes@(y:ys)
  | elem x yes && elem y xes = x:y:intersec xs ys
  | elem x yes = x:intersec xs ys
  | elem y xes = y:intersec xs ys
  | otherwise = intersec xs ys

 
