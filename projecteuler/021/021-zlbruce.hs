import Array

isqrt = truncate . sqrt . fromIntegral
-- sum of divisors
getSumOfDivisor 1 = 1
getSumOfDivisor num = genSumOfDivisor 0 [2..isqrt num] + 1
    where genSumOfDivisor res [] = res
          genSumOfDivisor res (x:xs)
            | mod == 0 = genSumOfDivisor res' xs
            | otherwise = genSumOfDivisor res xs
              where (div,mod) = num `quotRem` x 
                    res' = if div == x then res + div else res + div + x

allList n = listArray (1, n) [getSumOfDivisor i | i <- [1..n]]

getAllAmic n = genAllAmic [1..n]
    where genAllAmic [] = []
          genAllAmic (x:xs)
            | list!x <= n && list!x > 1 && x == list!(list!x) && x /= list!x = x : genAllAmic xs
            | otherwise = genAllAmic xs
          list = allList n

main = print $ sum $ getAllAmic 10000
