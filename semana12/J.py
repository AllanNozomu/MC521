import math

if __name__ == "__main__":
    
    d = [1, 1]
    l = [1, 0]
    for i in range(2, 13):
        l.append((l[i - 2] + l[i - 1]) * (i - 1))
        d.append(d[i - 1] * i)
    
    n = int(input())
    for i in range(n):
        m = int(input())
        print(str(l[m]) + "/" + str(d[m]))
