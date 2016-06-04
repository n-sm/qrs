par n | mod n 2 == 0 = 0
    | otherwise = 1

testHastaN n = map par [k*k | k <- [1..n]]

test [] = []
test (x:xs) = [(x, head xs)] : test (tail xs)
