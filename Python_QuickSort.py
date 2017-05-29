
def Quick_Sort(a,start,end):
    if start < end:
        pIndex = Partition(a,start,end)
        Quick_Sort(a,start,pIndex-1)
        Quick_Sort(a,pIndex+1,end)


def Partition(A,start,end):
    pivot = A[end]
    pIndex = start
    for i in range(start,end):
        if A[i] <= pivot:
            A[i],A[pIndex] = A[pIndex],A[i]
            pIndex += 1
    A[pIndex],A[end] = A[end],A[pIndex]
    return pIndex


B = [7,2,1,6,8,5,3,4]
print("B before Quick Sort : {}".format(B))
Quick_Sort(B,0,7)
print("B after Quick Sort : {}".format(B))
