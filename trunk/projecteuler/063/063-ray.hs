main = print . length $ [x^y | x <- [1..9], y <- [1..21], (==y) . length . show $ x^y]