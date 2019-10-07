def spiralMat(mat,m,n):
    k=0
    l=0
    o=1
    p=n
    while(l<m and k<n):
        for i in range(l,n):
            mat[k][i]=o
            o+=1
        k+=1
        
        for j in range(k,m):
            mat[j][n-1]=o
            o+=1
        n-=1
        if k<m:
            for i in range(n-1,l-1,-1):
                mat[m-1][i]=o
                o+=1
            m-=1
        if l<n:
            for i in range(m-1,k-1,-1):
                mat[i][l]=o
                o+=1
            l+=1
    return mat

n=int(input())
mat=[[0 for x in range(n)] for j in range(n)]
mat=spiralMat(mat,n,n)
for i in range(n):
    for j in range(n):
        print('{0:2}'.format(mat[i][j]),end=" ")
    print()

        
