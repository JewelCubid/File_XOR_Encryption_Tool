#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
//variable initialisation
    char newFilename[19] = "new-";
    char* filename = argv[1];
    char* password = argv[2];
    int digitPresent;

//concatenates new- and filename
    strcat(newFilename, filename);

//finds length of password
    int passLen = strlen(password);

    printf("newFileName = %s\n", newFilename);
    printf("password length = %d\n", passLen);

//loops and goes through password to check if isdigit = FALSE
    for (int i = 0; i < passLen; i++) {
        digitPresent = isdigit(password[i]);

//breaks from loop when digit is present
        if (digitPresent != 0) {
            digitPresent = 1;
            break;
        }
    }

//checks if password is valid
    if (passLen < 8) {
    	printf("The password needs to have at least 8 characters.\n");
    	if (digitPresent != 1) {
        	printf("The passwords needs to contain at least one digit.\n");
	}
    } else if (digitPresent != 1) {
        printf("The passwords needs to contain at least one digit.\n");
    }
} 
