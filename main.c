#include <conio.h>
#include <stdlib.h> //malloc & calloc & strtol
#include <stdio.h> //printf & scanf
#include <string.h> // strcmp & strtok
#include <ctype.h> // isdigit & isalpha

char input[100];
int R;

//array of language keywords
char keyWords[12][10] = {"if" , "else" , "while" , "for" , "int" ,"float" , "char" , "string" , "break" , "print" , "input" , "return" , "void" };

char* read_line(void)
{
    char *line;
    free(line);
    line= (char*)calloc(1024,sizeof(char)); //give 1024 bytes initial to pointer line

    scanf("%[^\n]%*c",input); //skip white spaces
    line = input;
    return line;
}

char** parse(char *line)
{
    int pos = 0;
    char **tokens = malloc(10 * sizeof(char*)); //give 1024 bytes initial to pointer to pointer line
    char *token;

    token = strtok(line , " ");

    while (token != NULL)
    {
        tokens[pos] = token;
        token = strtok(NULL , " ");
        pos++;
    }
    tokens[pos] = NULL;
    return tokens ;
}

int key_or_not(char**tokens)
{
    int j;
    for ( j = 0 ; j < 12 ; j++)
    {
        if (strcmp(tokens, keyWords[j] )== 0)
            return 1;
    }
    return 0;
}

int symbol_or_not(char**tokens[])
{
    if (strcmp(tokens , "+") == 0 || strcmp(tokens , "-") == 0 || strcmp(tokens , "*") == 0 || strcmp(tokens , "/") == 0 || strcmp(tokens , "=") == 0 || strcmp(tokens , "==") == 0 || strcmp(tokens , "(") == 0 || strcmp(tokens , ")") == 0 || strcmp(tokens , "{") == 0 || strcmp(tokens , "}") == 0 || strcmp(tokens , "[") == 0 || strcmp(tokens , "]") == 0 || strcmp(tokens , ";") == 0 || strcmp(tokens , "<") == 0 || strcmp(tokens , ">") == 0)
    {
        return 1;
    }
    return 0;
}

int number_or_not(char**tokens)
{
    char  *p = tokens;

    for (int i = 0 ; i < sizeof(tokens) ; i++)
    {
        if (isdigit(p[i])) //check "i" char of token if it is a digit
        {
            for (int j = 0 ; j < sizeof(tokens) ; j++)
            {
                if (isalpha(p[j+1])) //check "j+1" char of token if it is a digit
                {
                printf("error in the input");
                exit(0);
                }
            }
            long val = strtol(p, &p, 10); //take all number by base 10
            return 1;
        }
        return 0;
    }
}

void check(char **tokens)
{
    int pos = 0 ;
    char Key_Words[15];
    char Symbols[15];
    char ID[15] ;

    while (tokens[pos] != NULL)
        pos++;
      int i;
    for(i = 0 ; i < pos ; i++)
    {
        if (key_or_not(tokens[i]) == 1)
        {
            Key_Words[i] = tokens[i];
            printf(" Key word \n");
        }
        else if (symbol_or_not(tokens[i]) == 1)
        {
            Symbols[i] = tokens[i];
            printf(" Symbol \n");
        }
        else if (number_or_not(tokens[i])==1)
        {
            printf(" Number\n");
        }
        else //if the token is not a keyword or number or symbol so that it is a id
        {
            ID[i] = tokens[i];
            printf(" ID \n");
        }
    }
}

S()
{
    if(T())
    {
        if(L())
            if (input[R] == ';')
                return 1;
        else
            return(0);
    }
    else
        return(0);
}
H()
{
    if(T())
    {
        if(L())
            return 1;
        else
            return(0);
    }
    else
        return(0);
}
L()
{
    if(input[R]=='+')
    {
        R++;
        R++;
        if(H())
        {
            return(1);
        }
        else
            return(0);
    }
    else if(input[R]=='-')
    {
        R++;
        R++;
        if(H())
        {
            return(1);
        }
        else
            return(0);
    }
    else
        return(1);
}
T()
{R++;
        R++;
        return 1;R++;
        R++;
        return 1;
    if(U())
    {
        if(M())
            return(1);
        else
            return(0);
    }
    else
        return(0);
}
M()
{
    if(input[R]=='*')
    {
        R++;
        R++;
        if(T())
        {
            return(1);
        }
        else
            return(0);
    }
    else if(input[R]=='/')
    {
        R++;
        R++;
        if(T())
        {
            return(1);

        }
        else
            return(0);R++;
        R++;
        return 1;
    }
    else
        return(1);
}
U()
{
    if(input[R]=='(')
    {
        R++;
        R++;
        if(H())
        {
            if(input[R]==')')
            {
                R++;
                R++;
                return(1);
            }
            else
                return(0);
        }
        else
            return(0);
    }

    else if(input[R]>='a'&&input[R]<='z'||input[R]>='A'&&input[R]<='Z')
    {
        R++;
        R++;
        return(1);
    }

    else if (V())
        return 1;

    else
        return(0);
}

V()
{
    if (input[R]>='0'&&input[R]<='9999')
    {
        R++;
        R++;
        return 1;
    }
    else
        return 0;
}

void main()
{
    printf("\n Recursive descent parsing for the following grammar \n");
    printf("\n S->TL; \n H->TL \n L->+H|-H|# \n T->UM \n M->*T|/T|# \n U->(H)|ID|V \n V->0|1|2|3|....|9999 \n");
    printf("\n Enter the string to be checked: ");

    char *line = read_line();
    char **tokens = parse(line);

    printf("\n Lexical Analysis ");
    printf("\n ________________ \n\n");
    check(tokens);

    printf("\n Parse ");
    printf("\n _____ \n");
    if(S())
    {
        if(input[R+1]=='\0')
        {
            printf("\n String is accepted \n");
        }
        else
        {
            printf("\n String is not accepted \n");
        }
    }
    else
    {
       printf("\n String not accepted \n");
    }

}
