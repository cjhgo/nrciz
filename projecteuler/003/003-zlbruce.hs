
-- 找出x:xs列表中的数是否是num的因子
initFactors :: Integer->[Integer]->[Integer]
initFactors num [] = []
initFactors num (x:xs)
    | num < x = []
    | mod == 0 = x : initFactors div xs
    | otherwise = initFactors num xs
    where
        (div, mod) = num `divMod` x

main = print $ maximum $ initFactors 600851475143 [1,3..truncate (sqrt 600851475143)]
