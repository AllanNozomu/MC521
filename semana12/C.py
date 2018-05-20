import math

if __name__ == "__main__":
    
    l = [0, 2, 5, 13]
    for i in range(4, 1001):
        l.append(2*l[i - 1] + l[i - 2] + l[i - 3])
    
    while True:
        try:
            s=int(input())
            print(l[s])
        except:
            break
