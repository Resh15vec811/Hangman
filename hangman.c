
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OF_WORDS   25
#define NUM_OF_CHANCES 5
#define TRUE           1
#define FALSE          0


void show_heading_rules();
void scold_and_quit();
void see_in_word(char, const char [], char *, const size_t, unsigned int *);
void show_word_clue(const size_t);



void show_heading_rules()
{
    printf("\t\t\t\tHANGMAN\n\n");
    printf("Hangman is a game where you are expected to guess a word in a certain number of chances before you hang the hangman.\n\n");

    printf("A word has been chosen, begin guessing it. Good luck\n\n");
    printf("Guess the Word: ");
}


void scold_and_quit()
{
    printf("\n\nYou killed a person, Better luck next time :) ! Good Bye.\n\n");
    main();
}


void show_word_clue(const size_t len)
{
    size_t i;
    for(i = 0; i < len; i++)
        printf(" _ ");
    printf("\n\n");
}


void see_in_word(char guessed, const char word[], char *a, const size_t len, unsigned int *found)
{
    size_t i;
    int flag=0;

    for(i = 0; i < len; i++)
    {
        if(guessed == word[i])
        {

            *(a + i) = guessed;
            *found = TRUE;
        }
        else
        {



            if(*(a + i) >= 65 && *(a + i) <= 90 ) ;
            else if(*(a + i) >= 97 && *(a + i) <= 122) ;
            else *(a + i) = '_';
        }
    }

    for(i = 0; i < len; i++)
    {
        printf("%c ", *(a + i));
        if(*( a+i )!=word[i])
        {
        	flag=1;
        }
    }
    if(flag==0)
    {
    	printf("success\n");
    	main();
    }

  /*  if(strcmp(a, word) == 0)
    {
        printf("\n\nYou did it. Well done.\n\n");
       main();
    }
*/


}

int main()
{

    char *hanged[]={
                     "|=====|\n"
                     "      |\n"
                     "      |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "      |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "|     |\n"
                     "      |\n"
                     "     ===\n",
                     "|=====|\n"
                     "O     |\n"
                     "|     |\n"
                     "|     |\n"
                     "     ===\n",
                     " |=====|\n"
                     " O     |\n"
                     " |     |\n"
                    "/ \\    |\n"
                     "     ===\n"

    };

    char *words[] = {
                      "AUTO","CONST","BREAK","CHAR","CONTINUE","DEFAULT", "DO", "DOUBLE",
                       "ELSE", "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF",
                        "INT", "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC","STRUCT","SWITCH","TYPEDEF","UNION","UNSIGNED","VOID","VOLATILE","WHILE"

    };
 

  int ch;
  printf("enter 1 to play : enter 2 to exit");
  scanf("%d",&ch);
  if(ch==1)
  {
  
    show_heading_rules();


    srand((unsigned) time(NULL));
    unsigned short chosen_word = rand() % NUM_OF_WORDS;


    char guessed;
    size_t len = strlen(words[chosen_word]);
    size_t i = 0;
    unsigned int found = FALSE;
    unsigned int chances = 0;



    show_word_clue(len);


    char *a = (char *)malloc(len + 1);

    printf("\nGuess a letter: ");

        while(1)
    {

        guessed = toupper(getchar());

        if(guessed != '\n'){
            printf("\nGuess a letter: ");

            see_in_word(guessed, words[chosen_word], a, len, &found);


            if(found == FALSE)
            {
                if(chances >= 4)
                {
                    printf("\n\n%s\n\n", hanged[chances++]);
                    scold_and_quit();
                }

                printf("\n\nPlease try again :(\n");
                printf("\n\n%s\n\n", hanged[chances++]);
            }

            found = FALSE;
        }
    }
}
else
{
	exit(0);

}
}
