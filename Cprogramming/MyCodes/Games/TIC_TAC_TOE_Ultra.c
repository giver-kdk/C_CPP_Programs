/*This program is a TIC-TAC-TOE game application. It is multidimensional Tic-Tac-Toe game,
 
 *Features of Game:
    *The game has size options of 3 by 3, 4 by 4 and 5 by 5. 
    *Players can manually choose to be X or O.
    *Respective winner player is declared when wins.
    *If no one wins, then DRAW - DRAW.
    *If any of the player chooses wrong place on the box, then his/her turn is cancelled.

    -----------------------------Code by Giver Khadka---------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void game_logic(char player1A, char playground[100][100], int field_size);
void display_game(char game_field[100][100], int filed_size1A);
void display_updated_game(char update_field[100][100], int place, char player2A, int field_size2A);
char check_winner(char check_field[100][100], char player3A, int field_size3A);
char decide_winner(int ox_num, char player4A, int field_size4A);

int main()
{
    int game_size, size;
    char player;
    printf("\n\t\t******* T I C - T A C - T O E ******* MULTI-DIMENSIONAL *******\n");
    choose_player:
    printf("\n\t\t\t  Player 1 ==> X\tPlayer 2 ==> O\nWhich player are you?:\t");
    scanf(" %c", &player);
    
    if(player == 'x' || player == 'X' || player == '1' || player == 'o' || player == 'O' || player == '2')
    {
        if(player == 'x' || player == 'X' || player == '1')
        {
            player = 'X';
        }
        else if (player == 'o' || player == 'O' || player == '2')
        {
            player = 'O';
        }
        start: 
        printf("\nEnter the Size of GAME (3, 4, or 5?):\t");
        scanf("%d", &game_size);
        if(game_size == 3)
        {
            size = 11;
            char gameboard3[100][100] = 
            {
                
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '4', ' ', '|', ' ', '5', ' ', '|', ' ', '6', ' '},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '7', ' ', '|', ' ', '8', ' ', '|', ' ', '9', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
            };
            game_logic(player, gameboard3, size);
        }
        else if(game_size == 4)
        {
            size = 15;
            char gameboard4[100][100] = 
            {
                
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' ', '|', ' ', '4', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '5', ' ', '|', ' ', '6', ' ', '|', ' ', '7', ' ', '|', ' ', '8', ' '},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '9', ' ', '|', ' ', '1', '0', '|', ' ', '1', '1', '|', ' ', '1', '2'},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '1', '3', '|', ' ', '1', '4', '|', ' ', '1', '5', '|', ' ', '1', '6'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
            };
            game_logic(player, gameboard4, size);
        }
        else if(game_size == 5)
        {
            size = 19;
            char gameboard5[100][100] = 
            {
                
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', '1', ' ', '|', ' ', '2', ' ', '|', ' ', '3', ' ', '|', ' ', '4', ' ', '|', ' ', '5', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '6', ' ', '|', ' ', '7', ' ', '|', ' ', '8', ' ', '|', ' ', '9', ' ', '|', ' ', '1', '0'},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '1', '1', '|', ' ', '1', '2', '|', ' ', '1', '3', '|', ' ', '1', '4', '|', ' ', '1', '5'},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '1', '6', '|', ' ', '1', '7', '|', ' ', '1', '8', '|', ' ', '1', '9', '|', ' ', '2', '0'},
                {'_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_', '|', '_', '_', '_'},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
                {' ', '2', '1', '|', ' ', '2', '2', '|', ' ', '2', '3', '|', ' ', '2', '4', '|', ' ', '2', '5'},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
            };
            game_logic(player, gameboard5, size);
        }
        else
        {
            printf("\nEnter allowed size only!");
            goto start;
        }
    }
    else 
    {
       printf("\nEnter valid Player. X or O !"); 
       goto choose_player;
    }
    getch();
}
void game_logic(char player1A, char playground[100][100], int field_size)
{
    int i, j, input_choice;
    
    char resume_game = '0';
    display_game(playground, field_size);
    while(resume_game = '0')
    {
        printf("\nTurn for Player %c  ==>  Where do you want to place %c: ", player1A, player1A);
        scanf("%d", &input_choice);
        display_updated_game(playground, input_choice, player1A, field_size);
        
        check_winner(playground, player1A, field_size);
        if(player1A == 'X')
        {
            player1A = 'O';
        }
        else if(player1A == 'O')
        {
            player1A = 'X';
        }
        for(i = 0; i < field_size; i++)
        {
            for(j = 0; j < field_size; j++)
            {
                if(playground[i][j] > 48 && playground[i][j] < 57)
                {
                    resume_game = 'y';
                    i = i + field_size;
                    break;
                }
            }
        }
        if(resume_game == 'y')
        {
            resume_game = '0';
        }
        else
        {
            printf("This is a DRAW - DRAW!");
            return;
        }
    }

}
void display_game(char game_field[100][100], int field_size1A)
{
    int i, j;
    for(i = 0; i < field_size1A; i++)
        {
            for(j = 0; j < field_size1A; j++)
            {
                printf(" %c", game_field[i][j]);
            }
            printf("\n");
        }
}
void display_updated_game(char update_field[100][100], int place, char player2A, int field_size2A)
{
    int temp = 0, swaped = 0, i, j;
    for(i = 0; i < field_size2A; i++)
    {
        for(j = 0; j < field_size2A; j++)
        {
            if((place / 10) + 48 == update_field[i][j])
            {
                if((place % 10) + 48 == update_field[i][j + 1])
                {
                    temp = update_field[i][j + 1];
                    update_field[i][j] = player2A;
                    update_field[i][j + 1] = ' ';
                    swaped = 1;
                }
            }
            else if(place + 48 == update_field[i][j])
            {
                temp = update_field[i][j];
                update_field[i][j] = player2A;
                swaped = 1;  
                i = i + field_size2A;
                break;
            }
        }
    }
    display_game(update_field, field_size2A);
    if(swaped != 1)
    {
        printf("Please enter valid Place! Your Turn has been Cancelled!");
    }
}
char check_winner(char check_field[100][100], char player3A, int field_size3A)
{
    int i, j, ox_number;
    for(i = 0; i < field_size3A; i++)
    {
        ox_number = 0;
        for(j = 0; j < field_size3A; j++)
        {
            if(check_field[i][j] == player3A)
            {
                ox_number++;
            }
        }
        decide_winner(ox_number, player3A, field_size3A);
    }
    for(j = 0; j < field_size3A; j++)
    {
        ox_number = 0;
        for(i = 0; i < field_size3A; i++)
        {
            if(check_field[i][j] == player3A)
            {
                ox_number++;
            }
        }
        decide_winner(ox_number, player3A, field_size3A);
    }
    ox_number = 0;
    for(i = 0; i < field_size3A; i++)
    {
        for(j = 0; j < field_size3A; j++)
        {
            if(i == j)
            {
                if(check_field[i][j] == player3A)
                {
                    ox_number++;
                }
            }
        }
        decide_winner(ox_number, player3A, field_size3A);
    }
    ox_number = 0;
    for(i = 0; i < field_size3A; i++)
    {
        for(j = 0; j < field_size3A; j++)
        {
            if(i + j == field_size3A - 1)
            {
                if(check_field[i][j] == player3A)
                {
                    ox_number++;
                }
            }
        }
        decide_winner(ox_number, player3A, field_size3A);
    }
}
char decide_winner(int ox_num, char player4A, int field_size4A)
{
    if(ox_num == (field_size4A + 1) / 4)
    {
        printf("\n\t\t*******CONGRATULATIONS! Player %c won the GAME!*******\n", player4A);
        exit(0);
    }
}