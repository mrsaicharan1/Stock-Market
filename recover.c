


#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    
    FILE* infile;
    infile = fopen("card.raw", "r");



    char buf[512] = {0};                    
    char jpeg[4] = {0xff, 0xd8, 0xff, 0xe0};    
    char jpeg2[4] ={0xff, 0xd8, 0xff, 0xe1};    
    
    char filename[30];                          
    int filenumber = 0;                         
    FILE* outfile;                          
    int c = 0;

    while (c != EOF) {

     
        for (int v = 0; v < 512; v++) {
            buf[v] = c = fgetc(infile);
        }

        if (memcmp(buf, jpeg, 4) == 0||memcmp(buf,jpeg2,4)==0 ) {
            if (outfile)
        {    
            fclose(outfile);
}
if (!outfile) {
                printf("Error \n");
                return 1;
}
            
               if (!outfile) {
                printf("Error \n");
                return 1;
}
            int name;
            filenumber++;
            name = sprintf(filename, "%03d.jpg", filenumber);

            
            outfile = fopen(filename, "w");

          
            fwrite(buf, 1, 512, outfile);

        } else if (outfile) {

           
            fwrite(buf, 1, 512, outfile);
        }
    }

    
    fclose(infile);
    if (outfile){ 
        fclose(outfile);
        
    }

    printf("Done.\n");

    return 0;
}


