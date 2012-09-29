import Data.List
import Data.Numbers.Primes
import qualified Data.IntSet as S

truncs n = nub $ foldl genT [n] [1..nLen - 1]
    where 
        nLen = length $ show n
        genT res num = r' : l' : res
          where l' = n `div` 10 ^ (nLen - num)
                r' = n `mod` 10 ^ num

-- 这里假定了这些数在1000000以内
allPrime = S.fromList $ takeWhile (<1000000) primes

isOk = and . map isInPrime . truncs

isInPrime n
    | even n && n > 2 = False
    | otherwise       = S.member n allPrime

main = print . sum . take 11 . filter isOk $ dropWhile (<10) primes
