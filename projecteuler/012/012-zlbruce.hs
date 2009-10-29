
-- 又是穷举:(
triangle n = n*(n+1) `quot` 2
allTriangle = map triangle [1..]


isqrt = truncate . sqrt . fromIntegral

-- 找出一个数有多少个数能够整除他
getNumOfDivisor 1 = 1
getNumOfDivisor num = genNumOfDivisor 0 [2..isqrt num] + 2
    where genNumOfDivisor count [] = count
          genNumOfDivisor count (x:xs)
            | mod == 0 = genNumOfDivisor count' xs
            | otherwise = genNumOfDivisor count xs
              where (div,mod) = num `quotRem` x 
                    count' = if div == x then count + 1 else count + 2

-- 编译之后运行吧，要不很慢...
-- ghc -O2 --make 012-zlbruce.hs
main = print $ fst.head $ filter ((>500) . snd) $ zip allTriangle $ map getNumOfDivisor allTriangle
