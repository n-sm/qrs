inics :: String -> String
inics [] = []
inics (' ':x:xs) = x:inics xs
inics ('.':x:xs) = x:inics xs
inics ('_':x:xs) = x:inics xs
inics ('-':x:xs) = x:inics xs
inics (x:xs) = inics xs

iniciales :: String -> String
iniciales [] = []
iniciales (x:xs) = x : inics xs


iniciales' :: String -> String
iniciales' [] = []
iniciales' (x:xs) = x : inics' xs

inics' :: String -> String
inics' (x:x':xs)
  | elem x delims && not (elem x' delims) = x' : inics' xs
  | elem x delims && elem x' delims = inics' $ x':xs
  | otherwise = inics' $ x':xs
  where delims = " .-_"
  
inics' _ = []


    
