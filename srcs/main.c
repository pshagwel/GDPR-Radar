#define CONCLUSION "conclusion.txt"
#define PHRASES "./srcs/phrases_rus.txt"
#include "gdpr.h"

//check input file, parsing -> error messages
//gnl + algorythm
//return answer in a file answer.txt

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid argument, please write one file name of a document to check\n");
        exit(0);
    }
    FILE *fd = fopen(argv[1], "r");
    if (!fd)
    {
        printf("Can't open file, please check validity\n");
        perror("");
        exit(1);
    }
    char *document = NULL;
    int len = fscanf(fd, "%s", document);
    //TODO: check the limit of the size for str, len == EOF
    if (len != EOF)
    {
        printf("Reduce the size of the file or connect developers\n");
        fclose(fd);
        exit(1);
    }
    FILE *ph = fopen(PHRASES, "r");
    if (!ph)
    {
        printf("Can't open %s file, please add to current directory (near 'gdpr' file)\n", PHRASES);
        perror("");
        exit(1);
    }
    char *phrase = NULL;
    int len_ph;
    char *result = NULL;
    FILE *conclusion = fopen(CONCLUSION, "a");
    if (!conclusion)
    {
        printf("Can't create %s file\n", CONCLUSION);
        perror("");
        exit(1);
    }
    int all_ph = 0;
    int not_ph = 0;
    while ((len_ph = fscanf(conclusion, "%s\n", phrase)) > 0)
    {
        all_ph++;
        result = strstr(document, phrase);
        if (result == NULL)
        {
            //TODO: add to file
            not_ph++;
            fwrite(phrase, strlen(phrase), 1, conclusion);
        }
    }
    fclose(conclusion);
    fclose(ph);
    fclose(fd);
    return (0);
}