coins = [1, 2, 5, 10, 20, 50, 100, 200]

getWay n [] = 0
getWay n l@(x:xs) 
    | n == 0    = 1
    | n < 0     = 0
    | otherwise = getWay n xs + getWay (n - x) l


main = print $ getWay 200 coins
