import Data.Ratio
import Data.Ord
import Data.List

pell n = loop 0 1 1 0 0 1 a0
     where a0 = floor . sqrt . fromIntegral $ n
           loop p'' q'' p' q' g' h' a
                | p^2-n*q^2 == 1 = p
                | otherwise = loop p' q' p q g h a1
                where p = a*p'+p''
                      q = a*q'+q''
                      g = a*h'-g'
                      h = (n-g^2) `div` h'
                      a1 = (g+a0) `div` h

main = print $ fst $ maximumBy (comparing snd) $ [(n,pell n) | n <- [2..1000], n /= (floor . sqrt . fromIntegral $ n) ^ 2]
