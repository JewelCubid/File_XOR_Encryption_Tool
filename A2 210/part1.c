#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
//variable initialisation
    char newFilename[19] = "new-";
    char* filename = argv[1];
    char* password = argv[2];

//concatenates new- and filename
    strcat(newFilename, filename);

//finds length of password
    int passLen = strlen(password);

    printf("newFileName = %s\n", newFilename);
    printf("password length = %d\n", passLen);
}