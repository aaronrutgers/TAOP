//
// Created by 王沛彬 on 2019-07-04.
//

#include <stdio.h>
#include <string.h>

#define bool    _Bool
#define TRUE    1
#define false   0

void countSort(char *oldArr, char *newArr) {
    int count[26] = {0};
    int i;
    int lenOld = strlen(oldArr);
    memset(newArr, 0, lenOld); //clear
    int pos;
    for (i = 0; i < lenOld; i++) {
        pos = *(oldArr + i) - 'A';
        count[pos]++;
    }
    for (i = 0; i < 25; i++) {
        count[i + 1] += count[i];
    }
    for (i = 0; i < lenOld; i++) {
        pos = count[*(oldArr + i) - 'A'];
        while (newArr[pos - 1] != 0) {
            pos++;
        }
        newArr[pos - 1] = *(oldArr + i);
    }
}

bool contain1(char *stra, char *strb) {

    int lena = strlen(stra);
    int lenb = strlen(strb);
    for (int i = 0; i < lenb; ++i) {
        int j;
        for (j = 0; j < lena; ++j) {
            if (*(stra + j) == *(strb + i)) {
                break;
            }
        }
        if (j >= lena) {
            return false;
        }
    }
    return TRUE;
}

bool contain2(char *stra, char *strb) {
    char tmpA[100] = {0};
    char tmpB[100] = {0};
    countSort(stra, tmpA);
    countSort(strb, tmpB);

    int lena = strlen(tmpA);
    int lenb = strlen(tmpB);
    int i, j;

    /*下面这个for循环囊括了3种情况*/
    for (i = 0, j = 0; j < lena && i < lenb; j++) {
        if (tmpA[j] == tmpB[i]) {
            i++;
        } else if (tmpA[j] > tmpB[i]) {
            return false;
        }
    }
}


int main() {
    char stra[50];
    char strb[50];
    char strc[50];
    sprintf(stra, "ABCDEFGHLMNOPQRS");
    sprintf(strb, "DCGSRQPO");
    sprintf(strc, "DCGSRQPZ");

    if (contain1(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain1(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain2(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain2(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

/*    if (contain3(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain3(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");

    if (contain4(stra, strb))
        printf("%s contain %s\n", stra, strb);
    else
        printf("%s not contain %s\n", stra, strb);

    if (contain4(stra, strc))
        printf("%s contain %s\n", stra, strc);
    else
        printf("%s not contain %s\n", stra, strc);

    printf("\n");*/

    if (contain4("a", "A"))
        printf("a contain A in bit hack method\n");

    /*
     if(contain5("Ab","b")){
     printf("%s contain %s\n",stra,strb);
     }else{
     printf("%s not contain %s\n",stra,strb);
     }
     printf("\n");
     */
    return 0;
}