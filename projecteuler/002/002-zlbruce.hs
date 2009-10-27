-- 从1开始，在小于4000000以内的所有Fib数中的偶数，求他们的和

fib = 1 : 2 : zipWith (+) fib (tail fib)

main = print $ sum $ takeWhile (<4000000) $ filter even fib
