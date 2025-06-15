/*
    Make a program which can do following task :-

    execute program by taking file action (encryption or decryption) and file name as input from command prompt(as command line argument)
        ex.)a.exe encrypt source.png
            a.exe decrypt source.png

           1)Encryption :
                Get Username and key ( integer number as a key ) then encrypt the file
                    encryption :-
                                make a new binary file copy the content by encrypting , once all done then 
                                close both files delete the original file and rename the encrypted file to the original file.
                Then store the Username and key for the respective file by appending data but before that encrypt them by your unique key
                open .main.hid rename as main.txt and then append the encrypted data in main.txt and then rename main.txt as .main.hid
                and complete the program .

            2)Decryption :
                    You already have the filename , so take the username and key from user for respective file 
                    and find them in your .main.hid if data find then decrypt the file by using the key
                    decryption :-
                                make a new binary file take data from encrypted file and copy the decrypted data in new file 
                                once you copied all the data , close both files, delete encrypted file and rename decrypted file
                                as the name of encrypted file . Then complete the program

            Important note :- 
                    While making a new file , take care that the type of new file and source file should be same .
                    i.e. , both files should have same extension
                                                     
                                                          Solution:-          
                    ex.)Source file :- a.mp4                        Source file :- a.mp4
                        New file    :- temp.mp4                     New file    :- 1a.mp4
                 
                        Source file :- b.mp3                        Source file :- b.mp3
                        New file    :- temp.mp3                     New file    :- 1b.mp3

            If you don't know how to encrypt ,check this out
                    suppose num is a int variable and it is assigned to 12
                    then to encrypt the data in num , you can use bitwise Ex-or (^) operator
                        like this :- num ^ key or num ^ 10 (key = 10)
                        Now the num has value 6 and hence the dat ais encrypted 

                        and to DECRYPT the data repeate the same operation 
                            i.e. , num ^ key ( 6 ^ 10 )
                            then you will get 12 , i.e. your original data
                            You can do it with char data type 

            So in this way , you can encrpt and decrypt the data , 
            But note thet if the kay mismatches , you can lost your data permanentely . 
                So here, key is very importent . 

        Can you make it 
        Don't tell no , before trying .
        Try !!

*/

#include <stdio.h>
#include <stdlib.h>

void encryptFile(FILE *inputFile, FILE *outputFile, unsigned char key) {
    int ch;

    while ((ch = fgetc(inputFile)) != EOF) {
        unsigned char encryptedByte = ch ^ key; // XOR operation

        fputc(encryptedByte, outputFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    unsigned char key = (unsigned char)atoi(argv[3]);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        printf("Error: Unable to create output file.\n");
        fclose(inputFile);
        return 1;
    }

    encryptFile(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully with key %d.\n", key);

    return 0;
}
