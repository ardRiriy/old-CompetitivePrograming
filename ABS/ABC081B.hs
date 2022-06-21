main = do
    n <- readLn :: IO Int
    --  | aaa
    ns <- map read . words <$> getLine :: IO [Double]
    print $ check ns 0

check :: [Double] -> Int -> Int
check ns n =
    if all even xs
        then check (map (/2) ns) (n+1)
        else n
    where
        xs = map round ns