data Rosetree t = Rose t [Rosetree t] deriving Show

raiz :: Rosetree t -> t
raiz (Rose t _) = t

hijos :: Rosetree t -> [Rosetree t]
hijos (Rose _ rs) = rs

sumarlista :: Num t => [Rosetree t] ->  t
sumarlista [] = 0
sumarlista (r:rs) = (sumarTodo r) + sumarlista rs
  
sumarTodo :: Num  t => Rosetree t -> t
sumarTodo (Rose t []) = t
sumarTodo (Rose t rs) = t + sumarlista rs

--sumarTodo (Rose t rs) = t + sum [sumarTodo x | x <- rs]

hojasLista :: [Rosetree t] -> [t]
hojasLista [] = []
hojasLista (r:rs) = hojas r ++ hojasLista rs 

hojas :: Rosetree t -> [t]
hojas (Rose t []) = [t]
hojas (Rose t rs) = hojasLista rs 

reversear :: [Rosetree t] -> [Rosetree t]
reversear [] = []
reversear (r:rs) =  reversear rs ++ [espejar r] 
             
espejar :: Rosetree t -> Rosetree t
espejar (Rose t []) = (Rose t [])
espejar (Rose t ts) = (Rose t (reversear ts))



x = Rose 1 [Rose 23 [ Rose 1241243 []]]
a = Rose 7 [Rose 1 [Rose 1 [], Rose 1 [Rose 2 [], Rose 3 []]]] 
