import Data.Numbers.Primes

twiceSquare = map (\x -> 2 * x * x)  [1..]

conjecture n 
  | isPrime n = True    -- 排除素数
  | otherwise = or $ map isOk primes'
  where
    primes' = takeWhile (<n) primes
    isOk p = elem (n-p) $ takeWhile (<=n-p) twiceSquare

main = print $ head $ filter (not . conjecture) [5,7..]
