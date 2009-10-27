-- 写得好丑...
prime = 2:isPrime [3,5..]
    where isPrime (x:xs)
            | noMod = x : isPrime xs
            | otherwise = isPrime xs
                where noMod = not.or $ map (\y -> x `mod` y == 0) $ takeWhile (\y -> y*y <= x) prime

-- 速度很慢...
main = print $ sum $ takeWhile (<2000000) prime
