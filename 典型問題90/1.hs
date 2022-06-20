main = do
    [n, l] <- map read . words <$> getLine :: IO [Int]
    k <- getLine :: IO String
    ns <- map read . words <$> getLine :: IO [Int]

    