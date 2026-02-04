int mdc1 (int a, int b){
    int r;
    if (a == b){
        r = a;
        return r;
    }
    else if (a > b){
        for (int i = b; 0 < i; i--){
            if (b % i == 0 && a % i == 0){
                r = i;
                return r;
            }
        }
    }
    else{
        for (int i = a; 0 < i; i--){
            if (b % i == 0 && a % i == 0){
                r = i;
                return r;
            }
        }
    }
    
    return r;
}

int mdc2 (int a, int b){
    int r;
    while (a != 0 && b != 0){
        if (a == b){
            r = a;
            return r;
        }
        else if (a > b){
            a -= b;
        }
        else{
            b -= a;
        }
        if (b == 0){
            r = a;
        }
        else if (a == 0){
            r = b;
        }
    }
    return r;
}

int mdc3 (int a, int b, int *count){
    *count = 0;
    while (a != 0 && b != 0){
        if (a > b){
            a -= b;
            (*count)++;
        }
        else if (b > a){
            b -= a;
            (*count)++;
        }
        else{ // a == b
            break;
        }
    }
    return (a == 0 || b == 0) ? b : a;
}

int mdc4(int a, int b, int *count){
    *count = 0;
    while (a != 0 && b != 0){
        if (a > b){
            a = a % b;
            (*count)++;
        }
        else if (b > a){
            b = b % a;
            (*count)++;
        }
        else{
            break;
        }
    }
    return (a == 0) ? b : a;
}