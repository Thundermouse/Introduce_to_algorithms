def FIND_MAXIMUM_SUBARRAY(A,low,high):
    i=1
    a=1
    l=list()
    l.append((low,low,A[low]))
    s=A[low]
    while i<=high:
        s+=A[i]
        print i,l
        if s<0:
            s=0
            a=i+1
            l.append(l[i-1])
        elif s>l[i-1][2]:
            l.append((a,i,s))
        else :
            l.append(l[i-1])
        i+=1
    return l[high]

A=[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
k=FIND_MAXIMUM_SUBARRAY(A,0,len(A)-1)
