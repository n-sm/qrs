--suma x y = x + y

doble x = 2 * x

suma x y = x + y

normaVectorial v1 v2 = sqrt (v1**2 + v2**2)

funcionConstante8 x = 8

respuestaATodo = 42

unoSiCero n | n == 0 = 1
            | n /= 0 = 0


unoSiCero2 0 = 1
unoSiCero2 n = 0

test 0 = 1

signo n | n > 0  = 1
        | n == 0 = 0
        | n < 0  = (-1)

signo2 0 = 0
signo2 n | n > 0 = 1
         | otherwise = -1

absoluto n | n >= 0 = n
           | otherwise = -n


