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

//loops and goes through password to check if isdigit = FALSE
    for (int i = 0; i < passLen; i++) {
        digitPresent = isdigit(password[i]);

//breaks from loop when digit is present
        if (digitPresent != 0) {
            digitPresent = 1;
            break;
        }
    }

    FILE *file, *newFile;
    char block[passLen];
    int i, numBytes, count;
    count = 0;
    
//opening files
    file = fopen(filename, "rb");
    newFile = fopen(newFilename, "wb");

//implementing encryption
    do {
        numBytes = fread(block, 1, passLen, file);
        for (i = 0; i < numBytes; i++) {
            block[i] = block[i] ^ password[i];

//prints the first 5 bytes
            if (count < 5) {
                printf("%02x\n", (unsigned char)block[i]);
                count++;
            }
        }

//writing to newFile
        fwrite(block, 1, numBytes, newFile);
    } while (numBytes == passLen);
    fclose(newFile); fclose(file);
} 
