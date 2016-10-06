def FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high):
    left_sum=-65536
    s=0;
    i=mid
    while i>=low:
        s+=A[i]
        if s>left_sum:
            left_sum=s
            max_left=i
        i-=1
    right_sum=-65536
    s=0
    i=mid+1
    while i<=high:
        s+=A[i]
        if s>right_sum:
            right_sum=s
            max_right=i
        i+=1
    return (max_left,max_right,left_sum+right_sum)

def FIND_MAX_SUBARRAY(A,low,high):
    if low==high:
        return (low,high,A[low])
    mid=(low+high)/2
    res=list()
    m=(low+high)/2
    res.append(FIND_MAX_SUBARRAY(A,low,mid))
    res.append(FIND_MAX_SUBARRAY(A,mid+1,high))
    res.append(FIND_MAX_CROSSING_SUBARRAY(A,low,mid,high))
    k= sorted(res,key=lambda x:x[2],reverse=True)
    return k[0]


A=[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]
k=FIND_MAX_SUBARRAY(A,0,len(A)-1)
