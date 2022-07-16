

def LCS(X, Y, m, n) :
    if m == 0 or n == 0 :
        return 0
    elif X[m-1] == Y[n-1] :
        return LCS(X, Y, m-1, n-1) + 1
    else :
        return max(LCS(X, Y, m-1, n), LCS(X, Y, m, n-1))


qnum = 0

while True :
    qnum += 1
    n1, n2 = map(int,input().split())

    if n1 == 0 :
        break

    arr1 = list(map(int,input().split()))
    arr2 = list(map(int,input().split()))

    print("Twin Towers #{}\nNumber of Tiles : {}\n\n".format(qnum, LCS(arr1, arr2, n1, n2)))

