def min_k(n) :
    expr = int(1e9)
    min_i = int(1e9)
    for i in range(1,n) :
        tmp_expr = i + n//i + int(n%i != 0)
        if expr > tmp_expr :
            expr = tmp_expr 
            min_i = i
    return min_i, n//min_i , expr

