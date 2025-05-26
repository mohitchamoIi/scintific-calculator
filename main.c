//header files
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// Functions
#include"func.h"

void showMainMenu() {
    printf("\n\n===========================================\n");
    printf("         SCIENTIFIC CALCULATOR\n");
    printf("===========================================\n");
    printf("    Developed by:  MOHIT CHAMOLI \n");
    printf("    Roll No:      [39]\n");
    printf("    Section:      [H2]\n");
    printf("===========================================\n");

    printf("\nMain Menu:\n");
    printf("-------------------------------------------\n");
    printf("1. Basic Calculator\n");
    printf("2. Scientific Calculator\n");
    printf("3. Show History\n");
    printf("4. Exit\n");
    printf("-------------------------------------------\n");
}



//main function
int main() {
    int choice;
    while (1) {
        showMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

       switch (choice) {
    case 1:
        basicCalculator();
        break;
    case 2:
        scientificCalculator();
        break;
    case 3:
        showHistory();
        break;
    case 4:
        printf("\nThank you for using the calculator!\n");
        exit(0);
    default:
        printf("Invalid choice! Please try again.\n");
}
    }

    return 0;
}







