main = do
  ln <- getln
  print ln
  

getln = do c <- getChar
           if c == '\n'
             then return ""
             else do l <- getln
                     return (c:l)
