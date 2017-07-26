import math
n, k =[int(x) for x in input().split()] 
arr = input()
l = list(map(int,arr.split(' ')))
list1 = []
list2 = []
x = 0
while(x < n/2):
	list1.append(l[x])
	x = x+1
while(x < n):
	list2.append(l[x])
	x+=1
#print(len(list1))
def subproduct(li,nb):
	b = []
	up = 1<<nb
	global ans
	for i in range(1,up):
		prod = 1
		flag = 1
		for j in range(0,nb):
			if(i&(1<<j)):
				#jth element present in the array or not
				if(li[j] < (k/prod)):
					prod = prod*li[j]
				else: 
					flag = 0
					break
		if(flag == 1):
			b.append(prod)

	return b
ans = 0
b = subproduct(list1,len(list1))
c = subproduct(list2, len(list2))
ans += len(b) + len(c)
c.sort()
#print(b)
#print(c)
def BS(start,end,li,target):
	while(start <= end):
		mid = (start+end)//2
		if(li[mid] <= target):
			start = mid+1
		else:
			end = mid-1
	return start
for i in b:
	ind = BS(0,len(c)-1,c,k/i)
	ans += ind

print(ans)