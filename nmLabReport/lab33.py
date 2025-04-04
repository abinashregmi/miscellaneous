import math

def f(x, y, yp):
    return -y  # Example: y'' = -y (simple harmonic oscillator)

def rk4(x0, y0, yp0, h, x):
    y = y0
    yp = yp0
    
    while x0 < x:
        k1 = h * yp
        l1 = h * f(x0, y, yp)
        
        k2 = h * (yp + 0.5 * l1)
        l2 = h * f(x0 + 0.5 * h, y + 0.5 * k1, yp + 0.5 * l1)
        
        k3 = h * (yp + 0.5 * l2)
        l3 = h * f(x0 + 0.5 * h, y + 0.5 * k2, yp + 0.5 * l2)
        
        k4 = h * (yp + l3)
        l4 = h * f(x0 + h, y + k3, yp + l3)
        
        y += (k1 + 2*k2 + 2*k3 + k4) / 6.0
        yp += (l1 + 2*l2 + 2*l3 + l4) / 6.0
        
        x0 += h
    
    return y

def shooting_method(a, b, alpha, beta, h):
    t1 = 0.0
    t2 = 1.0
    iter = 0
    
    while iter < 100:
        y1 = rk4(a, alpha, t1, h, b)
        y2 = rk4(a, alpha, t2, h, b)
        
        if abs(y1 - beta) < 1e-6:
            print(f"Solution found: y'(a) = {t1}")
            return
        
        if abs(y2 - beta) < 1e-6:
            print(f"Solution found: y'(a) = {t2}")
            return
        
        t = t2 - (y2 - beta) * (t2 - t1) / (y2 - y1)
        
        t1 = t2
        t2 = t
        
        iter += 1
    
    print(f"Solution not found within {100} iterations")

def main():
    a = 0.0
    b = 1.0
    alpha = 0.0
    beta = 1.0
    h = 0.01
    
    shooting_method(a, b, alpha, beta, h)

if __name__ == "__main__":
    main()