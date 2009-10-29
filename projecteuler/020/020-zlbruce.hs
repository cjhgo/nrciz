import Char

sumOfDigits n = sum $ map digitToInt $ show n

main = print $ sumOfDigits $ product [1..100]
