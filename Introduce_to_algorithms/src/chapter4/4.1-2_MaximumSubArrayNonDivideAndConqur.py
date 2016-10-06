def FIND_MAXIMUM_SUBARRAY(A,low,high):
    i=low
    s=-65536
    while i<=high:
        ts=0
        j=i
        while j>0:
            ts+=A[j]
            if ts>s:
                s=ts
                left=j
                right=i
            j-=1
        i+=1
    return (left,right,s)

A=[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
k=FIND_MAXIMUM_SUBARRAY(A,0,len(A)-1)
            
