data Poli a = Poli [a]

instance (Num a, Eq a) => Num (Poli a) where
  (Poli p) + (Poli q) = Poli (reverse $ suma (reverse p) (reverse q))
  (Poli p) * (Poli q) = Poli (reverse $ prod (reverse p) (reverse q))
  (Poli p) - (Poli q) = Poli (reverse $ suma (reverse p) $ reverse (prodEscalar (-1) q))
  fromInteger i = Poli [fromInteger i]
--  abs (Poli p) = Poli (map abs p)
--  signum (Poli (a,b)) = Poli (signum a, signum b)

--producto escalar
(.:) :: (Num a,  Eq a) => a -> Poli a -> Poli a
(.:) r (Poli p) = Poli $ prodEscalar r p
  
f = Poli [2,2,1,3] :: (Fractional a) => Poli a
g = Poli [1,2,0,3]
h = Poli [1,1,1,0,0]

suma :: (Num a) => [a] -> [a] -> [a]
suma [] p = p
suma p [] = p
suma (x:xs) (y:ys) = x + y : suma xs  ys
  
prodEscalar :: (Num a, Eq a) => a -> [a] -> [a]
prodEscalar 0 _ = []
prodEscalar n [] = []
prodEscalar n (p:ps) = n*p : prodEscalar n ps

--prod :: [a] -> [a] -> [a]
prod [] _ = []
prod (x:xs) p = suma (prodEscalar x p) (0 : prod xs p)
  
coefsToStr :: (Show a) => (Poli a) -> String
coefsToStr (Poli []) = "Cero"
coefsToStr (Poli (coef:[])) = show coef
coefsToStr (Poli (c1:c0:[]))
  = (show c1)
  ++ " X + "
  ++ show c0
coefsToStr (Poli (c:cs))
  = (show c)  ++ " X + "  ++ (coefsToStr $ Poli cs)
-- |  c == 0 = coefsToStr (Poli cs)

expsToStr  :: (Show a) => (Poli a) -> String
expsToStr (Poli []) = ""
expsToStr (Poli (_:_:[])) = ""
expsToStr (Poli (x:xs))  
  = (espacios (2 + length (show x)))
  ++ (show $ length xs)
  ++ "  "
  ++ (expsToStr (Poli xs) )

espacios :: Int -> String
espacios 0 = []
espacios n = ' ' : espacios  (n - 1)

instance (Show a) => Show (Poli a) where
  show (Poli []) = "Cero"
  show p
    = (expsToStr p)
    ++ "\n"
    ++ (coefsToStr  p)

gr :: Poli a -> Integer
gr (Poli []) = error "El Cero no tiene grado"
gr (Poli (x:[])) = 0
gr (Poli (x:xs)) = 1 + gr (Poli xs)

cp :: (Num a) => Poli a -> a
cp (Poli (x:xs)) = x

resto :: (Eq a, Num a) => Poli a -> Poli a -> Poli a
resto p q
  | (gr p) < (gr q) = p
--  | (gr p) == (gr q) = p - (( (fromIntegral gr p) / (fromIntegral gr q)) .: q)
  | otherwise = resto (p - q) q
