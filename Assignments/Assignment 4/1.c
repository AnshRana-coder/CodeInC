/*Rock Paper Scissor (which is also called Stone Paper 
Scissor) is a hand game and played between two people, in 
which each player simultaneously forms one of three shapes.  
The winner of the game is decided as per the below rules: 
• Rock vs Paper -> Paper wins. 
• Rock vs Scissor -> Rock wins. 
• Paper vs Scissor -> Scissor wins. 
In this game, the user will be asked to make choice and 
according to the choice of user and computer and then the 
result will be displayed along with the choices of both computer 
and user. 
Note: This random number will decide the choice of computer 
as: 
• If the number is between 0-33 then the choice will be 
Stone. 
• If the number is between 33-66 then the choice will be 
Paper. 
• If the number is between 66-100 then the choice will be 
Scissors.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userChoice, computerChoice;
    int randomNum;
    

    srand(time(0));
    
    printf("Welcome to Rock, Paper, Scissors Game!\n");
    printf("Choose one of the following options:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &userChoice);

    randomNum = rand() % 3 +1;
    
    printf("You chose: ");
    if (userChoice == 1) printf("Rock\n");
    else if (userChoice == 2) printf("Paper\n");
    else if (userChoice == 3) printf("Scissors\n");

    printf("Computer chose: ");
    if (computerChoice == 1) printf("Rock\n");
    else if (computerChoice == 2) printf("Paper\n");
    else if (computerChoice == 3) printf("Scissors\n");

    if (userChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||  
               (userChoice == 3 && computerChoice == 2)) {  
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}
