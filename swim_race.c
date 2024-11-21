#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

// Function to simulate a dice roll
int dice() {
    int roll = rand() % 6 + 1; // A dice roll
    return roll;
}

// Function to simulate the race
void race(int distance, char player1[11], char player2[11]) {
    int position_lane1 = 0;
    int position_lane2 = 0;
    int winner1 = 0;
    int winner2 = 0;
    int roll1;
    int roll2;
    char lane1[distance];
    char lane2[distance];

    for (int i = 0; i < distance; i++) {
        lane1[i] = '~'; // Initialize the playing field
        lane2[i] = '~';
    }
    lane1[distance - 1] = '\0';
    lane2[distance - 1] = '\0';
    system("cls");
    printf("LANE 1");
    printf("\n\n%s", lane1);
    printf("\n\nLANE 2");
    printf("\n\n%s\n\n", lane2);

    do {
        printf("%s! It's your turn! (enter)", player1);
        getchar();
        roll1 = dice();
        printf("Roll: %d\n", roll1);
        lane1[position_lane1] = '~';
        position_lane1 = position_lane1 + roll1;
        if (position_lane1 >= distance - 2) {
            position_lane1 = distance - 2;
            winner1 = 1;
        }
        lane1[position_lane1] = 'o';
        sleep(1);
        system("cls");
        printf("LANE 1");
        printf("\n\n%s", lane1);
        printf("\n\nLANE 2");
        printf("\n\n%s\n\n", lane2);

        printf("%s! It's your turn! (enter)", player2);
        getchar();
        roll2 = dice();
        printf("Roll: %d\n", roll2);
        lane2[position_lane2] = '~';
        position_lane2 = position_lane2 + roll2;
        if (position_lane2 >= distance - 2) {
            position_lane2 = distance - 2;
            winner2 = 1;
        }
        lane2[position_lane2] = 'o';
        sleep(1);
        system("cls");
        printf("LANE 1");
        printf("\n\n%s", lane1);
        printf("\n\nLANE 2");
        printf("\n\n%s\n\n", lane2);

    } while (winner1 == 0 && winner2 == 0);

    if (winner1 == 1 && winner2 == 1) {
        printf("\n\nDRAW!\n\n");
    } else {
        if (winner1 == 1) {
            printf("\n\nCONGRATULATIONS %s!!!\n\n", player1);
        } else {
            printf("\n\nCONGRATULATIONS %s!!!\n\n", player2);
        }
    }
}

// Main program
int main() {
    srand(time(0));
    char name1[11];
    char name2[11];
    int distance;
    char choice = 'y';
    int input_ok = 0;

    while (choice == 'y') {
        system("cls");
        printf("What is the name of the swimmer in lane one? ");
        scanf("%10s", name1);
        getchar();
        printf("What is the name of the swimmer in lane two? ");
        scanf("%10s", name2);
        getchar();
        do {
            system("cls");
            printf("How long should the lane be? (20m-100m)? ");
            scanf("%d", &distance);
            getchar();
            if (distance >= 20 && distance <= 100) {
                input_ok = 1;
            } else {
                printf("Invalid input! The lane should be 20-100m long!\n\n");
                sleep(2);
            }
        } while (input_ok == 0);

        race(distance, name1, name2);

        printf("Another race? (y/n)");
        scanf("%c", &choice);
        getchar();
    }
    system("cls");
    printf("\nBye Bye!\n\n");
    sleep(3);
    return 0;
}
