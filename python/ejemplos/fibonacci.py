# versión recursiva 'ineficiente'.
def fibonacci(n):
    if n <= 2: return 1
    return fibonacci(n-1) + fibonacci(n-2)

# versión iterativa.
def fib(n):
    f1 = 0
    f2 = 1
    for i in range(n):
        tmp = f2
        f2 = f1 + f2
        f1 = tmp
    return f1
