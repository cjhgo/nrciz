-- 下面这样太慢了，使用了偷懒的做法，不知道算不算作弊-_-!!
--filterList = map (\x y -> y `mod` x == 0) [2..20]
--main = print $ head $ foldr filter [1..] filterList
--


-- 能被1-20都整除的数肯定能被1-10都整除，所以肯定是2520的倍数，所以只需要从这些数中过滤出都能被11-20整除的数就可以了
filterList = map (\x y -> y `mod` x == 0) [11..20]

main = print $ head $ foldr filter [2520, 5040..] filterList
