main = do
    n <- readLn :: IO Int
    -- | Floatで読み込むと大きい数字を扱う時に死ぬ
    ns <- map read . words <$> getLine :: IO [Double]
    print $ check ns 0

check :: [Double] -> Int -> Int
check ns n =
    if all even xs
        then check (map (/2) ns) (n+1)
        else n
    where
        xs = map round ns