import System.IO
import System.Environment

main = do
  args <- getArgs
  mapM (\f -> do
           contents <- readFile f
           putStr contents)
    args
