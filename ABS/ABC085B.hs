import Control.Monad

main = do
    n <- readLn :: IO Int
    ns <- replicateM n readLn :: IO [Int]

    print $ length (qsort ns)


qsort :: [Int] -> [Int]
qsort [] = []
qsort (p:xs) = qsort smaller ++ [p] ++ qsort larger
    where smaller = [x | x <- xs, x > p ]
          larger  = [x | x <- xs, x < p]
