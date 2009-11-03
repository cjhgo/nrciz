module Main where

main = print $ queens 8 8

queens 0 _ = [[]]
queens n m = [ x : y | y <- queens (n-1) m, x <- [1..m], safe x y 1]
    where
        safe x [] n = True
        safe x (c:y) n = and [ x /= c , x /= c + n , x /= c - n , safe x y (n+1)]

