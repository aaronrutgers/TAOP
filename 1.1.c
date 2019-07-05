#include <stdio.h>
#include <string.h>

void leftShift1(char *s, int n) {
    char t = s[0];
    for (int i = 1; i < n; ++i) {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}

void leftShift2(char *s, int n, int m) {
    while (m--) {
        leftShift1(s, n);
    }
}

void leftShift3(char *s, int from, int to) {
    while (from < to) {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

void leftShift4(char *s, int n, int m) {
    m %= n;
    leftShift3(s, 0, m - 1);
    leftShift3(s, m, n - 1);
    leftShift3(s, 0, n - 1);
}


int main() {
    char str[50];
    sprintf(str, "abcdefghijk");
    printf("The origin str is :%s\tlen is :%zu\n", str, strlen(str));
    printf("\n");
    leftShift1(str, 2);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, -2);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, 3);
    printf("The leftShift1 str is :%s\n", str);
    leftShift1(str, strlen(str) - 3);
    printf("The leftShift1 str is :%s\n", str);
    printf("\n");

    leftShift2(str, strlen(str), 3);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str, strlen(str), strlen(str) - 3);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str + 2, strlen(str) - 2, 2);
    printf("The leftShift2 str is :%s\n", str);
    leftShift2(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift2 str is :%s\n", str);
    printf("\n");

    sprintf(str, "abcdefghijk");
    leftShift3(str, strlen(str), 3);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str, strlen(str), strlen(str) - 3);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str + 2, strlen(str) - 2, 2);
    printf("The leftShift3 str is :%s\n", str);
    leftShift3(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift3 str is :%s\n", str);
    printf("\n");

    leftShift4(str, strlen(str), 3);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str, strlen(str), strlen(str) - 3);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str + 2, strlen(str) - 2, 2);
    printf("The leftShift4 str is :%s\n", str);
    leftShift4(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift4 str is :%s\n", str);
    printf("\n");

/*    leftShift5(str, strlen(str), 3);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str, strlen(str), strlen(str) - 3);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str + 2, strlen(str) - 2, 2);
    printf("The leftShift5 str is :%s\n", str);
    leftShift5(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift5 str is :%s\n", str);
    printf("\n");

    leftShift6(str, strlen(str), 3);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str, strlen(str), strlen(str) - 3);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str + 2, strlen(str) - 2, 2);
    printf("The leftShift6 str is :%s\n", str);
    leftShift6(str + 2, strlen(str) - 2, strlen(str) - 2 - 2);
    printf("The leftShift6 str is :%s\n", str);
    printf("\n");*/

    return 0;
}
