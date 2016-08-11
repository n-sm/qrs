import System.IO
import System.Environment

main = do
  args <- getArgs
  catFiles args

catFiles [] = return ()
catFiles (f:fs) =
  do
    contents <- readFile f
    putStr contents
    catFiles fs

                
