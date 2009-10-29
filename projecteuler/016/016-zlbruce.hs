import Char

sumOfDigits n = sum $ map digitToInt $ show n

main = print $ sumOfDigits $ 2^1000
