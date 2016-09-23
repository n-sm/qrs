data Arbol t = Hoja t | Ramificacion (Arbol t) t (Arbol t) deriving Show
data Dir = Der | Izq deriving (Show, Eq)

h1 = Hoja 1
h2 = Hoja 2
a = Ramificacion (Ramificacion h1 0 h2) 1  (Ramificacion h1  0 h1)
b = Ramificacion (Ramificacion h1 1 h1) 1  (Ramificacion h1  1 h1)
esHoja :: Arbol t -> Bool
esHoja (Hoja _) = True
esHoja _ = False

maximo :: Ord t => Arbol t -> t
maximo (Hoja n) = n
maximo (Ramificacion a1 n a2) =
  max n (max (maximo a1) (maximo a2))

raiz :: Arbol t -> t
raiz (Hoja n) = n
raiz (Ramificacion _ n _) = n

todosIguales :: Eq t => Arbol t -> Bool
todosIguales (Hoja _) = True
todosIguales (Ramificacion a n b) 
  | n /= raiz a || n /= raiz b = False
  | otherwise = todosIguales a && todosIguales b
  
espejar :: Arbol t -> Arbol t
espejar a@(Hoja _) = a
espejar (Ramificacion a n b) = Ramificacion (espejar b) n (espejar a)
