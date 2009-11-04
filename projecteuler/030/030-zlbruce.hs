module Main where 

import Data.Char

main = print $ sum [ x | x <- [2..500000], isOk x]

isOk x = if x == sumOfFifthPowers x then True else False

sumOfFifthPowers x = sum $ map ((^5).digitToInt) $ show x
