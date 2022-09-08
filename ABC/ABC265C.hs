-- | 未完成　まったく解けてない

import qualified Data.ByteString.Char8 as BS
import Control.Monad

main = do
    [h, w] <- map read . words <$> getLine :: IO [Int]
    xs <- replicateM h getLine :: IO [[Char]]
    print $ func x y xs times h w
    where
        x = 1
        y = 1
        times = 0


func x y xs times h w
    | times == 1000 = -1
    | (takeY (takeX xs x-1) y-1) == 'R' && y /= w = func x (y+1) xs (times+1) h w
    | (takeY (takeX xs x-1) y-1) == 'U' && x /= 1 = func (x-1) y xs (times+1) h w
    | (takeY (takeX xs x-1) y-1) == 'D' && x /= h = func (x+1) y xs (times+1) h w
    | (takeY (takeX xs x-1) y-1) == 'L' && y /= w = func x (y-1) xs (times+1) h w
    | otherwise = times

takeX xs 0 = head xs
takeX xs x = takeX (tail xs) (x-1)

takeY:: [Char] -> Int -> Char
takeY xs 0 = head xs
takeY xs x = takeX (tail xs) (x-1)
     
