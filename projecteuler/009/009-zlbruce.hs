
triplets = [ [a,b,c] | a <- [1..334], b <- [a+1..1000-a], c <- [1000-a-b], a*a + b*b == c*c ]

main = print $ product $ head triplets
