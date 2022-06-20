import Control.Applicative
import Control.Monad
 
main :: IO ()
main = do
  [a, b] <- map read . words <$> getLine
  let n = a*b ::Int
 
  if mod n 2 ==0
    then do
      putStrLn "Even"
    else do
      putStrLn "Odd"