x = int(input())
n = int(input())
sum = 1
fact = 1
for i in range(1,n):
    fact *= i
    sum += (x**i) / fact
    
print("{:.3f}".format(sum))
