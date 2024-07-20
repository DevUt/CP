for i in range(1,1000) :
    for j in range(i+1, 1000):
        s = "1"*j
        s = s[:-i]
        x = int(s,10)
        if j-i == x :
            print(f"{j} {i}")
