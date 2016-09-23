data Arbol = Hoja Integer | Ramificacion Arbol Integer Arbol deriving Show
data Dir = Der | Izq deriving (Show, Eq)

h1 = Hoja 1
h2 = Hoja 2
a = Ramificacion (Ramificacion h1 0 h2) 1  (Ramificacion h1  0 h1)
esHoja :: Arbol -> Bool
esHoja (Hoja _) = True
esHoja _ = False

sumarNodos :: Arbol -> Integer
sumarNodos (Hoja n) = n
sumarNodos (Ramificacion a1 n a2) = sumarNodos a1 + n + sumarNodos a2

altura :: Arbol -> Integer
altura (Hoja _) = 1
altura (Ramificacion a1 _ a2) = 1 + max (altura a1) (altura a2)

pertenece :: Integer -> Arbol -> Bool
pertenece k (Hoja n) = n == k
pertenece k (Ramificacion a1 n a2) = k == n || pertenece k a1 || pertenece k a2

raiz :: Arbol -> Integer
raiz (Hoja n) = n
raiz (Ramificacion _ n _) = n

busqueda :: [Dir] -> Arbol -> Integer
busqueda [] a = raiz a
busqueda (Der:xs) (Ramificacion a1 _ a2) = busqueda xs a2
busqueda (Izq:xs) (Ramificacion a1 _ a2) = busqueda xs a1

