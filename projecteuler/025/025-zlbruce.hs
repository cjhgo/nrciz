module Main where

import List

fibonacci = 1:1:zipWith (+) fibonacci (tail fibonacci)

getLength :: (Show a) => a -> Int
getLength = length.show

main = print $ lookup 1000 $ zip (map getLength fibonacci) [1..]

