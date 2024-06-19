x, y, n = map(int, input().split())

for i in range (1,x+y+2) :
    if i%x == y%i :
        print(f"{i} for {x} and {y}")

# print(f"{n%x} {y%n}")
