/*
 Marvin Jerald Villador 2014-75249
 Yves Sta. Ana
*/
// HANG MAN!


#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

void error_function(int x, int y);
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
#define BROWN 20
#define ORANGE 38
#define SKIN 46
#define GRAY 56
#define BLUE 25
#define DIRTY 48

int puzzle = 1, count;
int error = 0;

int main()
{
	int status = start_game;
	char keypress;
	int winner, puzzle, select, game_status;
	int x, y;

	set_graphics(VGA_320X200X256);

	do{
		erase(1,1,400,220);

		header(8, 5); // print menu
		
		select = start_game;

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

		if(select == start_game){
			erase(1,1,400,220);

			status = start_game;
			puzzle =  1;
			winner = 0;
			game_status = 1; //new puzzle

			//start
			keypress = yes;
			x = 6;
			y = 22;
			arrow(6, 22);

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
								erase(x, y, 10, 12);
								y = 142;
								arrow(x, y);
							}
							else{
								erase(x, y, 10, 12);
								y = y-10;
								arrow(x, y);
							}
						}
						else if(keypress == down_key){
							if(y == 142){
								erase(x, y, 10, 12);
								y = 22;
								arrow(x, y);
							}
							else{
								erase(x, y, 10, 12);
								y = y+10;
								arrow(x, y);
							}
						}
						else if(keypress == right_key){
							if(x == 31){
								erase(x, y, 10, 12);
								x = 6; 
								arrow(x, y);
							}
							else{
								erase(x, y, 10, 12);
								x = 31;
								arrow(x, y);
							}
						}
						else if(keypress == left_key){
							if(x == 6){
								erase(x, y, 10, 12);
								x = 31;
								arrow(x, y);
							}
							else{
								erase(x, y, 10, 12);
								x = 6;
								arrow(x, y);
							}	
						}
						else if(keypress == enter_key){
							erase(x+11, y+3, 10, 7);
						}
					}
				}while(keypress != exit && keypress != reset && error != 5 && winner != 1);
				
				if(winner == 1){

				}
				else if(keypress == exit){
					write_text("Do you want to exit? y/n",85,185,WHITE,0);
					keypress = (char)getch();
					erase(85,185,215,10);
				}
				else if(keypress == reset){
					write_text("Do you want to reset? y/n",80,185,WHITE,0);
					keypress = (char)getch();
					if(keypress == yes) {
						game_status = 1;
						keypress = no;
						
						erase(x, y, 10, 12);
						x = 6;
						y = 22;
						arrow(x, y);

					}
					erase(80,185,221,10);
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

void error_function(int x, int y){
	int i,j,k;

	//head
	for(i=0;i<9;i++){
		for(j=0;j<24;j++){
			write_pixel(j+x,i+y,BROWN);
		}
	}
	for(i=0;i<15;i++){
		for(j=0;j<24;j++){	
			write_pixel(j+x,i+9+y,SKIN);
		}
	}
	for(i=3;i<21;i++)write_pixel(i+x,6+y,SKIN);
	for(i=3;i<21;i++)write_pixel(i+x,7+y,SKIN);
	for(i=3;i<21;i++)write_pixel(i+x,8+y,SKIN);
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){	
			write_pixel(j+3+x,i+12+y,WHITE);
			write_pixel(j+18+x,i+12+y,WHITE);
			write_pixel(j+6+x,i+12+y,BLACK);
			write_pixel(j+15+x,i+12+y,BLACK);
		}
	}

	//body
	for(i=0;i<33;i++){
		for(j=0;j<24;j++){
			write_pixel(j+x,i+27+y,CYAN);
		}
	}
	for(i=0;i<3;i++){
		for(j=3;j<21;j++)write_pixel(j+x,i+27+y,BLUE);
		for(j=6;j<18;j++)write_pixel(j+x,i+30+y,BLUE);
		for(j=9;j<15;j++)write_pixel(j+x,i+33+y,BLUE);	
		for(j=6;j<18;j++)write_pixel(j+x,i+27+y,SKIN);
		for(j=9;j<15;j++)write_pixel(j+x,i+30+y,SKIN);
	}

	//right hand
	for(i=0;i<12;i++){
		for(j=0;j<6;j++){
			write_pixel(j+x-9,i+y+27,CYAN);
			write_pixel(j+x-9,i+12+y+27,SKIN);
		}
	}

	//left hand
	for(i=0;i<12;i++){
		for(j=0;j<6;j++){
			write_pixel(j+x+27,i+y+27,CYAN);
			write_pixel(j+x+27,i+12+y+27,SKIN);
		}
	}

	//right leg
	for(i=0;i<21;i++){
		for(j=0;j<9;j++){
			write_pixel(j+x,i+y+63,GRAY);
			
		}
	}
	for(i=0;i<6;i++){
		for(j=0;j<12;j++){
			write_pixel(j+x-3,i+y+84,DIRTY);
			
		}
	}

	//left leg
	for(i=0;i<21;i++){
		for(j=0;j<9;j++){
			write_pixel(j+x+15,i+y+63,GRAY);
			
		}
	}
	for(i=0;i<6;i++){
		for(j=0;j<12;j++){
			write_pixel(j+x+15,i+y+84,DIRTY);
			
		}
	}

	//slash with a smile
	k = 156;
	for(i=0;i<18;i++ ,k--){
		for(j=0;j<k;j++){
			write_pixel(j+x+45,i+y+39,GRAY);
		}
	}

	k = 150;
	for(i=0;i<6;i++ ,k--){
		for(j=0;j<k;j++){
			write_pixel(j+x+45,i+y+45,RED);
		}
	}
	for(i=0;i<6;i++){
		for(j=0;j<14;j++){
			write_pixel(j+x+36,i+y+45,GRAY);			
		}
	}	
	
	for(i=0;i<24;i++)write_pixel(x+45,i+y+36,RED);
	for(i=0;i<22;i++)write_pixel(x+46,i+y+37,RED);	
	for(i=0;i<20;i++)write_pixel(x+47,i+y+38,RED);	
	

}

void display_game(){
	int i, j, x, y;
	char str[15];

	write_text("Puzzle",115,5,WHITE,0);
	sprintf(str,"%d",puzzle); // to string
	write_text(str,190,5,WHITE,0);
	
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

	//LEGENDS
	write_text("X-Exit",10,170,WHITE,0);
	write_text("R-Reset",10,180,WHITE,0);

	/*y = 25;
	for(i=0;i<65;i++){
		x = 115;
		for(j=0;j<100;j++){
			write_pixel(j+x,i+y,i);
		}
	}*/

	error_function(115, 25);
}

void arrow(int x, int y){
	int i;
	
	for (i=4;i<11;i++)write_pixel(i+x,5+y,GRAY);
	for (i=4;i<10;i++)write_pixel(i+x,6+y,RED);
	for (i=4;i<9;i++)write_pixel(i+x,7+y,GRAY);
	
	for (i=0;i<9;i++)write_pixel(x+2,2+i+y,RED);
	for (i=0;i<9;i++)write_pixel(x+3,2+i+y,RED);	
	for (i=1;i<4;i++)write_pixel(x+1,4+i+y,GRAY);
	for (i=1;i<4;i++)write_pixel(x,4+i+y,GRAY);	

	write_pixel(x+4,y+6,GRAY);	
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