#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[20];
    printf("Enter the IP address: \n");
    scanf("%s", ip);
    int len = strlen(ip);

    char arr[5] = {0};
    int ans[2] = {0};

    for (int i = 0; i < len; i++) {
        if (ip[i] == '.') {
            arr[i] = '\0'; // Null-terminate the string before converting to integer
            ans[0] = atoi(arr);
            break;
        }
        arr[i] = ip[i];
    }

    if (ans[0] != 0 && ans[0] <= 127)
        printf("Class A IP address.\n");
    else if (ans[0] >= 128 && ans[0] <= 191)
        printf("Class B IP address.\n");
    else if (ans[0] >= 192 && ans[0] <= 223)
        printf("Class C IP address.\n");
    else if (ans[0] >= 224 && ans[0] <= 239)
        printf("Class D IP address.\n");
    else
        printf("Invalid IP address.\n");

    return 0;
}
