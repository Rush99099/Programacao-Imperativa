float multInt1 (int n, float m){
    int contOp = 0;
    float r = 0;
    for (int i = 0; i < n; i++){
        r+=m;
        contOp++;
    }
    
    return r;

}

float multInt2 (int n, float m){
    int contOp = 0;
    float r = 0;
    while (n > 0){
        if (n % 2 != 0){
            r += m;
            contOp++;
        }
        m = m * 2;
        n = n / 2;
    }
    return r;
}

float multInt3 (int n, float m, int *count){
    float r = 0;
    while (n > 0){
        if (n % 2 != 0){
            r += m;
            (*count)++;
        }
        m = m * 2;
        n = n / 2;
    }
    return r;
}