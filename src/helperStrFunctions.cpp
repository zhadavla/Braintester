#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToCStr(int num) {
    int i = 0, j = 0, k = 0;
    char temp;
    
    char *str = (char*) malloc(sizeof(char) * 5);
//    if (!str) return NULL; /
    
    if (num < 0) { 
        str[k++] = '-';
        num = -num;
    }
    
    do { // convert integer to string
        str[i++] = num % 10 + '0';
        num /= 10;
    } while (num);
    
    str[i] = '\0'; // add null terminator
    
    if (str[0] == '-') { // reverse string excluding negative sign
        j = 1;
    }
    
    for (i -= 1; j < i; i--, j++) { // reverse string
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    return str; // return the string
}


char* makeEquationString(int x, int y, char operation) {
    char *str = (char*) malloc(sizeof(char) * 20);
    sprintf(str, "%d %c %d = ", x, operation, y); 
    return str; 
}
