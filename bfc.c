#include "list_node.h"
#include "interpreter.h"
#include <stdlib.h>
int main(int argc, char **argv)
{
    char *str = NULL;
    if (argc == 1)
    {
        printf(">>> ");
        char s[1000];
        while (fgets(s, 1000, stdin) != NULL)
        {
            list_node *head = lexer(s);
            interpreter(head);
            clear_node(head);
            printf("\n>>> ");
        }
    }
    else
    {
        str = argv[1];
#ifdef _WIN32
        FILE *fp;
        fopen_s(&fp, str, "rb");
#else
        FILE *fp = fopen(str, "rb");
#endif
        if (fp == NULL)
        {
            printf("cannot open file:%s", str);
            return -1;
        }
        fseek(fp, 0, SEEK_END);
        size_t fileLength = ftell(fp);
        char *content = (char *)malloc((fileLength) * sizeof(char));
        rewind(fp);
        fread(content, 1, fileLength, fp);
        if (content == NULL)
        {
            printf("empty content in file:%s", str);
            return -1;
        }
        list_node *head = lexer(content);
        interpreter(head);
        clear_node(head);
        fclose(fp);
    }
    return 0;
}