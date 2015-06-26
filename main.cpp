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

    int userInput;



	endwin();
	return 0;
}

int printMenu(){
	clear();
	char menu[4][35] = {"Agregar Magia","Eliminar Magia","Imprimir todas las magias","Salir"};
	int retVal=4;
	int maxY, maxX;
	
	mvprintw(0,0, "-------MENU-------\n");
	mvprintw(8,0, "Presione enter para continuar");
	int input;
	do{
		for(int i = 0; i < 4; i++){
			if(retVal-1 == i){
				attrset(A_BOLD | COLOR_PAIR(2));
			}
			mvprintw(i+1,0,menu[i]);
			attroff(A_BOLD | COLOR_PAIR(2));
		}
		printw("\nSeleccione su opcion con las FLECHAS\n");
		input = getch();
		if(input == KEY_DOWN || input == KEY_RIGHT){
			if(retVal<4)
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