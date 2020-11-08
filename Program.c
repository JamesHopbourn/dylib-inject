/* ====================================================
#   Copyright (C) 2020 All rights reserved.
#
#   Author        : James Hopbourn
#   Email         : JamesHopbourn@gmail.com
#   File Name     : testProgram.c
#   Last Modified : 2020-10-29 12:04
#   Describe      : 
#
# ====================================================*/

#define CS_RESTRICT      0x0000800  /* tell dyld to treat restricted */
#define CS_REQUIRE_LV       0x0002000  /* require library validation */
#define CS_RUNTIME       0x00010000  /* Apply hardened runtime policies */

#include <stdio.h>

int hookTargetFunction() {
	printf("Calling original function!\n");
    return 5;
}

int main() {
	char str[100];
	printf("The number is: %d\n", hookTargetFunction());
	printf("请输入密码：");
	gets(str);
	printf("%s\n", str);
    return 0;
}
