#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define INPUTFILE "sng_msg_58_no_align.txt"//"EncryptedFile.txt"
#define OUTPUTFILE "DecryptedFile.txt"

int main(){
        unsigned int v0, v1, sum=0xC6EF3720, i;//set up
        unsigned int delta=0x9e3779b9;//a key schedule constant
        unsigned int k0=0xf71850f5, k1=0x5db8544a, k2=0xbf5ecf69, k3=0xcb93ef85;//password
        // unsigned int k0=0x85ef93cb, k1=0x69cf5ebf, k2=0x4a54b85d, k3=0xf55018f7;//password by Little Endian 

        //unsigned int k0=0x62373761, k1=0x35633536, k2=0x31393334, k3=0x65303839;//public key
        FILE * inputFile;
        FILE * outputFile;
 int n;
 
 //open a file
 inputFile = fopen( INPUTFILE , "r");
 if (inputFile == NULL) {
         printf("EncryptedFile failed to open file.\n");
         return -1;
 }

 outputFile = fopen( OUTPUTFILE , "w");
 if (outputFile == NULL) {
         printf("DecryptedFile failed to open file.\n");
         return -1;
 }

 while (! feof(inputFile)) {
         fscanf(inputFile, "%x %x\n", &v0, &v1);
         for(i=0; i<32; i++){//basic cycle start
                 v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
                 v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
                 sum -= delta;
   }//end cycle
         fprintf(outputFile, "%x %x\n", v0, v1);
 }

 fclose( inputFile ); 
 fclose( outputFile ); 
 return 0;
}
