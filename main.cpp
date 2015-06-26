#include "Stack.hpp"
#include <ncurses.h>

int printMenu();

int main(int argc, char** argv){
	initscr();
	noecho();
	curs_set(0);
	//COLORS Y SPECIAL KEYS
	start_color();
    use_default_colors();
    init_pair(1, -1, -1);
    init_pair(2, COLOR_BLACK, COLOR_CYAN);
    init_pair(3, COLOR_RED, -1);
    init_pair(4, COLOR_BLUE, -1);
    init_pair(5, COLOR_CYAN, -1);
    keypad(stdscr, TRUE);
    Stack stack= Stack();
    int i, j;
	getmaxyx(stdscr,i,j);

    int in=3;
    do{
    	in=printMenu();
    	if(in==1){
    		echo();
    		int num;
    		mvprintw(i/3-2,j/2-27/2, "Ingrese el numero push: ");
    		scanw("%i",&num);
    		stack.push(num);
    		noecho();

    	}else if(in==2){
    		try{
    			mvprintw(i/3-2,j/2-27/2, "El ultimo numero fue %i", stack.pop());
    			getch();
    		}catch(const char* str){
    			clear();
    			mvaddstr(i/3-2, j/2-27/2,str); 
    			getch();
    		}
    		
    	}else if(in==3){

    	}
    }while(in!=3);




	endwin();
	return 0;
}

int printMenu(){
	int i, j;
	getmaxyx(stdscr,i,j);
	clear();
	char menu[3][35] = {" Push "," Pop "," Salir "};
	int retVal=1;
	
	
	mvprintw(i/3-2,j/2-9/2, " MENU ");
	mvprintw(i/3-1,j/2-35/2, "Presione enter para continuar");
	int input;
	do{
		for(int ii = 0; ii < 3; ii++){
			if(retVal-1 == ii){
				attrset(A_BOLD | COLOR_PAIR(2));
			}
			mvprintw(i/3+ii,j/2-9/2,menu[ii]);
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