{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
import qualified Data.ByteString.Char8 as BS

main = do
    n <- readLn :: IO Int
    ns <- map (read . BS.unpack) . BS.words <$> BS.getLine :: IO [Int]

    print $ jg 2 (qsort ns)

jg ::  Int -> [Int] -> Int
jg _ [] = 0
jg i (n:ns) = n * (-1)^i + jg (i+1) ns


qsort [] = []
qsort (p:xs) = qsort smaller ++ [p] ++ qsort larger
    where smaller = [x | x <- xs, x >= p ]
          larger  = [x | x <- xs, x < p]