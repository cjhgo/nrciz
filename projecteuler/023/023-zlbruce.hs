import Data.IntSet (toList, fromList, member)


divisor :: Int -> [Int]
divisor n = foldl' getDivisor [1] [2..isqrt n]
    where getDivisor xs x
            | mod == 0 && x == div = x:xs
            | mod == 0 && x /= div = x:div:xs
            | otherwise = xs
            where (div,mod) = n `divMod` x
          isqrt = floor . sqrt . fromIntegral

maxSize = 28123

-- 所有的过剩数
need_abundant_number = filter (\x -> sum (divisor x) > x) [12..maxSize]
-- 所有过剩数的set
need_abundant_number_set = fromList need_abundant_number

p23_list n = filter (not . is_abundant_sum) [1..n]
is_abundant_sum x = any is_sum cur_list
            where cur_list = takeWhile (<x) need_abundant_number
                  is_sum c = let a = x - c
                             in a `member` need_abundant_number_set


main = print $ sum $ p23_list maxSize
