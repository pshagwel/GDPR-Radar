#define CONCLUSION "conclusion.txt"
#define PHRASES "./srcs/phrases_rus.txt"
#include "gdpr.h"

int main (int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid argument, please write one file name of a document to check\n");
        exit(0);
    }
    
    char *document = NULL;
    int ph = open(PHRASES, O_RDONLY);
    if (!ph)
    {
        printf("Can't open %s file, please add to current directory (near 'gdpr' file)\n", PHRASES);
        perror("");
        exit(1);
    }
    char *phrase = NULL;
    int len_ph;
    char *result = NULL;
    FILE *conclusion = fopen(CONCLUSION, "w");
    if (!conclusion)
    {
        printf("Can't create %s file\n", CONCLUSION);
        perror("");
        exit(1);
    }
    int all_ph = 0;
    int not_ph = 0;
    while ((len_ph = get_next_line(ph, &phrase)) > 0)
    {
        int fd = open(argv[1], O_RDONLY);
        if (!fd)
        {
            printf("Can't open file, please check validity\n");
            perror("");
            exit(1);
        }
        all_ph++;
        int ret;
        result = NULL;
        int not_found = 1;
        while(not_found && (ret = get_next_line(fd, &document)) > 0)
        {
            result = strstr(document, phrase);
            if (result)
                not_found = 0;
            free(result);
            result = NULL;
        }
        if (not_found)
        {
            not_ph++;
            fwrite(phrase, strlen(phrase), 1, conclusion);
            fwrite("\n", 1, 1, conclusion);
        }
        close(fd);
    }
    fclose(conclusion);
    close(ph);
    return (0);
}