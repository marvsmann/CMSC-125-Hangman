/*
 Marvin Jerald Villador 2014-75249
 Yves Sta. Ana
*/
// HANG MAN!


#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"


void print_display();
void display_game();
void arrow(int x, int y); //selector
void head(int x, int y);
void hand(int x, int y);
void erase();

#define max_puzzle 6

#define enter_key '\n'
#define up_key 'w'
#define down_key 's'
#define right_key 'd'
#define left_key 'a'

#define reset 'r'
#define exit 'x'
#define yes 'y'
#define no 'n'

#define start_game 1
#define quit_game 2
#define available 3
#define not_available 4

#define YELLOW 54
#define WHITE 63
#define BLACK 100
#define RED 36
#define CYAN 27

#define intMask 67108864


int puzzle = 1, count;

int createWord(char * word){
	unsigned long long newWord = 0;
	int i;
	int length = strlen(word);
	for(i = 0; i < length;i++){
		newWord ^= intMask >> (word[i]-64);
	}

	return newWord;
}

bool checkLetter(char * sourceWord,char * input){
	int sourceValue = createWord(sourceWord);
	int wordValue = createWord(input);

	if(sourceValue - (sourceValue ^ wordValue) == wordValue){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	int status = start_game;
	char keypress;
	int error = 0;
	int winner, puzzle, select, game_status;
	int x, y;

	set_graphics(VGA_320X200X256);

	do{
		erase(1,1,400,220);

		header(8, 5); // print menu
		
		select = start_game;

		//Main Menu
		do{
			if(keypress = (char)getch()){
				
				if(keypress == up_key && select == start_game){
					erase(115, 117, 13, 13);
					head(115, 157);
					select = quit_game;
				}
				else if(keypress == up_key && select == quit_game){
					erase(115, 157, 13, 13);
					head(115, 117);
					select = start_game;
				}
				else if(keypress == down_key && select == start_game){
					erase(115, 117, 13, 13);
					head(115, 157);
					select = quit_game;
				}
				else if(keypress == down_key && select == quit_game){
					erase(115, 157, 13, 13);
					head(115, 117);
					select = start_game;
				}
			
			}
		}while(keypress != enter_key);

		//Main Game
		if(select == start_game){
			erase(1,1,400,220);

			status = start_game;
			puzzle =  1;
			winner = 0;
			game_status = 1; //new puzzle

			//start
			keypress = yes;
			x = 10;
			y = 22;
			arrow(10, 22);

			do{
				if(game_status == 1){
						
					display_game();

					game_status = 0; //same puzzle
				}				

				do{
					if(keypress=(char)getch()){
					// EPIC CODE
						if(keypress == up_key){
							//top
							if(y == 22){
								erase(x, y, 7, 12);
								y = 142;
								arrow(x, y);
							}
							else{
								erase(x, y, 7, 12);
								y = y-10;
								arrow(x, y);
							}
						}
						else if(keypress == down_key){
							if(y == 142){
								erase(x, y, 7, 12);
								y = 22;
								arrow(x, y);
							}
							else{
								erase(x, y, 7, 12);
								y = y+10;
								arrow(x, y);
							}
						}
						else if(keypress == right_key){
							if(x == 35){
								erase(x, y, 7, 12);
								x = 10; 
								arrow(x, y);
							}
							else{
								erase(x, y, 7, 12);
								x = 35;
								arrow(x, y);
							}
						}
						else if(keypress == left_key){
							if(x == 10){
								erase(x, y, 7, 12);
								x = 35;
								arrow(x, y);
							}
							else{
								erase(x, y, 7, 12);
								x = 10;
								arrow(x, y);
							}	
						}
						else if(keypress == enter_key){
							erase(x+10, y+3, 10, 7);
							
						}
					}
				}while(keypress != exit && keypress != reset && error != 5 && winner != 1);
				
				if(winner == 1){

				}
				else if(keypress == exit){
					write_text("Do you want to exit? y/n",85,160,WHITE,0);
					keypress = (char)getch();
					erase(85,160,215,10);
				}
				else if(keypress == reset){
					write_text("Do you want to reset? y/n",80,160,WHITE,0);
					keypress = (char)getch();
					if(keypress == yes) {
						game_status = 1;
						keypress = no;
						
						erase(x, y, 7, 12);
						x = 10;
						y = 22;
						arrow(x, y);

					}
					erase(80,160,221,10);
				}
			}while(keypress != yes);

		}
		else{
			status = quit_game;
		}

	}while(status != quit_game);

	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}

void display_game(){
	int i, j, x, y;
	char str[15];

	write_text("Puzzle",115,5,WHITE,0);
	sprintf(str,"%d",puzzle); // to string
	write_text(str,190,5,WHITE,0);
	
	(20,25) = 'A'
	//display letters
	write_text("A",20,25,WHITE,0);
	write_text("B",20,35,WHITE,0);
	write_text("C",20,45,WHITE,0);
	write_text("D",20,55,WHITE,0);
	write_text("E",20,65,WHITE,0);
	write_text("F",20,75,WHITE,0);
	write_text("G",20,85,WHITE,0);
	write_text("H",20,95,WHITE,0);
	write_text("I",20,105,WHITE,0);
	write_text("J",20,115,WHITE,0);
	write_text("K",20,125,WHITE,0);
	write_text("L",20,135,WHITE,0);
	write_text("M",20,145,WHITE,0);

	write_text("N",45,25,WHITE,0);
	write_text("O",45,35,WHITE,0);
	write_text("P",45,45,WHITE,0);
	write_text("Q",45,55,WHITE,0);
	write_text("R",45,65,WHITE,0);
	write_text("S",45,75,WHITE,0);
	write_text("T",45,85,WHITE,0);
	write_text("U",45,95,WHITE,0);
	write_text("V",45,105,WHITE,0);
	write_text("W",45,115,WHITE,0);
	write_text("X",45,125,WHITE,0);
	write_text("Y",45,135,WHITE,0);
	write_text("Z",45,145,WHITE,0);

	write_text("Errors:",5,160,WHITE,10);

	//LEGENDS
	write_text("X-Exit",115,180,WHITE,0);
	write_text("R-Reset",195,180,WHITE,0);

	/*y = 25;
	for(i=0;i<65;i++){
		x = 115;
		for(j=0;j<100;j++){
			write_pixel(j+x,i+y,i);
		}
	}*/
}

void arrow(int x, int y){
	int i;
	for (i=1;i<2;i++)write_pixel(i+x,0+y,YELLOW);
	for (i=1;i<3;i++)write_pixel(i+x,1+y,YELLOW);
	for (i=1;i<4;i++)write_pixel(i+x,2+y,YELLOW);
	for (i=1;i<5;i++)write_pixel(i+x,3+y,YELLOW);
	for (i=1;i<6;i++)write_pixel(i+x,4+y,YELLOW);
	for (i=1;i<7;i++)write_pixel(i+x,5+y,YELLOW);
	for (i=1;i<7;i++)write_pixel(i+x,7+y,YELLOW);
	for (i=1;i<6;i++)write_pixel(i+x,8+y,YELLOW);	
	for (i=1;i<5;i++)write_pixel(i+x,9+y,YELLOW);
	for (i=1;i<4;i++)write_pixel(i+x,10+y,YELLOW);
	for (i=1;i<3;i++)write_pixel(i+x,11+y,YELLOW);
	for (i=1;i<2;i++)write_pixel(i+x,12+y,YELLOW);

	for (i=0;i<13;i++)write_pixel(x,i+y,RED);	
}

void head(int x, int y){
	int i;
	for (i=4;i<10;i++)write_pixel(i+x,0+y,YELLOW);
	for (i=2;i<12;i++)write_pixel(i+x,1+y,YELLOW);
	for (i=1;i<13;i++)write_pixel(i+x,2+y,YELLOW);
	for (i=1;i<13;i++)write_pixel(i+x,3+y,YELLOW);
	for (i=0;i<14;i++)write_pixel(i+x,4+y,YELLOW);
	for (i=0;i<14;i++)write_pixel(i+x,5+y,YELLOW);
	for (i=0;i<14;i++)write_pixel(i+x,6+y,YELLOW);
	for (i=0;i<14;i++)write_pixel(i+x,7+y,YELLOW);
	for (i=0;i<14;i++)write_pixel(i+x,8+y,YELLOW);	
	for (i=1;i<13;i++)write_pixel(i+x,9+y,YELLOW);
	for (i=1;i<13;i++)write_pixel(i+x,10+y,YELLOW);
	for (i=2;i<12;i++)write_pixel(i+x,11+y,YELLOW);
	for (i=4;i<10;i++)write_pixel(i+x,12+y,YELLOW);

	write_pixel(2+x,4+y,BLACK);
	write_pixel(4+x,4+y,BLACK);
	write_pixel(9+x,4+y,BLACK);
	write_pixel(11+x,4+y,BLACK);

	write_pixel(2+x,6+y,BLACK);
	write_pixel(4+x,6+y,BLACK);
	write_pixel(9+x,6+y,BLACK);
	write_pixel(11+x,6+y,BLACK);

	write_pixel(3+x,5+y,BLACK);
	write_pixel(10+x,5+y,BLACK);

	for (i=3;i<11;i++)write_pixel(i+x,8+y,BLACK);
	for (i=5;i<9;i++)write_pixel(i+x,9+y,RED);
	for (i=5;i<9;i++)write_pixel(i+x,10+y,RED);
	for (i=6;i<8;i++)write_pixel(i+x,11+y,RED);	
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

//displays MENU
header(int x, int y){
		
	write_text("HANG MAN!",120,40,WHITE,1); //title

	//menu options
	head(115, 117);
	write_text("Start",140,120,WHITE,0); 
	write_text("Quit",140,160,WHITE,0);
}