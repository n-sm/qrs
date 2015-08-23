def dnorm(x,mu = 0,sigma = 1):
    import math;
    return (1/(sigma*math.sqrt(2*math.pi))) * math.exp(-.5*(((x-mu)/sigma)**2));

def dnorm01(x):
    import math;
    return (1/(math.sqrt(2*math.pi))) * math.exp(-.5*(x**2));

dnorm01.expr = (1/(sqrt(2*pi))) * exp(-.5*(x**2));
def derivarDnorm():
    import sympy;
    x, mu, sigma = sympy.symbols('x u sigma');
    return sympy.diff((1/(sigma*sympy.sqrt(2*sympy.pi))) * sympy.exp(-.5*(((x-mu)/sigma)**2)), x);
