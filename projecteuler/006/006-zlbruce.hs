squareOfSum = (^2) $ sum [1..100]
sumOfSquare = sum $ map (^2) [1..100]

main = print $ squareOfSum - sumOfSquare
