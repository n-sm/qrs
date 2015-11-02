def esPolindromo(string):
    for i in range(len(string)//2):
        if string[i] is not string[-(i+1)]:
            return False
    return True
