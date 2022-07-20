#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

uint32_t readfile(char *argv){
    
    uint32_t num;

    FILE * fp = fopen(argv, "rb");
    fread(&num, sizeof(uint32_t), 1, fp);
    num = ntohl(num);
    fclose(fp);

    return num;
}


int main(int argc, char **argv){
    
    if (argc != 3){
        fprintf(stderr, "add-nbo <file1> <file2>\n");
    }

    uint32_t num1 = readfile(argv[1]);
    uint32_t num2 = readfile(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, num1+num2, num1+num2);
}
