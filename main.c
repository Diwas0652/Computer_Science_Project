#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void welcome_menu();
void main_menu();
void add_record();
void search_record();
void search_menu();
void search_by_name();
void search_by_synonym();
void search_by_antonym();
void display_record();
void timesleep();
void update_record();

struct detail {
    char wname[100];
    char wmeaning[100];
    char wsynonym[100];
}var;

/*main function*/
void main() {
    system("cls");
    main_menu();
    getch();
}

/*main menu module*/
void main_menu() {
    char choice;
    welcome_menu();
    printf("\n---------------------------------------------------------\n");
    printf("Enter your choice......\n");
    printf("-----------------------------------------------------------\n");
    printf
}
