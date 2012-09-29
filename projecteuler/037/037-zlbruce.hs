import Data.List
import Data.Numbers.Primes

truncs n = nub $ foldl genT [n] [1..nLen - 1]
    where 
        nLen = length $ show n
        genT res num = r' : l' : res
          where l' = n `div` 10 ^ (nLen - num)
                r' = n `mod` 10 ^ num

isOk = and . map isPrime . truncs

main = print . sum . take 11 . filter isOk $ dropWhile (<10) primes
