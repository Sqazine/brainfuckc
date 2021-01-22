#ifndef LEXER_H
#define LEXER_H
#include "list_node.h"
#include <string.h>
#include <stddef.h>
typedef enum
{
    TOKEN_GREATER,       //>
    TOKEN_LESS,          //<
    TOKEN_ADD,           //+
    TOKEN_SUB,           //-
    TOKEN_DOT,           //.
    TOKEN_COMMA,         //,
    TOKEN_BRACKET_LEFT,  //[
    TOKEN_BRACKET_RIGHT, //]
    TOKEN_INVALID,       //other
} token;

token mapping(char c)
{
    switch (c)
    {
    case '>':
        return TOKEN_GREATER;
    case '<':
        return TOKEN_LESS;
    case '+':
        return TOKEN_ADD;
    case '-':
        return TOKEN_SUB;
    case '.':
        return TOKEN_DOT;
    case ',':
        return TOKEN_COMMA;
    case '[':
        return TOKEN_BRACKET_LEFT;
    case ']':
        return TOKEN_BRACKET_RIGHT;
    default:
        return TOKEN_INVALID;
    }
}

list_node *lexer(const char *str)
{
    list_node *head = create_node(mapping(str[0]));
    head->prev = NULL;
    head->next = NULL;
    list_node *p = head;
    for (size_t i = 1; i < strlen(str); ++i)
    {
        token t = mapping(str[i]);
        if (t != TOKEN_INVALID)
        {
            list_node *node = create_node(t);
            node->prev = p;
            node->next = NULL;
            p->next = node;
            p = p->next;
        }
    }
    return head;
}

list_node *interpreter(list_node *head)
{
    list_node *result = create_node(0);
    result->prev = NULL;
    result->next = NULL;
    list_node *p = head;
    list_node *cur = result;
    while (p)
    {
        switch (p->value)
        {
        case TOKEN_ADD:
            cur->value += 1;
            break;
        case TOKEN_SUB:
            cur->value -= 1;
            break;
        case TOKEN_DOT:
            putchar(cur->value);
            break;
        case TOKEN_COMMA:
            cur->value = getchar();
            break;
        case TOKEN_GREATER:
            if (cur->next == NULL)
            {
                list_node *tmpNode = create_node(0);
                tmpNode->next = NULL;
                tmpNode->prev = cur;
                cur->next = tmpNode;
            }
            cur = cur->next;
            break;
        case TOKEN_LESS:
            if (cur->prev == NULL)
            {
                list_node *tmpNode = create_node(0);
                tmpNode->next = cur;
                tmpNode->prev = NULL;
                cur->prev = tmpNode;
                result = tmpNode;
            }
            cur = cur->prev;
            break;
        case TOKEN_BRACKET_LEFT:
            if(cur->value==0)
            {
                while(p->value!=TOKEN_BRACKET_RIGHT)
                    p=p->next;
            }
            break;
        case TOKEN_BRACKET_RIGHT:
            if(cur->value!=0)
            {
                while(p->value!=TOKEN_BRACKET_LEFT)
                    p=p->prev;
            }
            break;
        default:
            break;
        }
        p = p->next;
    }
    return result;
}

#endif