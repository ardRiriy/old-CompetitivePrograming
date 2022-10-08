main :: IO ()
main = do
  s <- getLine :: IO String
  putStrLn $ c (head s) (tail s) 3



c :: Char -> String -> Int -> String
c _ [] _ = "-1"
c _ _ 0  = "-1" 
c s sx@(k:kx) n =
    if s `elem` sx
        then c k (kx ++ [s]) (n-1)
        else [s]