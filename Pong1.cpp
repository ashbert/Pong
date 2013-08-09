#include <c:\tc\include\graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>

union REGS i, o, ii;
char a = '/';
char b = 196;
char c = 92;
void *paddle1, *paddle2, *ball;
unsigned int size1, size2, size3, size4;
int x, y, x1, y1, x2, y2, button, flag, score1, score2, oo, flag1, flg, xx,
    yyy;
float yy, accuracy;
char n[2], n1[2];

void readme() 
{
	cleardevice();
	flushall();
	outtextxy(180, 200,
		   "This is a single player game. Player 1 on the mouse");
	outtextxy(180, 220,
		   "is YOU.Player 2 on the left side is the computer");
	getch();
	cleardevice();
} 

void comments() 
{
	cleardevice();
	flushall();
	setbkcolor(44);
	outtextxy(200, 200, "Email me at :-  ashwin_c99@hotmail.com");
	getch();
	cleardevice();
}

 void tricks() 
{
	cleardevice();
	setbkcolor(41);
	flushall();
	outtextxy(140, 200,
		   "Well... basically start off by entering a lower accuracy");
	outtextxy(140, 211, "value for the computer.");
	outtextxy(140, 223,
		   "Secondly when its your turn and the ball isnt already");
	outtextxy(140, 234,
		   "acclerated then you can do so by hitting the ball with the");
	outtextxy(140, 245,
		   "paddle at the top or bottom edge (somewhere 10 pixels +/-)");
	outtextxy(140, 256,
		   "To avoid flickering as far as possible try keeping your");
	outtextxy(140, 267, "paddle off the screen  (sorry about that)");
	outtextxy(140, 278, "ENJOY! ");
	getch();
	cleardevice();
}

 void mainmenu() 
{
	cleardevice();
	i.x.ax = 0;
	int86(0x33, &i, &o);
	flushall();
	i.x.ax = 1;
	int86(0x33, &i, &o);
	setcolor(41);
	
	do {
		line(0, 470, 640, 470);
		ellipse(290, 290, 0, 360, 170, 110);
		ii.x.ax = 3;
		int86(0x33, &ii, &o);
		xx = o.x.cx;
		yyy = o.x.dx;
		button = o.x.bx;
		outtextxy(200, 240, "PLAY some PONG!");
		outtextxy(200, 260, "TIPS AND TRICKS! ;) ");
		outtextxy(200, 280, "COMMENTS");
		outtextxy(200, 300, "Read Me First!!!!");
		outtextxy(200, 320, "EXIT");
		
		if (xx >= 200 && xx <= 300 && yyy >= 230 && yyy <= 250) {
			setcolor(GREEN);
			if (button == 1)
				return;
		}
		 
		else if (xx >= 200 && xx <= 300 && yyy >= 250 && yyy <= 270)
			 {
			setcolor(RED);
			if (button == 1)
				tricks();
			button = 0;
			}
		 
		else if (xx >= 200 && xx <= 300 && yyy >= 270 && yyy <= 290)
			 {
			setcolor(YELLOW);
			if (button == 1)
				comments();
			button = 0;
			}
		 
		else if (xx >= 200 && xx <= 300 && yyy >= 290 && yyy <= 310)
			 {
			setcolor(MAGENTA);
			if (button == 1)
				readme();
			button = 0;
			}
		 
		else if (xx >= 200 && xx <= 300 && yyy >= 310 && yyy <= 330)
			 {
			setcolor(CYAN);
			if (button == 1) {
				free(paddle1);
				free(paddle2);
				free(ball);
				closegraph();
				exit(0);
			}
			}
		
		else
			setcolor(WHITE);
	} while (button != 1);
}

void introscreen() 
{
	cleardevice();
	setcolor(2);
	rectangle(80, 40, 560, 450);
	rectangle(100, 410, 540, 430);
	setlinestyle(DOTTED_LINE, 0, 3);
	settextstyle(SANS_SERIF_FONT, 0, 7);
	setcolor(4);
	outtextxy(166, 70, "/=PONG=\\");
	settextstyle(SMALL_FONT, 0, 5);
	setcolor(41);
	outtextxy(310, 320, "Developed by:- Ashwin Chaugule");
	outtextxy(430, 333, "TE COMP 1");
	for (int i = 100; i <= 540; i += 3) {
		delay(30);
		line(100, 420, i, 420);
	} setlinestyle(SOLID_LINE, 0, 1);
	settextstyle(DEFAULT_FONT, 0, 1);
	setcolor(WHITE);
} void initgame() 
{
	x1 = 340;
	y1 = 240;
	yy = 220;
	flg = 0;
	x2 = x1 - 1;
	y2 = y1 - 1;
} void endgame() 
{
	cleardevice();
	gotoxy(15, 15);
	printf("Play another game?(y/n)");
	if (getch() == 'y')
		initgame();
	
	else
		 {
		mainmenu();
		}
}

