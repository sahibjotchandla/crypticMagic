#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int enc(void);
int dec(void);
int showenc(void);
int showdec(void);

FILE *fpE, *fpD;
char read[250];
int size;
int i = 1, j, temp;
long int decNum, rem, quo;

char hexadecNum[500];
int number[250];

int main(){

    int option;

    while(1){
        printf("\nSelect one of the following options:\n");
        printf("1. Encrypt\n");
        printf("2. Read Encrypted File\n");
        printf("3. Decrypt\n");
        printf("4. Read Decrypted File\n");
        printf("5. Exit Program\n");
        printf("\nPlease make your selection: ");

        scanf("%d", &option);

        switch(option){
            case 1: enc();
            break;
            case 2: viewenc();
            break;
            case 3: dec();
            break;
            case 4: viewdec();
            break;
            case 5: exit(1);
            }
        }
    return 0;
}

int enc(){
    printf("\n");
   
    fpE = fopen("myFile.txt","r");
        if(fpE == NULL){
            printf("Text File not found\n");
    }

    fpD = fopen("myFile.crp","w");
        if(fpD == NULL){
            printf("Encrypted File not found\n");
    }
    
    for(int j = 0; j<250; j++){
        read[j] = fgetc(fpE);
    }

    size = strlen(read);

    for(int i = 0; i<size; i++){
        number[i] = read[i] - 16;
        if(number[i]<32){
            number[i] = (number[i]-32)+144;
        }
        if(read[i] == EOF){
            printf("\nThis is the end of the file\n");
            break;
        }
    }

    for (int k = 0; k<size; k++){
        if(number[k]==((10-16)-32)+144){
            hexadecNum[i++] = 'a';
            hexadecNum[i++] = '0';
        }
        else if(number[k] == ((9-16)-32)+144){
            hexadecNum[i++] = 'T';
            hexadecNum[i++] = 'T';
        }
        else{
            quo = number[k];
            while(quo!=0){
                temp = quo % 16;
                if(temp <10){
                    temp = temp + 48;
                }
                else{
                    temp = temp + 55;
                }

                hexadecNum[i++] = temp;
                quo = quo/16;
            }
        }
    }

    char tempor;
    for(j = 1; j<i;j++){
        if(j%2==1){
            tempor = hexadecNum[j];
            hexadecNum[j] = hexadecNum[j+1];
            hexadecNum[j+1] = tempor;
        }
    }

    for(j=1; j<i-2;j++){
            fputc(hexadecNum[j],fpD);
    }

    fclose(fpE);
    fclose(fpD);
    printf("\n\n\n");
    return 0;
}

int viewenc(){
    printf("\n");

    fpE = fopen("myFile.crp","r");
        if(fpE == NULL){
            printf("There is no file to be read\n");
            exit(1);
    }

    else{
        for(int i = 0; i<250; i++){
            read[i]= fgetc(fpE);
        }

        size = strlen(read);

        printf("Encrypted Message: \n");
        for (int k = 0; k<size; k++){
            if(read[k] == EOF){
                break;
            }

            else{
                if(read[k] == '0' && read[k+1] == 'a'){
                    printf("\n");
                    k+=2;
                }
                printf("%c", read[k]);
            }
        }
        printf("\n");
        fclose(fpE);
    }

    printf("\n\n\n");
    return 0;
}

int dec(){

    printf("\n");

    fpE = fopen("myFile.txt","r");
        if(fpE == NULL){
            printf("Source File is not being read\n");
    }
    fpD = fopen("myFile.crp","w");
        if(fpD == NULL){
            printf("Target File is not being read\n");
    }

    for(int j = 0; j<250; j++){
        read[j] = fgetc(fpE);
    }
    size = strlen(read);

    for(int i = 0; i<size; i++){
        if(read[j] == EOF){
            printf("\nThis is the end of the file\n");
            break;
        }
    }

    for(int k = 0; k<size; k++){
        fputc(read[k], fpD);
    }

    fclose(fpE);
    fclose(fpD);
    printf("\n\n\n");
    return 0;
}

int viewdec(){
    printf("\n");

    fpE = fopen("myFile.txt","r");
        if(fpE == NULL){
            printf("There is no file found\n");
            exit(1);
    }

    else{
        for(int i = 0; i<250; i++){
            read[i]=fgetc(fpE);
        }

        size = strlen(read);

        printf("Decrypted Message: \n");
            for (int k = 0; k<size; k++){
                if(read[k] == EOF){
                    break;
            }

            else{
                if(read[k] == '0' && read[k+1] == 'a'){
                    printf("\n");
                    k+=2;
                }
                printf("%c", read[k]);
            }
        }

    printf("\n");
    fclose(fpE);
    }
    return 0;
    printf("\n\n\n");
}