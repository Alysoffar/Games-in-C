#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int counter=0;
int answer;
int random_number;
int checking_procedure(char answer);
void random_no(int lower,int upper);
int main()
{
    int upper_limit;
    int lower_limit;
    bool checking_value=true;
    int answer_checked;
    int user_repeatition_answer;
    bool again=true;
    printf("Guess the Number Game\n");
    while (again){
        printf("Please enter the limit:\n");
        scanf("%d",&lower_limit);
        scanf("%d",&upper_limit);
        while (true){
            if(lower_limit>upper_limit){
                printf("Please enter the lower limit first\n");
                scanf("%d",&lower_limit);
                scanf("%d",&upper_limit);
            }
            else{
                break;
            }
        }
        while(true){
            if (upper_limit-lower_limit<10){
                printf("Small range enter a bigger one\n");
                scanf("%d",&lower_limit);
                scanf("%d",&upper_limit);
            }
            else{
                break;
            }
        }
        printf("You have selected a number between %d and %d \n",lower_limit,upper_limit);
        printf("Try to guess the number\n");
        srand(time(0));
        random_number=(rand()%(upper_limit+lower_limit));
        scanf("%d",&answer);
        answer_checked=checking_procedure(answer);
        printf("Do you want to play again? (1 for yes,0 for no)\n");
        scanf("%d",&user_repeatition_answer);
        while(true){
                if (user_repeatition_answer==1 || user_repeatition_answer==0){
                    break;
            }
                else {
                    printf("please enter a valid input\n");
                    scanf(" %d",&user_repeatition_answer);
            }
        }

        if (user_repeatition_answer==1){
            again=true;
            counter=0;
        }
        else if(user_repeatition_answer==0){
                break;
        }
    }
    return 0;
}
int checking_procedure(char answer){
    while (true){
        if (answer==random_number){
            printf("Congratulations! You guessed the correct number (%d) in %d attempts\n",answer,counter);
            break;
        }
        else if(answer>random_number){
             printf("Too high. Try again\n");
             scanf("%d",&answer);
             counter+=1;
        }
        else{
            printf("Too low. Try again\n");
            scanf("%d",&answer);
            counter+=1;
        }

    }
    return counter;
}
