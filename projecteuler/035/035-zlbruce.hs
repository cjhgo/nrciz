import Data.List
import Data.Numbers.Primes

rotations n = foldl genR [n] [1..nLen - 1]
    where 
        nLen = length $ show n
        genR res num = n' : res
          where n'     = m * (10 ^ (nLen - num)) + d
                (d, m) = n `divMod` (10 ^ num)

allPrime = takeWhile (<1000000) primes

isOk = and . map isPrime . rotations

main = print $ length $ filter isOk allPrime
