import System.Environment
import Data.Char
import qualified Data.ByteString as B

main = do
  contents <- B.readFile "foo.txt"
  print $ B.reverse contents




