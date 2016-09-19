import System.Environment
import Data.Char

main = do
  args <- getArgs
  putStr "\n"
  putStrLn $ foo $ head args

foo :: String -> String
foo str = map (chr . ord) str


