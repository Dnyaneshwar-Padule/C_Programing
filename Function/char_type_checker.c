#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int take_input(char*);
void check_type(char);

int main()
{
   
    char character = '\0';

    if (take_input(&character))
    {    
        check_type(character);
    }
    else
    {
        printf("Invalid input !\n");
        clear_buffer();
    }

    return SUCCESS;
}

void clear_buffer()
{
    char ch;
    while (  (ch = getchar()) != '\n' && ch != EOF );
}

int take_input(char *character)
{
    printf("Enter a character  :");
    return scanf("%c", character);
}

void check_type(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        printf("%c is a Capiltal letter. \n", ch);
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        printf("%c is a small letter. \n", ch);
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("%c is a digit. \n", ch);
    }
    else
    {
        printf("%c is a special symbol. \n", ch);
    }
    
}