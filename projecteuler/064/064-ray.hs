continuedFraction n = loop 0 1 a0 1
     where a0 = floor . sqrt . fromIntegral $ n
           loop g' h' a ans
                | h == 1 = ans
                | otherwise = loop g h a1 (ans+1)
                where g = a*h'-g'
                      h = (n-g^2) `div` h'
                      a1 = (g+a0) `div` h

main = print $ sum $ [continuedFraction n `mod` 2 | n <- [2..10000], n /= (floor . sqrt . fromIntegral) n ^ 2]