main = do
    n <- readLn :: IO Int
    print $ hundred n

hundred :: Int -> Int
hundred n
    | n >= 100  = 1 + ten (n-100)
    | otherwise = 0 + ten n

ten :: Int -> Int
ten n
    | n >= 10   = 1 + one (n-10)
    | otherwise = 0 + one n

one :: Int -> Int
one n
    | n == 1    = 1
    | otherwise = 0