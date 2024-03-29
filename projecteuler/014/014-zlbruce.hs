import Data.Array.Unboxed
import qualified Data.Array.Unsafe as U
import Data.Array.IO
import Control.Monad
import Data.List
--import Data.Vector.Unboxed hiding (mapM_)
--import qualified Data.Vector.Generic as G
--import qualified Data.Vector.Generic.Mutable as GM


-- 这道题可以用一个数组把算出来的结果保存起来
-- 这样在计算下一个数据时可以用上保存的值，不用重新计算
-- 比如得到了countChain 10 = 7后，在计算countChain 20时就不用再计算10的值了
-- 不过在haskell中我不会-_-!!所以-----还是暴力

--countChain 1 = 1
--countChain num = 1 + countChain num'
--    where num' | even num = num `div` 2
--               | otherwise = 3 * num + 1
--
---- 编译后再运行...
---- ghc -O2 --make 014-zlbruce
--main = print $ snd.maximum $ zip (map countChain [1..1000000]) [1..1000000]


-- 使用数组存储中间的计算值
maxSize = 1000000 :: Integer
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

countChainV3 arr num
    | num > maxSize = countChainMain
    | otherwise = do
        val <- readArray arr num
        if val == 0 
          then do
            val' <- countChainMain
            writeArray arr num val'
            return val'
          else do
            return val
    where countChainMain = do
            if even num
              then countChainV3 arr (num `div` 2) >>= return.(+1)
              else countChainV3 arr (3 * num + 1) >>= return.(+1)
    
main = do
    marr <- newListArray (1, maxSize) $ 1:[0,0..] :: IO (IOUArray Integer Int)
    mapM_ (countChainV3 marr) [1..maxSize]
    arr <- U.unsafeFreeze marr :: IO (UArray Integer Int)
    let maxNum = foldl' (findMaxNum arr) 1 [1..maxSize]
    print (maxNum, arr!maxNum)
    where 
        findMaxNum a maxNum num =
            let valnum = a!num
                valMax = a!maxNum
            in  if valnum > valMax then num else maxNum


-- 使用Vector
--initVector :: Vector Int
--initVector = fromListN (fromInteger maxSize) (1:1:[0,0..] :: [Int])
--
--countChainV4 vec num
--    | num >= maxSize = countChainMain
--    | otherwise = do
--        val <- GM.read vec (fromInteger num)
--        if val == 0
--        then do
--            val' <- countChainMain
--            GM.write vec (fromInteger num) val'
--            return val'
--        else do
--            return val
--    where 
--        countChainMain = 
--            if even num 
--                then countChainV4 vec (num `div` 2) >>= return.(+1)
--                else countChainV4 vec (3 * num + 1) >>= return.(+1)
--
--main = do
--    mvec <- unsafeThaw initVector
--    mapM_ (countChainV4 mvec) [1..maxSize]
--    vec <- unsafeFreeze mvec
--    let maxNum = maxIndex vec
--    print (maxNum, vec!maxNum)
