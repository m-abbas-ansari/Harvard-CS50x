#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;
int fcount = 0;


void crtjpg(BYTE b[], FILE* f);

int main(int argc, char *argv[])
{
    //Check for atleast one CL argument
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //Opening forensic image file
    FILE* read = fopen(argv[1], "r");
    FILE* write;
    //Check for successful open
    if(read == NULL)
    {
        printf("Image cannot be opened\n");
        return 1;
    }
    BYTE b[512];
    fread(b, sizeof(BYTE), 512, read);
    while(!feof(read))
    {
        //Checking for JPEG signature
        if((b[0] == 0xff) && (b[1] == 0xd8) && (b[2] == 0xff) && ((b[3] >= 0xe0) && (b[3] <= 0xef)))
        {
            crtjpg(b, read);
        }
        else
        {
            fread(b, sizeof(BYTE), 512, read);
        }

    }

}

void crtjpg(BYTE b[], FILE* f)
{   
    char* fname =  malloc(13);
    if(fcount < 10)
    {
        sprintf(fname, "00%i.jpeg", fcount);
    }
    else if((fcount > 9) && (fcount < 100))
    {
        sprintf(fname, "0%i.jpeg", fcount);
    }
    else if(fcount > 99)
    {
        sprintf(fname, "%i.jpeg", fcount);
    }
    
    fcount++;
    FILE *write = fopen(fname, "w");
    fwrite(b, sizeof(BYTE), 512, write);
    fread(b, sizeof(BYTE), 512, f);
    while(!((b[0] == 0xff) && (b[1] == 0xd8) && (b[2] == 0xff) && ((b[3] >= 0xe0) && (b[3] <= 0xef))))
    {
        fwrite(b, sizeof(BYTE), 512, write);
        fread(b, sizeof(BYTE), 512, f);
    }
    fclose(write);
    free(fname);
}
