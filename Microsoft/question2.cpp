//
// Created by Isaac_Chen on 2020/9/21.
//
#include <string.h>
#include <stdio.h>

int main () {
    char str[80] = "This is - /l;kwww.runoob.com - website";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(str, s);

    /* 继续获取其他的子字符串 */
    while( token != NULL ) {
        printf( "%s\n", token );

        token = strtok(NULL, s);
    }

    return(0);
}