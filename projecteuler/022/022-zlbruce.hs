module Main where

import IO
import List
import Char 


main = do
    hFile <- openFile "names.txt" ReadMode
    hString <- hGetContents hFile
    print $ getAllScores $ sort $ getData hString
    hClose hFile

getData :: String -> [String]
getData a = map read $ mywords $ map toUpper a

mywords :: String -> [String]
mywords s =  case dropWhile {-partain:Char.-}isComma s of
                "" -> []
                s' -> w : mywords s''
                      where (w, s'') =
                             break {-partain:Char.-}isComma s'

isComma c = if c == ',' then True else False

getAllScores = getAllScores' 1 
    where getAllScores' order [] = 0
          getAllScores' order (x:xs) = order * (getScores x) + getAllScores' (order + 1) xs
          getScores xs = sum $ map (\x -> ord x - 64) xs
