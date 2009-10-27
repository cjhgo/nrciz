-- 所有3位数的乘积
allNum = [ x * y | x <- [100..999], y <- [100..x] ]

-- 是否为回环数
isPalindrome :: Integer -> Bool
isPalindrome num = numStr == reverse numStr
    where numStr = show num

main = print $ maximum $ filter isPalindrome allNum
