//Program to add,search and find meaning of a word in a dictionary

/*
The menu contains option
- to add data
- to search data
- to read and display data
- to update existing record
*/

#include<stdio.h>
#include<string.h> //for string handeling functions
#include<stdlib.h> //for exit() function

void welcome_menu(); //welcome module
void main_menu(); //displays main manu
void add_record(); //function to add records
void search_record(); // function to search record
void search_menu(); //search module
void search_by_name(); //search by name module
void search_by_synonym(); //search by synonym module
void search_by_antonym(); //search by antonym module
void display_record(); //function to display records
void timesleep(); //time delay function
void update_record(); //function to update records

struct detail {
	//members
	char wname[100];
	char wmeaning[100];
	char wsynonym[100];
	char wantonym[100];
}var;

/*main function*/
void main() {
	system("cls");
	main_menu();
	getch();
}

/*main menu module*/
void main_menu() {
	int choice;
	welcome_menu();
	printf("\n------------------------------------------------\n");
	printf("Enter your choice........\n");
	printf("--------------------------------------------------\n");
	printf("|(1) to store data		|\n");
	printf("|(2) to search data		|\n");
	printf("|(3) to display records		|\n");
	printf("|(4) to update/modify the record|\n");
	printf("--------------------------------------------------\n");
	scanf("%d",&choice);

	switch(choice) {
		case 1:
			system("cls");
			printf("\nwe are going to add/store data\n");
			add_record(); //call function if the condition is true
			break;
		case 2:
			system("cls");
			printf("we are going to search data\n");
			search_menu(); //call of function if the condition is true
			break;
		case 3:
			system("cls");
			printf("we are going to display records\n");
			display_record(); //call of function to print the records
			break;
		case 4:
			system("cls");
			printf("we are going to modify records\n");
			update_record(); //call of function to print the records
			break;
		default:
			system("cls");
			printf("sorry, this choice is not available.\n");
			printf("so terminating the program...\n");
			printf("thank u for using this program...\n");
			sleep(2000); //sleeps the exit of execution for 2 secs.
			exit(0); //exits the process. It exits in stdlib.h
	}
}

/*self typing welcome message*/
void welcome_menu() {
	char welcome[100]="Dictionary Management program";
	int i;
	printf("welcome to");
	for(i=0;welcome[i]!='\0';i++) {
		printf("%c",welcome[i]); //printing character with 100/1000 second.
		sleep(100); //delay time
	}
}

/* add data/word module*/
void add_record() {
	system("cls");
	printf("------------------------------------------------------------\n");
	char ch='y';
	FILE *p;
	p=fopen("dict.txt","a"); //file opened in apend mode
	while(ch!='n') {
		printf("\n");
		fflush(stdin); //flushes the input buffer
		//data input
		printf("Enter word:\n");
		gets(var.wname);
		fflush(stdin);
		printf("Enter its meaning:\n");
		gets(var.wmeaning);
		fflush(stdin); //flushes the buffer
		printf("Now, enter its synonym:\n");
		gets(var.wsynonym);
		fflush(stdin);
		printf("Enter antonym:\n"); //gets the antonym
		gets(var.wantonym);
		fflush(stdin);
		fwrite(&var,sizeof(var),1,p); //writs data
		system("cls");
		printf("you want to continue?\n");
		system("cls");
		printf("press y/Y to continue and 'n' to discontinue...\n");
		ch=getch(); //gets a character to continue the process
		fflush(stdin); //flushes the buffer
		system("cls");
	}
	fclose(p);
	printf("press enter to goto main menu\n");
	getch();
	fflush(stdin);
	sleep(1000); //sleeps for 1 secs
	system("cls");
	main_menu(); //calling of main menu with some delay
}

/*data display module*/
void display_record() {
	system("cls");
	FILE *p;
	p=fopen("dict.txt","r"); //opening of file in read mode
	int i=0;
	while ((fread(&var,sizeof(var),1,p))==1) {
		i++;
		printf("word=%20s\n",var.wname);
		printf("meaning=%20s\n",var.wmeaning);
		printf("synonmy=%20s\n",var.wsynonym);
		printf("antonym=%20s\n",var.wantonym);
		printf("------------------------------------------------------------\n");
		if(i==3) {
			i=0;
			printf("hit enter to continue\n"); //for three records display at a time
			getch();
			system("cls");
		}
	}
	fclose(p); //closes the file
	printf("press enter to goto main menu\n");
	getch();
	fflush(stdin);
	sleep(1000); //sleeps for 1 secs
	system("cls");
	main_menu(); //calls the main menu
}

/*search module starts here*/
void search_menu() {
	char choice; //prints the menu
	printf("we have following searching choice.................\n");
	printf("------------------------------------------------------------\n");
	printf("|----------------------------------------------------------|\n");
	printf("|'n' or 'N' to search by name;		|\n");
	printf("|'s' or 'S' to search by synonym	|\n");
	printf("|'a' or 'A' to search by antonym	|\n");
	printf("-----------------------------------------------------------|\n");
	choice=getch(); //gets a character
	fflush(stdin); //fflush the buffer
	switch(choice) {
		case 'n':
		case 'N':
			system("cls");
			printf("\nwe are going to search by name\n");
			search_by_name(); //call of function if the condition is true
			break;
		case 's':
		case 'S':
			system("cls");
			printf("\we are going to search by synonyms\n");
			search_by_synonym(); //call of function if the condition is true
			break;
		case 'a':
		case 'A':
			printf("we are going to search by antonyms\n");
			search_by_antonym(); //call of function to print the records
			break;
		default:
			system("cls");
			printf("sorry,this choice is not available.\n");
			printf("so terminating the searching.......\n");
	}
	printf("press enter to return to main menu\n");
	getch();
	timesleep(); //sleeps the exit of execution for 3 secs
	system();
	main_menu();

}

