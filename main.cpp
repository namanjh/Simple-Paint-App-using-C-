#include <graphics.h>
#include<windows.h>
#include<stdio.h>
#include<conio.h>

int windowform();
int mouseclick();
int draw(int , int ,char , int);
int main()
{
	DWORD windowh = GetSystemMetrics(SM_CXSCREEN);
	DWORD windoww = GetSystemMetrics(SM_CYSCREEN);
	initwindow(windowh-600,windoww,"graphics editor by naren and sajan",-3,-3); //to display the window
	windowform(); //to display the form of the window
	mouseclick();
	getch();
	delay(5000);
}

int windowform()
{
	DWORD windoww = GetSystemMetrics(SM_CXSCREEN);
	DWORD windowh = GetSystemMetrics(SM_CYSCREEN);
	int i,j;
		//start building menu
	setbkcolor(10); //setting background color to light green
	setcolor(0); //setting the color of the text of the area of writting to balck
	settextstyle(10,HORIZ_DIR,2);
	outtextxy(1,1,"Open File");
	bar(80,50,80,50); // bar for the text to be displayed
	
	//setting the menu options
	outtextxy(130,1,"Save File");
	outtextxy(260,1,"Pencil");
	outtextxy(350,1,"Line");
	outtextxy(430,1,"Rectangle");
	outtextxy(560,1,"Circle");
	outtextxy(650,1,"Fill Color");
	outtextxy(785,1,"Eraser");
	outtextxy(890,1,"Exit");
	settextstyle(10,HORIZ_DIR,2);
	outtextxy(1,40,"Colors:");
	
	//start building colors
		//red color = 4
		setfillstyle(SOLID_FILL,4);
		bar(1,80,100,150);
		
		//blue color = 1
		setfillstyle(SOLID_FILL,1);
		bar(1,160,100,230);
		
		//Green color = 2
		setfillstyle(SOLID_FILL,2);
		bar(1,240,100,310);
		
		//yellow color = 14
		setfillstyle(SOLID_FILL,14);
		bar(1,320,100,390);
		
		//white color = 15
		setfillstyle(SOLID_FILL,15);
		bar(1,400,100,470);
		
		//magneta = 5
		setfillstyle(SOLID_FILL,5);
		bar(1,480,100,550);
		
		//cyan = 3
		setfillstyle(SOLID_FILL,3);
		bar(1,560,100,630);
		
		//light red = 12
		setfillstyle(SOLID_FILL,12);
		bar(1,640,100,710);
		
		//light blue = 9
		setfillstyle(SOLID_FILL,9);
		bar(1,720,100,790);
	
	setcolor(15);
	setfillstyle(SOLID_FILL,15);
	rectangle(120,50,windoww-100,windowh-100);
	floodfill(200,400,15);
}


