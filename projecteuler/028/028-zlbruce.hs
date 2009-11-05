
-- n 为右上角数的平方根，build n得到他随后的4个值，由n^2之后的第一个值n^2+n+1开始
-- 每次递增n+1，直到(n+2)^2，当然这里少算了最开始的1
build n = [n^2 + n + 1, n^2 + 2*n +2..(n+2)^2]

main = print $ (+1).sum $ concatMap build [1,3..999]
