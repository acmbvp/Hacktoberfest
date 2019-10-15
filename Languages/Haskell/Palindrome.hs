-- Program to check whether a list is palindrome
isPalindrome :: Eq a => [a] -> [a]
isPalindrome x = x == (myReverse x)

myReverse :: [a] -> [a]
myReverse [x] = [x] 
myReverse (x:xs) = (myReverse xs) ++ [x]