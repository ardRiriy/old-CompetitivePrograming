main = do
    [x, y]<- map read . words <$> getLine :: IO [Int]