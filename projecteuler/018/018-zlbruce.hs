-- 从下往上计算每层各个点的最大权值即可

import Array

rawData = [ [75],
            [95,64],
            [17,47,82],
            [18,35,87,10],
            [20,04,82,47,65],
            [19,01,23,75,03,34],
            [88,02,77,73,07,63,67],
            [99,65,04,28,06,16,70,92],
            [41,41,26,56,83,40,80,70,33],
            [41,48,72,33,47,32,37,16,94,29],
            [53,71,44,65,25,43,91,52,97,51,14],
            [70,11,33,28,77,73,17,78,39,68,17,57],
            [91,71,52,38,17,14,91,43,58,50,27,29,48],
            [63,66,04,68,89,53,67,30,73,16,69,87,40,31],
            [04,62,98,27,23,09,70,98,73,93,38,53,60,04,23] ]

--rawData = [ [3],
--            [7,4],
--            [2,4,6],
--            [8,5,9,3] ]

-- 我把三角形倒过来了，便于遍历
reverseData = reverse rawData

-- 由前一行的权值和这样的数据，返回这行最大的权值
step pre cur 
    | isEmpty = listArray (1, length cur) $ map (\x -> (x, [x])) cur
    | otherwise = step' [] 1 cur
    where step' res _ [] = listArray (1, length res) $ reverse res
          step' res n (x:xs) = step' res' (n+1) xs
            where res' = add:res
                  (w1,p1) = pre!n
                  (w2,p2) = pre!(n+1)
                  (w',p') = if w1 > w2 then (w1,p1) else (w2,p2)
                  add = (w'+x, x:p')
          isEmpty = b == e
            where (b,e) = bounds pre


getWightPath x = genWightPath (array (1,1) []) x
    where genWightPath res [] = res
          genWightPath res (x:xs) = genWightPath res' xs
            where res' = step res x


main = print $ head.elems $ getWightPath reverseData
