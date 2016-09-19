import System.Environment
import System.IO

main = do
  args <- getArgs
  catFiles args


catFiles [] = return ()
catFiles (f:fs) =
  do
    handle <- openFile f ReadMode
    contents <- hGetContents handle
    putStr contents
    hClose handle
    catFiles fs
    
