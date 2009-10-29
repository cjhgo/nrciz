
-- 这道题可以用一个数组把算出来的结果保存起来
-- 这样在计算下一个数据时可以用上保存的值，不用重新计算
-- 比如得到了countChain 10 = 7后，在计算countChain 20时就不用再计算10的值了
-- 不过在haskell中我不会-_-!!所以-----还是暴力

countChain 1 = 1
countChain num = 1 + countChain num'
    where num' | even num = num `div` 2
               | otherwise = 3 * num + 1

-- 编译后再运行...
-- ghc -O2 --make 014-zlbruce
main = print $ snd.maximum $ zip (map countChain [1..1000000]) [1..1000000]
