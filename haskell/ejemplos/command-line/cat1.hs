import System.IO
import System.Environment

main = do
  args <- getArgs
  catFiles args



catFiles [] = return ()
catFiles (f:fs) =
  do
    withFile f ReadMode (\handle -> do
      contents <- hGetContents handle
      putStr contents)
    catFiles fs

                
