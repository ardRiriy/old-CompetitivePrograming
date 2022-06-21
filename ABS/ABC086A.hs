import Control.Applicative
import Control.Monad

main :: IO ()
main = do
  [a, b] <- map read . words <$> getLine
  let n = a*b ::Int

  if even n
    then do
      putStrLn "Even"
    else do
      putStrLn "Odd"