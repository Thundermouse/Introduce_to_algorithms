def MERGE(l,p,q,r):
    res=list()
    A=l[p:q+1]
    B=l[q+1:r+1]
    i=0
    j=0
    k=p
    con=0
    while k < r+1:
        
        if A[i]<=B[j]:
            l[k]=A[i]
            i+=1
        else :
            l[k]=B[j]
            j+=1;
            con+=len(A)-i
        
        k+=1
        
        if i==len(A):
            l[k:r+1]=B[j:len(B)]
            break
        elif j==len(B):
            l[k:r+1]=A[i:len(A)]
            break
    return con

def SORT_MERGE(c,a,b):
    res=0
    if b>a:
        mid=(a+b)/2
        res+=SORT_MERGE(c,a,mid)
        res+=SORT_MERGE(c,mid+1,b)
        res+=MERGE(c,a,mid,b)
    return res


A=[2,3,8,6,1]
print SORT_MERGE(A,0,len(A)-1)



            
