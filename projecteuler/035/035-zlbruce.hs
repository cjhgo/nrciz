import Data.List
import Data.Numbers.Primes
import qualified Data.IntSet as S

rotations n = foldl genR [n] [1..nLen - 1]
    where 
        nLen = length $ show n
        genR res num = n' : res
          where n'     = m * (10 ^ (nLen - num)) + d
                (d, m) = n `divMod` (10 ^ num)

allPrime = S.fromList $ takeWhile (<1000000) primes

isOk = and . map isInPrime . rotations

-- 必然是由1,3,5,7组成的数
-- 这个会把2这个数给排除掉，所以需要对结果+1
isInPrime n
    | even n    = False
    | otherwise = S.member n allPrime

main = print $ (+1) . S.size $ S.filter isOk allPrime
