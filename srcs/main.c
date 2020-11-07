#define CONCLUSION "conclusion.txt"
#define PHRASES "phrases.txt"
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
    char *tmp3 = "Missing phrases are:\n\n";
    fwrite(tmp3, strlen(tmp3), 1, conclusion);
    int all_ph = 0;
    int not_ph = 0;
    int i;
    while ((len_ph = get_next_line(ph, &phrase)) >= 0)
    {
        all_ph++;
        i = 0;
        while (phrase[i] != '\0')
        {
            phrase[i] = tolower(phrase[i]);
            i++;
        }
        int fd = open(argv[1], O_RDONLY);
        if (!fd)
        {
            printf("Can't open file, please check validity\n");
            perror("");
            exit(1);
        }
        int ret;
        result = NULL;
        int not_found = 1;
        while(not_found && (ret = get_next_line(fd, &document)) >= 0)
        {
            i = 0;
            while (document[i] != '\0')
            {
                document[i] = tolower(document[i]);
                i++;
            }
            result = strstr(document, phrase);
            if (result)
                not_found = 0;
            free(document);
            document = NULL;
            if (ret == 0)
                break ;
        }
        if (not_found)
        {
            not_ph++;
            char *num = ft_itoa(not_ph);
            fwrite(num, strlen(num), 1, conclusion);
            free(num);
            num = NULL;
            fwrite(". ", 2, 1, conclusion);
            fwrite(phrase, strlen(phrase), 1, conclusion);
            fwrite("\n", 1, 1, conclusion);
        }
        free(phrase);
        phrase = NULL;
        close(fd);
        if (len_ph == 0)
            break ;
    }
    int sum = (float)(all_ph - not_ph)/all_ph * 100;
    char *sum_ch = ft_itoa(sum);
    char *tmp2 = "\nThe result: ";
    fwrite(tmp2, strlen(tmp2), 1, conclusion);
    fwrite(sum_ch, strlen(sum_ch), 1, conclusion);
    char *tmp = "% of the necessary phrases are included in the document.\n";
    fwrite(tmp, strlen(tmp), 1, conclusion);
    free(sum_ch);
    sum_ch = NULL;
    fclose(conclusion);
    close(ph);
    return (0);
}