import qualified Data.ByteString.Char8 as BS

main = do
  -- | 標準入力から一行読み込む
  -- | 型は省略可
  s <- getLine :: IO String

  -- | 標準入力から一行読み込みInt型の値に変換する
  -- | read <$> getLine とほぼ同じ
  -- | Integer や Double として読み込みたい時は後ろの型を変える
  -- | 型は省略しない方が無難
  n <- readLn :: IO Int

  -- | 標準入力から一行読み込み、空白区切りで文字列のリストに変換する
  xs <- words <$> getLine :: IO [String]
  -- | より効率が良い(数値型でも使える？要検証)
  xs <- map (read . BS.unpack) . BS.words <$> BS.getLine

  -- | 標準入力から一行読み込み、空白区切りでInt型の値のリストに変換する
  ns <- map read . words <$> getLine :: IO [Int]
  

  -- | 標準入力から一行読み込み、空白区切りでInt型の値を取り出す
  -- | 1行あたりで与えられるパラメータの数が予め分かっているときに便利
  [n, m] <- map read . words <$> getLine :: IO [Int]

  -- | 標準入力からn行読み込み、文字列のリストとして返す
  xs <- replicateM n getLine :: IO [String]

  -- | 標準入力からn行読み込み、Int型の値のリストとして返す
  ns <- replicateM n readLn :: IO [Int]

  -- | 標準入力からn行読み込み、各行を空白区切りでInt型の値のリストに変換したリストを返す
  nss <- replicateM n (map read . words <$> getLine) :: IO [[Int]]

  /*--------------------------------------------------------------------------------*/

  -- | 文字列型の値を出力する
  putStrLn (xs :: String)

  -- | Int, Integer, Double 等の方の値を出力する
  -- | String も出力できるがダブルクオーテーションがついてしまうので
  -- | String を出力する際は putStrLn を使う
  print (n :: Int)

  -- | リストの値を先頭から順番に一行ずつ出力する
  -- | 文字列のリストを出力する際は print を putStrLn　に置き換える
  mapM_ print (ns :: [Int])

  -- | リストの値を空白区切りで一行で出力する
  putStrLn . unwords . map show $ (ns :: [Int])