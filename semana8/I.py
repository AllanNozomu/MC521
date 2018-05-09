import math

if __name__ == "__main__":
    n = int(input())
    l = [1, 0]
    for i in range(2, n + 1):
        l.append((l[i - 2] + l[i - 1])* (i - 1))
    print(l[n])