void starting() 
{
	cleardevice();
	setcolor(2);
	rectangle(190, 230, 430, 350);
	outtextxy(200, 240, "RESTARTING GAME ENGINE....");
	sprintf(n, "PLAYER1:: %d", score1);
	outtextxy(200, 260, n);
	sprintf(n1, "PLAYER2:: %d", score2);
	outtextxy(200, 280, n1);
	outtextxy(200, 310, "Press any key to begin..");
	while (!kbhit()) {
		gotoxy(52, 20);
		printf("\b%c", a);
		delay(100);
		printf("\b%c", b);
		delay(100);
		printf("\b%c", c);
		delay(100);
	}
	getch();
}

void ballloop() 
{
	x2 = x1;
	y2 = y1;
	switch (flag)
		 {
	case 0:
		x1++;
		y1--;
		break;
	case 1:
		x1 -= 1;
		y1 -= 1;
		break;
	case 2:
		x1--;
		y1++;
		break;
	case 3:
		x1 += 1;
		y1 += 1;
		break;
	case 4:{
			if (score1 <= score2)
				 {
				x1--;
				y1++;
				}
			
			else
				 {
				x1++;
				y1++;
				}
		}
		break;
	case 5:
		x1--;
		y1--;
		break;
	case 6:
		x1--;
		y1++;
		break;
	case 7:
		x1++;
		y1++;
		break;
	case 8:
		x1++;
		y1--;
		break;
	 case 9:
		x1 -= 2;
		y1 -= 2;
		break;
	case 10:
		x1 -= 2;
		y1 += 2;
		break;
		}
}

void fastballloop() 
{
	x2 = x1;
	y2 = y1;
	switch (flag1)
		 {
	case 0:
		x1 += 3;
		y1 -= 3;
		break;
	case 1:
		x1 -= 3;
		y1 -= 3;
		break;
	case 2:
		x1 -= 3;
		y1 += 3;
		break;
	case 3:
		x1 += 3;
		y1 += 3;
		break;
	case 4:{
			if (score1 <= score2)
				 {
				x1--;
				y1++;
				}
			
			else
				 {
				x1++;
				y1++;
				}
		}
		break;
	case 5:
		x1 -= 3;
		y1 -= 3;
		break;
	case 6:
		x1 -= 3;
		y1 += 3;
		break;
	case 7:
		x1 += 3;
		y1 += 3;
		break;
	case 8:
		x1 += 3;
		y1 -= 3;
		break;
		}
}

 void accelerateball() 
{
	if (x1 == 340 && y1 == 240)
		 {
		flag1 = 4;
		}
	 if (y1 > 474 && x2 < x1)
		 {
		flag1 = 0;
		}
	
	else if (y1 > 474 && x2 > x1)
		 {
		flag1 = 5;
		}
	 if (x1 > 625 && y2 > y1)
		 {
		if (y1 > y && y1 < (y + 80))
			 {
			flag1 = 1;
			}
		
		else
			 {
			score2++;
			starting();
			initgame();
			}
		}
	 
	else if (x1 > 625 && y2 < y1)
		 {
		if (y1 > y && y1 < (y + 80))
			 {
			flag1 = 6;
			}
		
		else
			 {
			score2++;
			starting();
			initgame();
			}
		}
	 if (y1 <= 4 && x2 > x1)
		 {
		flag1 = 2;
		}
	
	else if (y1 <= 4 && x2 < x1)
		 {
		flag1 = 7;
		}
	 if (x1 < 4 && y2 < y1)
		 {
		if (y1 > yy && y1 < (yy + 80))
			 {
			flag1 = 3;
			}
		
		else
			 {
			score1++;
			starting();
			initgame();
			}
		}
	 
	else if (x1 < 4 && y2 > y1)
		 {
		if (y1 > yy && y1 < (yy + 80))
			 {
			flag1 = 8;
			}
		
		else
			 {
			score1++;
			starting();
			initgame();
			}
		}
	fastballloop();
}

void getupdates() 
{
	setcolor(41);
	line(0, 478, 640, 478);
	i.x.ax = 3;
	int86(0x33, &i, &o);
	x = o.x.cx;
	y = o.x.dx;
	button = o.x.bx;
	 putimage(631, y, paddle2, XOR_PUT);
	
	    if ((yy + 80) <= 470 || yy >= 4) {
		 if (y2 < y1)
			 {
			if (x1 == 4) {
				if (y1 <= (yy + 20) || y1 >= (yy + 70)) {
					flg = 1;
					accelerateball();
				}
			}
			
			else {
				if (flg == 1)
					putimage(2, yy +=
						  accuracy, paddle1, XOR_PUT);
				
				    else
					putimage(2, yy++, paddle1, XOR_PUT);
			}
			
			}
		
		else
			 {
			if (x1 == 4) {
				if (y1 <= (yy + 20) || y1 >= (yy + 70)) {
					flg = 1;
					accelerateball();
				}
			}
			
			else {
				if (flg == 1)
					
					    putimage(2, yy -=
						     accuracy, paddle1,
						     XOR_PUT);
				
				else
					
					    putimage(2, yy--, paddle1, XOR_PUT);
			}
			 }
	}
	
	else
		putimage(2, yy, paddle1, XOR_PUT);
	 putimage(x1, y1, ball, XOR_PUT);
 }

