int fib (int n){
    int r = 0;
    if (n < 2){
        r += n;
    }
    else {
        r = fib (n - 1) + fib(n - 2);
    }
    return r;
}

int fastfib (int n){
    int aux1 = 0;
    int aux2 = 1;
    int r = 0;
    if (n < 2){
        r += n;
    }
    else{
        for (int i = 0; i < n; i++){
            aux1 = aux2;
            aux2 = r;
            r = aux1 + aux2;
        }
    }
    return r;
}

