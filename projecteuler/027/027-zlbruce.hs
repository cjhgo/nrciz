module Main where

import Data.List

prime = 2:isPrime [3,5..]
    where isPrime (x:xs)
            | noMod = x : isPrime xs
            | otherwise = isPrime xs
                where noMod = not.or $ map (\y -> x `mod` y == 0) $ takeWhile (\y -> y*y <= x) prime

isPrime n = n `elem` takeWhile (<=n) prime

f a b n = n*n + a*n + b

flist = [(f a b, a, b) | b <- takeWhile (<999) prime, a <- [-b+1..999]]

getNumOfF (f,a,b) = (len, a,b)
  where len = length $ takeWhile (isPrime.f) [0..]

fst3 (a,_,_) = a
comp (a,_,_) (b,_,_) = compare a b
getResult (_,a,b) = a*b

main = print $ getResult $  maximumBy comp $ map getNumOfF flist