void checkballpos() 
{
	if (x1 == 340 && y1 == 240)
		 {
		flag = 4;
		}
	 if (y1 > 474 && x2 < x1)
		 {
		flag = 0;
		}
	
	else if (y1 > 474 && x2 > x1)
		 {
		flag = 5;
		}
	 if (x1 > 625 && y2 > y1)
		 {
		if (y1 > y && y1 < (y + 80))
			 {
			flag = 1;
			 if (y1 <= y + 20)
				 {
				flg = 1;
				accelerateball();
				}
			
			else if (y1 >= y + 60)
				 {
				flg = 1;
				accelerateball();
				}
			}
		
		else
			 {
			score2++;
			starting();
			initgame();
			}
		}
	 
	else if (x1 > 625 && y2 < y1)
		 {
		if (y1 > y && y1 < (y + 80))
			 {
			flag = 6;
			if (y1 <= y + 20) {
				flg = 1;
				accelerateball();
			}
			
			else if (y1 >= y + 60)
				 {
				flg = 1;
				accelerateball();
				}
			}
		
		else
			 {
			score2++;
			starting();
			initgame();
			}
		}
	 if (y1 <= 4 && x2 > x1)
		 {
		flag = 2;
		}
	
	else if (y1 <= 4 && x2 < x1)
		 {
		flag = 7;
		}
	 if (x1 < 4 && y2 < y1)
		 {
		if (y1 > yy && y1 < (yy + 80))
			 {
			flag = 3;
			}
		
		else
			 {
			score1++;
			starting();
			initgame();
			}
		}
	 
	else if (x1 < 4 && y2 > y1)
		 {
		if (y1 > yy && y1 < (yy + 80))
			 {
			flag = 8;
			}
		
		else
			 {
			score1++;
			starting();
			initgame();
			}
		}
	if (flg == 1)
		return;
	ballloop();
}

void drawpaddle(int left, int up, int right, int bottom) 
{
	rectangle(left, up, right, bottom);
} void getinfo() 
{
	drawpaddle(4, 200, 9, 280);
	size1 = imagesize(4, 200, 9, 280);
	paddle1 = malloc(size1);
	getimage(4, 200, 9, 280, paddle1);
	 drawpaddle(631, 200, 636, 280);
	size2 = imagesize(631, 200, 636, 280);
	paddle2 = malloc(size2);
	getimage(631, 200, 636, 280, paddle2);
	 circle(625, 200, 5);
	size3 = imagesize(620, 195, 630, 205);
	ball = malloc(size3);
	getimage(620, 195, 630, 205, ball);
	setcolor(BLACK);
 } void main(void) 
{
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:/tc/bgi/");
	errorcode = graphresult();
	if (errorcode != grOk)
		 {
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);
		}
	introscreen();
	mainmenu();
	i.x.ax = 2;
	int86(0x33, &i, &o);
	setcolor(WHITE);
	cleardevice();
	printf(".......during game right click to exit........");
	printf("\nEnter accuracy for computer (float value) 0-3 \n\
      (ideally 2.75 )..= ");
	scanf("%f", &accuracy);
	getinfo();
	starting();
	initgame();
	button = 1;
	
	do
		 {
		i.x.ax = 3;
		int86(0x33, &i, &o);
		button = o.x.bx;
		if (button == 2)
			mainmenu();
		 if (score1 == 5) {
			cleardevice();
			setcolor(3 + BLINK);
			outtextxy(200, 240, "Player 1 wins!!!!");
			score1 = score2 = 0;
			getch();
			endgame();
		}
		 
		else if (score2 == 5) {
			cleardevice();
			setcolor(4 + BLINK);
			outtextxy(200, 240, "Player 2 wins!!!!");
			score1 = score2 = 0;
			getch();
			endgame();
		}
		setcolor(RED);
		sprintf(n, "PLAYER(2):: %d", score2);
		outtextxy(50, 468, n);
		sprintf(n1, "PLAYER(1):: %d", score1);
		outtextxy(500, 468, n1);
		setcolor(2);
		cleardevice();	//this is the annoying cleardevice()
		getupdates();
		if (flg == 1)
			accelerateball();
		checkballpos();
		if (button == 2) {
			mainmenu();
			i.x.ax = 2;
			int86(0x33, &i, &o);
			setcolor(WHITE);
			cleardevice();
			flushall();
			gotoxy(1, 1);
			printf
			    (".......during game right click to exit........");
			printf
			    ("\nEnter accuracy for computer (float value) 0-3 \n\
      (ideally 2.75 )..= ");
			scanf("%f", &accuracy);
			score1 = score2 = 0;
			starting();
			initgame();
		}
	} while (button != 2);
}


