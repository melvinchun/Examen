#include "Stack.h"
#include <ncurses.h>

int main(int argc, char** argv){
	initscr();

	//COLORS Y SPECIAL KEYS
	start_color();
    use_default_colors();
    init_pair(1, -1, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_RED, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_CYAN, -1);
    keypad(stdscr, TRUE);

    int userInput=printMenu();




	endwin();
	return 0;
}

int printMenu(){
	int i, j;
	getmaxyx(stdscr,i,j);
	clear();
	char menu[3][35] = {"Push","Pop","Salir"};
	int retVal=3;
	
	
	mvprintw(0,0, "-------MENU-------\n");
	mvprintw(8,0, "Presione enter para continuar");
	int input;
	do{
		for(int ii = 0; ii < 3; ii++){
			if(retVal-1 == ii){
				attrset(A_BOLD | COLOR_PAIR(2));
			}
			mvprintw(i/3+ii,j/2,menu[ii]);
			attroff(A_BOLD | COLOR_PAIR(2));
		}
		mvprintw(0,0,"Su opcion con las flechas");
		input = getch();
		if(input == KEY_DOWN || input == KEY_RIGHT){
			if(retVal<3)
				retVal++;
		}else if(input == KEY_UP || input == KEY_LEFT){
			if(retVal>1)
				retVal--;
		}
		refresh();
	}while(input!='\n');
	clear();
	return retVal;
}