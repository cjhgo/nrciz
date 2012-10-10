import Data.Char

-- √2:
-- base = 1
-- loop = [ x | x <- [2,2..] ]

--e:
base = 2
loop = concat [ [1, 2*k, 1] | k <- [1..] ]

-- (a,b) == a/b, 初始值为(1,0)，这样其倒数为(0,1)，值为0...
getN n = foldr (\x (a,b) -> (a*x + b, a) ) (1, 0) seq
    where seq = take n $ base:loop


main = print $ sum $ map digitToInt $ show a
    where (a,b) = getN 100
