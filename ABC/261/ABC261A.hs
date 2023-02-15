main = do
    [n, m, k, l] <- map read . words <$> getLine :: IO [Int]
    print $ cal n m k l 

cal n m k l
    | m == k || n == l = 0
    | l > n && n < k =
        if (m-k) > 0
            then if l > m
                then m-k
                else l-k
            else 0
    | otherwise =
        if (l-n) > 0
            then if m > l
                then l-n
                else m-n
            else 0