/*search by name module*/
// data search function
void search_by_name() {
	char word_search[100],ch //variable for name
	system("cls");
	FILE *p;
	int flag=0;
	system("cls");
	p=fopen("dict.txt","r"); //opening of file in read mode
	printf("we can search record here only using word\n"");
	printf("enter word to be searched\n");
	fflush(stdin); //flushes the input buffer
	gets(word_search); //input of data to be searched
	fflush(stdin);
	system("cls");
	printf("data are\n");
	printf("--------------------------------------------------------\n");
	while((fread(&var,sizeof(var),1,p))==1 {
		if((strcmp(word_search,var.wname)==0)) {
		//reading till the last record
			flag=1; //data testing
			break; //breaks the searching process
		}
	}
	if(flag==1) {
		printf("word=%s,meaning=%s\n",var.wname,var.wmeaning); //printing of data
		printf("-----------------------------------------------\n");
	}
	else { //if(flag==0)
		system("cls");
		printf("sorry,no data found!"); //printing no data found
	}
	fclose(p);
	printf("press any key to load main menu\n");
	getch();
	fflush(stdin);
	sleep(1000); //sleep for 1 secs before search menu
	search_menu();
}

/*search by synonym module*/
// data search function
void search_by_synonym() {
	char word_search[100],ch //variable for name
	system("cls");
	FILE *p;
	int flag=0;
	system("cls");
	p=fopen("dict.txt","r"); //opening of file in read mode
	printf("we can search record here only using synonyms\n"");
	printf("enter synonym to be searched\n");
	fflush(stdin); //flushes the input buffer
	gets(word_syno); //input of data to be searched
	fflush(stdin);
	system("cls");
	printf("data are\n");
	printf("--------------------------------------------------------\n");
	while((fread(&var,sizeof(var),1,p))==1 {
		if((strcmp(word_syno,var.wsynonym)==0)) {
		//reading till the last record
			flag=1; //data testing
			break; //breaks the searching process
		}
	}
	if(flag==1) {
		printf("word=%s,synonyms=%s\n",var.wname,var.wsynonym); //printing of data
		printf("-----------------------------------------------\n");
	}
	else { //if(flag==0)
		system("cls");
		printf("sorry,no data found!"); //printing no data found
	}
	fclose(p);
	printf("press any key to load main menu\n");
	getch();
	fflush(stdin);
	sleep(1000); //sleep for 1 secs before search menu
	search_menu();
}

/*search by name module*/
// data search function
void search_by_antonym() {
	char word_anto[100],ch //variable for name
	system("cls");
	FILE *p;
	int flag=0;
	system("cls");
	p=fopen("dict.txt","r"); //opening of file in read mode
	printf("we can search record here only using antonyms\n"");
	printf("enter antonym to be searched\n");
	fflush(stdin); //flushes the input buffer
	gets(word_anto); //input of data to be searched
	fflush(stdin);
	system("cls");
	printf("data are\n");
	printf("--------------------------------------------------------\n");
	while((fread(&var,sizeof(var),1,p))==1 {
		if((strcmp(word_anto,var.wantonym)==0)) {
		//reading till the last record
			flag=1; //data testing
			break; //breaks the searching process
		}
	}
	if(flag==1) {
		printf("word=%s,antonym=%s\n",var.wname,var.wantonym); //printing of data
		printf("-----------------------------------------------\n");
	}
	else { //if(flag==0)
		system("cls");
		printf("sorry,no data found!"); //printing no data found
	}
	fclose(p);
	printf("press any key to load main menu\n");
	getch();
	fflush(stdin); //flushes the input buffer
	sleep(1000); //sleep for 1 secs before search menu
	search_menu();
}

/*update data module starts here*/
void update_record() {
	system("cls");
	FILE *p,*pl;
	char word_update[100];
	p=fopen("dict.txt","r");
	pl=fopen("updatedata.txt","a");
	printf("enter word to update\n");
	fflush(stdin);
	gets(word_update);
	while ((fread(&var,sizeof(var),1,p))==0) {
		if((strcmp(var.wname,word_update))==0) {
			printf("word=%20s\n",var,wname);
			printf("meaning=%20s\n",var,wmeaning);
			printf("synonym=%20s\n",var,wsynonym);
			printf("antonym=%20s\n",var,wantonym);
			printf("-----------------------------------------------------------\n");
			printf("Enter new informations about %s word\n",word_update);
			printf("enter word\n");
			gets(var.wname);
			printf("enter its meaning\n");
			gets(var.wmeaning);
			printf("enter its synonym\n");
			gets(var.wsynonym);
			printf("enter its antonym\n");
			gets(var.wantonym);
			fwrite(&var,sizeof(var),p,1); //writes datd
		}
		else {
			fwrite(&var,sizeof(var),1,p1); //writes data
		}
	}
	fclose(p);
	fclose(p1);
	remove("dict.txt");
	rename("updatedata.txt","dict,txt");
	printf("data updated successfully\n");
	printf("press enter to goto main menu");
	getch();
	fflush(stdin);
	sleep(1000); //sleeps for 1 sec
	system("cls");
	main_menu();
}

/*-------------------------------*/
/*time delay module starts here*/
void timesleep() {
	system("cls");
	printf("loading main menu.....\n");
	sleep(1000)
	system("cls");
	fflush(stdin); //flushes input buffer(if any)
	main_menu(); //loads main menu
}
