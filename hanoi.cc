#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//These declarations are three poles A, B, C
#define user_source 'A'
#define user_dest 'C'
#define user_aux 'B'

//Function prototypes
void MoveTowerHanoi(int disc, char source, char dest, char aux, int nextFinalDisc);
void clearBuffer(void);

//Global file pointer for output file
FILE *f_output;





/***********************************************************************************
* Function:     main                                                               *
* Description:  Calls relevant logical functions to get solution of Tower of Hanoi.*
*               It keeps asking user for new game input till he chooses to quit.   *
*                                                                                  *
* Parameters:   void                                                               *
* Returns:      int                                                                *
************************************************************************************/

int main()
{
    int check;
    char user_choice = 'y';

    //Number of discs, and pointer to keep track of original value even when calling recursion
    int num_discs;
    //int *p_num_discs = &num_discs;

    //Open output file in append mode
    f_output = fopen("Output.doc", "w");

    //Check if file is opened correctly
    if (f_output != NULL)
    {
        printf("WELCOME TO PLAY TOWERS OF HANOI\n\n");
        fprintf(f_output, "WELCOME TO PLAY TOWERS OF HANOI\n\n");
        while (user_choice == 'y' || user_choice == 'Y')
        {

            //Get initial number of discs from user
            printf("\n\nHow many discs to start Towers of Hanoi?\n");
            fprintf(f_output,"How many discs to start Towers of Hanoi?\n");
            check = scanf("%d", &num_discs);


            clearBuffer();

            //Check if input number of discs is valid
            if (check == 1 && num_discs > 0)
            {
                printf("You entered %d. Here are your moves: \n\n", num_discs);
                fprintf(f_output, "You entered %d. Here are your moves: \n\n", num_discs);

                printf("Source: pole A, Dest: pole C, Aux: Pole B\n\n");
                fprintf(f_output, "Source: pole A, Final Dest: pole C, Aux: Pole B\n\n");

                //Call function to move discs for the solution
                MoveTowerHanoi(num_discs, user_source, user_dest, user_aux, num_discs);
            }

            //Get a new input from user if input is not correct
            else
            {
                printf("The input is invalid.\n");
                fprintf(f_output, "The input is invalid.\n");
                continue;
            }

            //Ask user to continue playing or quit
            printf("All %d discs are now at destination %c\n\n", num_discs, 'C');
            fprintf(f_output, "All %d discs are now at destination %c\n\n", num_discs, 'C');

            printf("\nEnter y to continue playing tower of Hanoi, any key to exit\n");
            fprintf(f_output, "\nEnter y to continue playing tower of Hanoi, any key to exit\n");

            scanf("%c", &user_choice);
            fprintf(f_output, "You entered %c.\n\n\n", user_choice);

            clearBuffer();
        }

        printf("\n\nThank you for playing Towers of Hanoi!\n\n");
        fprintf(f_output, "\n\nThank you for playing Towers of Hanoi!\n\n");
    }

    //Close the file stream
    fclose(f_output);
    return 0;
}



/***********************************************************************************
* Function:     MoveTowerHanoi                                                     *
* Description:  Gets solution to move tower of Hanoi from source to destination    *
*               using recursion.                                                   *
*                                                                                  *
* Parameters:   int, char, char, char                                              *
* Returns:      void                                                               *
************************************************************************************/


void MoveTowerHanoi(int disc, char source, char dest, char aux, int nextFinalDisc)
{
    //Base solution--for only 1 disc, move it from source/aux to dest
    if (disc == 1)
    {

        //If final_move is equal to original number of discs when function was called, mark as final move
        printf("Moving disc 1 from %c to %c %s\n\n", source, dest, (disc == nextFinalDisc) ? "==> FINAL MOVE" : " ");
        fprintf(f_output, "Moving disc 1 from %c to %c %s\n\n", source, dest, (disc == nextFinalDisc) ? "==> FINAL MOVE" : " ");

        return;
    }

    //If not, move disc-1 discs from source to aux pole using dest as temporary aux
    MoveTowerHanoi(disc-1, source, aux, dest, nextFinalDisc);

    //nextFinalDisc keeps track of the next biggest disc to move into destination in order
    printf("Moving disk %d from %c to %c %s", disc, source, dest, (disc == nextFinalDisc ) ? "==> FINAL MOVE\n\n" : "\n\n");
    fprintf(f_output, "Moving disk %d from %c to %c %s", disc, source, dest, (disc == nextFinalDisc) ? "==> FINAL MOVE\n\n" : "\n\n");


    /*Now move disc-1 discs from aux to dest using source as temporary aux,
    nextFinalDisc is decremented as the biggest disc will now move into dest */

    nextFinalDisc--;
    MoveTowerHanoi(disc-1, aux, dest, source, nextFinalDisc);

}


/***********************************************************************************
* Function:     ClearBuffer                                                        *
* Description:  Flushes input buffer for any stray characters,                     *
*               called after using scanf                                           *
*                                                                                  *
* Parameters:   None                                                               *
* Returns:      void                                                               *
************************************************************************************/


void clearBuffer(void)
{
    //Keep reading and flushing characters from buffer till a newline is reached
    while (getchar() != '\n');
}
