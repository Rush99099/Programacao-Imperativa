#include <stdio.h>

void miniteste() {
    long x = 28, y = 2;
    int v = 1;
    char d = 'w';

    for (int t = 0; t <= 10000; t++) {  // Starts at 1
        if (t % 3 == 0 && t % 5 == 0) {
            if (d == 'n')
                d = 'e';
            else if (d == 'e')
                d = 's';
            else if (d == 's')
                d = 'w';
            else
                d = 'n';
        } 
        else if (t % 3 == 0)
            v += 2;
        else if (t % 5 == 0)
            v -= 1;
        else {
            if (d == 'n')
                y += v;
            else if (d == 'e')
                x += v;
            else if (d == 's')
                y -= v;
            else
                x -= v;
        }
    }
    
    printf("%ld %ld %d %c\n", x, y, v, d);
}

int main() {
    miniteste();
    return 0;
}
