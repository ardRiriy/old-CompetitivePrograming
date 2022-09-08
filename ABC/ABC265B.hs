import qualified Data.ByteString.Char8 as BS
import Control.Monad

main = do
    [n, m, t] <- map read . words <$> getLine :: IO [Int]
    a <- map (read . BS.unpack) . BS.words <$> BS.getLine:: IO[Int]
    nss <- replicateM m (map read . words <$> getLine) :: IO [[Int]]

    putStrLn $ func times n t (a++[-1]) (nss++[[-1,2]])
    where
        times = 1

func :: Int -> Int -> Int -> [Int] -> [[Int]] -> String
func times n t a nss
    | t <= 0 = "No"
    | times == n = "Yes"
    | otherwise =
        if head(head nss) == times
            then func (times + 1) n (t - head a + last(head nss)) (tail a) (tail nss)
            else func (times + 1) n (t - head a) (tail a) nss

