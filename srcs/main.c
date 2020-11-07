#include "gdpr.h"

//check input file, parsing -> error messages
//gnl + algorythm
//return answer in a file answer.txt

int main (int argc, char **argv)
{
    if (argv != 2)
    {
        printf("Invalid argument, please write one file name of a document to check\n");
        exit(0);
    }
    FILE *fd = fopen(argv[1], "r");
    if (!fd)
    {
        printf("Can't open file, please check validity\n");
        perror(errno);
        exit(0);
    }
    char *document = NULL;
    int len = fscanf("%s", &document);
    //TODO: check the limit of the size for str, len == EOF
    if (len != EOF)
    {
        printf("Reduce the size of the file or connect developers\n");
        fclose(fd);
        exit(1);
    }
    FILE *ph = fopen("phrases.txt", "r");
    while (len )
    {
        
    }
    fclose(fd);
    return (0);
}