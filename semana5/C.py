def cal(pow, val, mod):
    if pow == 0:
        return 1
    v = cal(pow//2, val, mod)
    if pow % 2 == 0:
        return (v*v) % mod
    else:
        return (((v*v) % mod) * val) % mod

if __name__ == "__main__":
    n = input()

    n = int(n)
    if n == 0:
        print(1)
    else:
        total = cal(2*n-1, 2, 1000000007)
        diferenca = cal(n-1, 2, 1000000007)
        
        print ((total + diferenca) % 1000000007)