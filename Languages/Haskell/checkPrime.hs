-- Program to check whether a number is prime
isPrime :: Int -> Bool
isPrime k = null [ x | x <- [2..k - 1], k `mod` x == 0]
