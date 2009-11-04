module Main where

import List

forGroup = map (\x -> product [1..x]) [9,8..1]


getNum n = getNum' [] [0..9] 0 n
  where 
    getNum' result [x] i n = x:result
    getNum' result left i n = getNum' result' left' (i+1) n'
      where 
        (div, n') = n `divMod` (forGroup !! i)
        value = left !! (fromInteger div)
        result' = value : result
        left' = delete value left


main = print $ concatMap (show) $ reverse $ getNum 999999
