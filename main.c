#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//1=Rock
//2=paper
//3=scissors
char processing(char user_answer);
int random_computer_choice;
int user_answer;
int counter=0;
int main()
{
    int output;
    int again;
    printf("Hello to Rock Paper Scissors Game!\n");
    while (true){
            printf("Please enter 1 for rock, 2 for paper , or 3 for scissors\n");
            srand(time(0));
            random_computer_choice= rand()%3+1;
            scanf("%d",&user_answer);
            output=processing(user_answer);
            while (true){
                    if(output==2){
                        printf("Please enter a valid input\n");
                        scanf("%d",&user_answer);
                        output=processing(user_answer);
                        }
                    else{
                        break;
                    }
            }
            if(output==1){
                    printf("You won, the computer chose: %d\n",random_computer_choice);
                    printf("You took %d attempts to beat the computer\n",counter);
             }
            else if(output==0){
                    printf("You lost, the computer chose: %d\n",random_computer_choice);
            }
            else if(output==-1){
                    printf("You and the computer have similar minds: %d\n",random_computer_choice);
            }
            printf("Do you want to play again?(Enter 1 for yes 0 for no)\n");
            scanf("%d",&again);
            while(true){
                if(again==1 || again==0){
                    break;
                }
                else{
                    printf("Please enter a valid input\n");
                    scanf("%d",&again);
                }
            }
            if(again==0){
                break;
            }

    }
    return 0;
}
char processing(char user_answer){
    if (user_answer==random_computer_choice){
        counter++;
        return -1;
    }
    else if (user_answer==1 && random_computer_choice==2){
        counter++;
        return 0;

    }
    else if (user_answer==1 && random_computer_choice==3){
        return 1;
    }
    else if (user_answer==2 && random_computer_choice==1){
        return 1;
    }
    else if (user_answer==2 && random_computer_choice==3){
        counter++;
        return 0;
    }
    else if (user_answer==3 && random_computer_choice==1){
        counter++;
        return 0;
    }
    else if (user_answer==3 && random_computer_choice==2){
        return 1;
    }
    else{
        return 2;
    }
}
