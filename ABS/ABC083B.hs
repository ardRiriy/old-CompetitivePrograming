main = do
    [n, a, b] <- map read . words <$> getLine :: IO [Double]
    print $ func n a b



func :: Double -> Double -> Double -> Int
func 0 _ _ = 0
func n x y
    | sum >= a && sum <= b = m + func (n-1) x y
    | otherwise            = func (n-1) x y
    where
        a = truncate x
        b = truncate y
        m = truncate n
        sum = adder n
        

adder:: Double -> Int
adder n
    | n < 10 = m
    | otherwise = mod m 10 + adder (n/10)
    where
        m = truncate n