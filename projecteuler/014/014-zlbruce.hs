--import Data.Array.IArray
--import Data.Array.MArray
--import Data.Array.IO
import Control.Monad
--import Data.List
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Generic as G
import qualified Data.Vector.Generic.Mutable as GM


-- 这道题可以用一个数组把算出来的结果保存起来
-- 这样在计算下一个数据时可以用上保存的值，不用重新计算
-- 比如得到了countChain 10 = 7后，在计算countChain 20时就不用再计算10的值了
-- 不过在haskell中我不会-_-!!所以-----还是暴力

--countChain 1 = 1
--countChain num = 1 + countChain num'
--    where num' | even num = num `div` 2
--               | otherwise = 3 * num + 1
--
-- 编译后再运行...
-- ghc -O2 --make 014-zlbruce
--main = print $ snd.maximum $ zip (map countChain [1..1000000]) [1..1000000]


-- 使用数组存储中间的计算值
maxSize = 1000000
-- 第一个元素为1,其他初始化为0
--allTempValue :: Array Int Int
--allTempValue = listArray (1, maxSize) $ 1:replicate (maxSize - 1) 0
--
----countChainV2 :: Array Int Int -> Int -> (Array Int Int, Int)
--countChainV2 arr num 
--    | num > maxSize = (arr', newval)
--    | otherwise = case arr!num of
--                    0 -> (newarr, newval)
--                    otherwise -> (arr, arr!num)
--    where
--        (arr',val) = if even num then countChainV2 arr (num `div` 2) else countChainV2 arr (3 * num + 1)
--        newval = val + 1
--        newarr = arr'//[(num, newval)]
--
--main = print $ (maxNum, arr!maxNum)
--    where (arr,maxNum) = foldl' findMaxNum (allTempValue, 1) [1..maxSize]
--          findMaxNum (a, maxNum) num =
--              let (a', val) = countChainV2 a num
--                  maxNum' = if val > a'!maxNum then num else maxNum
--              in (a', maxNum')
--

--countChainV3 :: IOUArray Int Int -> Int -> IO Int
--countChainV3 num arr
--    | num > maxSize = do 
--        val <- if even num then countChainV3 (num `div` 2) arr else countChainV3 (3 * num + 1) arr
--        return (val + 1)
--    | otherwise = do
--        val <- readArray arr num
--        if val == 0 
--        then do
--            val' <- if even num then countChainV3 (num `div` 2) arr else countChainV3 (3 * num + 1) arr
--            writeArray arr num (val' + 1)
--            return (val' + 1)
--        else do
--            return val
--    
--main = do
--    arr <- newListArray (1, maxSize) $ 1:[0,0..] :: IO (IOUArray Int Int)
--    maxNum <- foldM (findMaxNum arr) 1 [1..maxSize]
--    print maxNum
--    where 
--        findMaxNum a maxNum num = do
--            valnum <- countChainV3 num a
--            valMax <- countChainV3 maxNum a
--            if valnum > valMax then return num else return maxNum


-- 使用Vector
--initVector :: V.Vector Int
initVector = V.fromListN maxSize (1:1:[0,0..] :: [Int])

countChainV4 num vec
    | num >= maxSize = countChainMain
    | otherwise = do
        val <- GM.read vec num
        if val == 0
        then do
            val' <- countChainMain
            GM.write vec num val'
            return val'
        else do
            return val
    where 
        countChainMain = 
            if even num 
            then
                countChainV4 (num `div` 2) vec >>= return.(+1)
            else
                countChainV4 (3 * num + 1) vec >>= return.(+1)

main = do
    mvec <- V.unsafeThaw initVector
    maxNum <- foldM (findMaxNum mvec) 1 [1..maxSize]
    print maxNum
    GM.read mvec maxNum >>= print
    where
        findMaxNum v maxNum num = do
            valnum <- countChainV4 num v
            valMax <- countChainV4 maxNum v
            if valnum > valMax then return num else return maxNum
