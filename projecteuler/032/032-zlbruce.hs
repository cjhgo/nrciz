import Data.List

allNum = permutations [1..9]

isOk [a,b,c,d,e,f,g,h,i] = x * y == z || x' * y' == z
    where x  = 10 * a + b
          y  = 100 * c + 10 * d + e
          z  = 1000 * f + 100 * g + 10 * h + i
          x' = a
          y' = 1000 * b + 100 * c + 10 * d + e

toNum [_,_,_,_,_,a,b,c,d] = a * 1000 + b * 100 + c * 10 + d

main = print . sum . nub . map toNum $ filter isOk allNum
