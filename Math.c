#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void save(int score);

int main (void){
    
    printf("Welcome.\n");
    
    printf("Hi Jolie\n");
    printf("Please select one from below:\n");
    printf("(1) Plus\n(2) Minus\n(3) Multiply\n");
    printf("Enter a number:\n");
    
    int input;
    scanf("%d",&input);
    
    
    int score = 0;
    
        srand(time(NULL));
        while (1){
            int count = 0;
            
            while (count < 11){
            
            printf("\n\n\n");
            int round = count + 1;
            printf("Round: %d\n",round);
            printf("Score: %d\n",score);
            
                
            
            int one; 
            int two;
            
            if (input == 3){
                one = rand()%5+1;
                two = rand()%5+1;
            }
            else {
                one = rand()%30+1;
                two = rand()%30+1;
            }
                
            if (one < two){
                one += two;
            }
            
            
            printf("\n\n\n");
            if (input == 1) printf("%d + %d = ???\n",one,two);
            if (input == 2) printf("%d - %d = ???\n",one,two);
            if (input == 3) printf("%d * %d = ???\n",one,two);
                
            printf("Your answer:");
                
            int answer;
            scanf("%d",&answer);
            
            
            int actual;
            if (input == 1) actual = one+two;
            if (input == 2) actual = one-two;
            if (input == 3) actual = one*two;
                
            if (answer == actual){
                score++;
                printf("Correct!\n");
            }
            else {printf("Wrong. Correct Answer is %d\n",actual);}
                
            if (count != 10){
                printf("Next...\n");
                count++;
            }
            
            if (count == 10){
                printf("\n\n\n");
                printf("Your score is %d\n",score);
                save(score);
                printf("Try again? (Y/N)\n");
                char response;
                scanf("%s",&response);
                if (response == 'y'){
                    count = 0;
                    score = 0;
                    printf("Still want to play like this or want to play it differently? (Y/N)\n");
                    char reply;
                    scanf("%s",&reply);
                    if (reply != 'y'){
                        printf("(1) Plus\n(2) Minus\n(3) Multiply\n");
                        scanf("%d",&input);
                    }
                }
                else {
                    return 0;
                }
                
            }
                
            }
        }
    }

void save (int score){
    FILE *file;
    char c;
    file = fopen("progress.txt","a+");
    fprintf(file,"%d\n",score);
    
    
    fclose(file);
}
