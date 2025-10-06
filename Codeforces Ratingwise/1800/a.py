MOD = 10**9 + 7

def modinv(x, p):
    return pow(x, p-2, p)

def nCr_mod_p(n, r, p):
    if r > n:
        return 0
    if n < p:
        num = 1
        den = 1
        for i in range(r):
            num = (num * (n - i)) % p
            den = (den * (i + 1)) % p
        return (num * modinv(den, p)) % p
    ni = n % p
    ri = r % p
    return (nCr_mod_p(n // p, r // p, p) * nCr_mod_p(ni, ri, p)) % p

n = (90000 - 1) * 70000 + 1
a = 90000
b = 80000
k = 70000

nca = nCr_mod_p(n, a, MOD)
res = (nca * k * (b - 1) + 1) % MOD

print(res)
