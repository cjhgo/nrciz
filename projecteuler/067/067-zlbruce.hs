module Main where

import IO


main = do
    hFile <- openFile "triangle.txt" ReadMode
    hString <- hGetContents hFile
    print $ head $ foldr1 getMaxPath (getData hString)
    hClose hFile

getData :: String -> [[Int]]
getData s = map ((map read).words) $ lines s

getMaxPath [] _ = []
getMaxPath (x:xs) (w1:w2:ws) 
    | w1 > w2 = (x+w1) : getMaxPath xs (w2:ws)
    | otherwise = (x+w2) : getMaxPath xs (w2:ws)