int mouseclick()
{
	DWORD windoww = GetSystemMetrics(SM_CXSCREEN);
	DWORD windowh = GetSystemMetrics(SM_CYSCREEN);
	int xc, yc;
	char cmd;
	int clr;
	POINT mycursor;
	while(1)
	{
		clearmouseclick(WM_LBUTTONDOWN);
		if(ismouseclick(WM_LBUTTONDOWN))
		{
			xc= mousex();
		 	yc = mousey();
		 	clearmouseclick(WM_LBUTTONDOWN);
			if(yc>1 && yc <30)
			{
				if(xc>1 && xc<120)
				{
					cmd = 'o'; //open file
					outtextxy(200,300,"open file");
				}
				
				else if(xc>130 && xc<250)
				{
					cmd = 's'; //save file
				}
				
				else if(xc>260 && xc<340)
				{
					cmd = 'p'; //pencil
					printf("pencil");
				}
				
				else if(xc>350 && xc<420)
				{
					cmd = 'l';//line
					printf("line");
				}
				
				else if(xc>430 && xc<550)
				{
					cmd = 'r';//rectangle
					printf("rectangle");
				}
				
				else if(xc>560 && xc<640)
				{
					cmd = 'c'; //circle
				}
				
				else if(xc>650 && xc<775)
				{
					cmd = 'f'; //fill
					printf("flood fill");
				}
				
				else if(xc>785 && xc<880)
				{
					cmd = 'e'; //eraser
					printf("eraser");
				}
				
				else if(xc>890 && xc<950)
				{
					setcolor(9);
					setbkcolor(4);
					outtextxy(200,400,"exiting in 3 secs...");
					delay(3000);
					exit(1);
				}
			}
			if(xc>120 && xc<windoww && yc>50 && yc<windowh)
			{
				draw(xc,yc,cmd,clr);
			}
			
			if(xc>1 && xc<100)
			{
				if(yc>80 && yc<150)
				{
					clr =4; //red
				}
				
				else if(yc>160 && yc<230)
				{
					clr = 1; //blue
					printf("blue");
				}
				
				else if(yc>240 && yc<310)
				{
					clr = 2; //green
				}
				
				else if(yc>320 && yc<390)
				{
					printf("yellow");
					clr = 14; //yellow
				}
				
				else if(yc>400 && yc<470)
				{
					clr = 15; //white
				}
				
				else if(yc>480 && yc<550)
				{
					clr = 5;//magneta
				}
				
				else if(yc>560 && yc<630)
				{
					clr = 3; //cyan
				}
				
				else if(yc>640 && yc<710)
				{
					clr = 12; //light red
				}
				
				else if(yc>720 && yc<790)
				{
					clr= 9; //light blue
				}
			}
		}
	}
}


int draw(int xcl,int ycl, char cmd, int clr)
{
	if (cmd == 'p')   //pencil
	{
		printf("this is pencil");
		clearmouseclick(WM_LBUTTONUP);
		while(!ismouseclick(WM_LBUTTONUP))
		{
			setfillstyle(SOLID_FILL,clr);
			clearmouseclick(WM_LBUTTONUP);
			bar(xcl,ycl,xcl+10,ycl+6);
			clearmouseclick(WM_LBUTTONUP);
			xcl= mousex();
			ycl= mousey();
			delay(1);
		}
	}
	
	if(cmd == 'l') //line
	{
		setcolor(clr);
		int a,b;
		printf("\n we are drawing a line \n");
		printf("Give the co-ordinates as the end point of the line");
		scanf("%d%d",&a, &b);
		line(xcl,ycl,a,b);
		/*clearmouseclick(WM_LBUTTONDOWN);
		while(ismouseclick(WM_LBUTTONDOWN))
		{
			a = mousex();
			b= mousey();
			line(xcl,ycl,a,b);
			printf("while");
		}*/	
	}
	
	if(cmd == 'r') //rectangle
	{
		setcolor(0);
		int a,b;
		printf("\n Enter the co-ordinate of the Rectangle \n");
		scanf("%d%d",&a,&b);
		rectangle(xcl,ycl,a,b);
	}
	
	if(cmd =='c')
	{
		int r;
		setcolor(0);
		printf("\n we are drawing a circle");
		scanf("%d",&r);
		circle(xcl,ycl,r);
	}
	
	if(cmd == 'f')
	{
		printf("flood");
		setfillstyle(SOLID_FILL,clr);
		floodfill(xcl,ycl,14);
	}
	
	if(cmd == 'e')
	{
		setfillstyle(SOLID_FILL,15);
		printf("erase it macha");
			clearmouseclick(WM_LBUTTONUP);
		while(!ismouseclick(WM_LBUTTONUP))
		{
			setfillstyle(SOLID_FILL,15);
			clearmouseclick(WM_LBUTTONUP);
			bar(xcl,ycl,xcl+10,ycl+6);
			clearmouseclick(WM_LBUTTONUP);
			xcl= mousex();
			ycl= mousey();
			delay(1);
		}
	}
} 

