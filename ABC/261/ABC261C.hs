import Control.Monad

-- | TLEで死ぬ
main = do
    n <- readLn :: IO Int
    xs <- replicateM n getLine :: IO [String]
    mapM_ putStrLn $ reverse(cal (reverse xs))

cal :: [String] -> [String]
cal [] = []
cal (x:xs) =
    if x `elem` xs
        then (x ++ "(" ++ show(length(filter (== x) xs)) ++ ")") : cal xs
        else x : cal xs