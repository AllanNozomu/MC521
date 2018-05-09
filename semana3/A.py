if __name__ == "__main__":
    v = input().upper().split(' ')
    while v[0] != '*':
        t = True
        c = v[0][0]
        for cs in v:
            if c != cs[0]:
                t = False
        if t:
            print("Y")
        else :
            print("N")
        v = input().upper().split(' ')