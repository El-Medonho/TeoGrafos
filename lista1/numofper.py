N = 1

for i in range(100):
    N = 1
    for j in range(i):
        k = j+1
        N *= k
    
    if(N >= 1e82): 
        N = i
        break

print(N)

