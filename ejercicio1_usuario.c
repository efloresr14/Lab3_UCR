#include <stdio.h>

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i *= n;
        n--;
    }
    return i;
}

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    printf("%d! = %d\n", num, factorial(num));
    return 0;
}
