x = input("Enter sentence one:")
y = input("Enter sentence one:")

j,sim = 0,0
ly = len(y)
lx = len(x)
for i in x:
    if j >= ly:
        break
    if i == y[j]:
      sim += 1
    j += 1
print(sim/(lx if lx > ly else ly))