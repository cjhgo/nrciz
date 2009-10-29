-- 最自然的想法，但是很慢，我编译之后跑很久都没跑出来
--countNum (begX, begY) (endX, endY)
--    | begX == endX || begY == endY = 1
--    | otherwise = left + down 
--    where right = countNum (begX + 1, begY) (endX, endY)
--          down = countNum (begX ,begY + 1) (endX, endY)
--
--
--main = print $ countNum (0,0) (20,20)

-- 其实就是一个排列组合问题
-- 根据题意，我们只能走20步下和20步右，总共40步
-- 问题就转化为把这20步下和20不右的一个组合
-- 即 C^20_40 * C^20_20

main = print $ countNum 20 20

countNum x y = product [1..x+y] `div` (product [1..x] * product [1..y])
