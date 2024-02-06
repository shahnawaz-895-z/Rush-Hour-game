//============================================================================
//muhammad shahnawaz i210895 section y project
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
int mytime=0;
int color;
int x2=0,y2=700;
bool lefta=false,righta=true;
bool upb=true,downb=true,leftb=true,rightb=true;
int xI = 40, yI = 120;
	int passenger[5]={40,200,320,520,840};
	int passengery[5]={120,80,280,440,600};
	int drop[2];
int picked=-1;
int score=0;
void drawCar() {
	DrawSquare(xI, yI, 20, colors[WHITE]);
	glutPostRedisplay();
}


bool flag = true;
void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}

/*
 * Main Canvas drawing function.
 * */
int menu=1;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square

	
	
if(menu==1)
	{
		DrawString( 300, 500, "Enter color(r for red, y for yellow)", colors[MISTY_ROSE]);
		glutSwapBuffers(); 
			
	}
	else if(menu==3){
		DrawString( 300, 500, "Enter color(r for red, y for yellow)", colors[MISTY_ROSE]);

	}
	else if (menu==2){
		DrawSquare(xI+5, yI, 30, colors[color]);
		DrawSquare(x2,y2,30,colors[GREEN]);
/*	
	//Green Square
	DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

	DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	
	drawCar();
	*/
	for(int x=0;x<1020;x+=40)
		DrawLine(x,0,x,900,2,colors[WHITE]);
		int hurdlesx[15]={80,160,240,120,280,320,400,720,520,200,720,800,600,240,440};
	int hurdlesy[15]={160,200,200,80,160,80,240,320,360,400,200,600,740,600,240};
	for(int i=0;i<15;i++)
	{		DrawSquare( hurdlesx[i] , hurdlesy[i] ,40,colors[WHITE]); 
	}
	int passenger[5]={40,200,320,520,840};
	int passengery[5]={120,80,280,440,600};
	for(int i=0;i<5;i++){
		if(picked!=i)
			DrawLine(passenger[i],passengery[i],passenger[i]+30,passengery[i]+20,20,colors[BLUE]);
		else
			DrawSquare(passenger[i],passenger[i],30,colors[GREEN]);
		
	}
	
	
	
	/////////////////passenger pickup here
	
	/////////////
	/////////////////collision with hurdle here
	for(int i=0;i<15;i++){
	/*	if((xI-hurdlesx[i])<10 )
		{
			if(xI-hurdlesx[i]<0){
				rightb=false;
			}
			if(xI-hurdlesy[i]>0){
				leftb=false;
			}
		}
		if((yI-hurdlesx[i]<50)){
			if(yI-hurdlesy[i]<0){
				upb=false;
			}
			if(yI-hurdlesy[i]>0){
				downb=false;
			}
			
			
			
		}
		
	*/
		DrawString(50,800,"Time Elapsed:"+Num2Str(mytime/10),colors[WHITE]);
		DrawString(850,800,"Score:"+Num2Str(score),colors[WHITE]);
		if(abs(xI-hurdlesx[i])<40 && abs(yI-hurdlesy[i])<40)
		{
		
			if(xI-hurdlesx[i]==0){
				
				if(leftb)
				{
					xI+=40;
					leftb=true;
					glutPostRedisplay();
				}
				if(rightb)
				{
					xI-=40;
					rightb=true;
					glutPostRedisplay();
				}
			}
			
			if(yI-hurdlesy[i]==0){
				
				if(upb)
				{
					yI-=40;
					upb=true;
					glutPostRedisplay();
				}
				if(downb)
				{
					yI+=40;
					rightb=true;
					glutPostRedisplay();
				}
			}
		
		}
		if(abs(xI-passenger[i])<40 && abs(yI-passengery[i])<40)
		{
		
			if(xI-passenger[i]==0){
				
				if(leftb)
				{
					xI+=40;
					leftb=true;
					glutPostRedisplay();
				}
				if(rightb)
				{
					xI-=40;
					rightb=true;
					glutPostRedisplay();
				}
			}
			
			if(yI-passengery[i]==0){
				
				if(upb)
				{
					yI-=40;
					upb=true;
					glutPostRedisplay();
				}
				if(downb)
				{
					yI+=40;
					rightb=true;
					glutPostRedisplay();
				}
			}
		
		}
		}
	glutSwapBuffers(); // do not modify this line..
	
		

	
}

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		
		if(xI>=40){
		rightb=false;
		leftb=true;
		upb=false;
		downb=false;
		xI -= 40;
		}
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
			if(xI<=940){
				rightb=true;
		leftb=false;
		upb=false;
		downb=false;
				xI += 40;
				}
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
			if(yI<=780){
					rightb=false;
		leftb=false;
		upb=true;
		downb=false;
				yI += 40;
				}
		
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
			if(yI>=40)
			{
					rightb=false;
		leftb=false;
		upb=false;
		downb=true;
				yI -= 40;
				
				}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	else if(key=='2'){
		menu=3;
	}
	else if (key == '1') //Key for placing the bomb
			{
		//do something if b is pressed
		menu=3;

	}
	else if(key =='r' || key=='R')
	{
		color=RED;
		menu=2;
	}
	else if(key =='y' || key=='Y')
	{
		color=YELLOW;
		menu=2;
	}
	else if(key==' ')
	{
		if(picked==-1)
		{
			for(int i=0;i<5;i++)
			{
			if(abs(xI-passenger[i])<=100 && abs(yI-passengery[i])<=100)
				{
				
					picked=i;
					
					int x=GetRandInRange(1,19);
					int y=GetRandInRange(1,19);
					cout<<x<<" and "<<y<<endl;
					int j=0;
					for(int k=0;k<1020;k+=40)
					{

						if(j==x)
						{
						   passenger[picked]=i;
						}
						if(j==y)
						{
						   passengery[picked]=k;
						   cout<<"assigning "<<k<<" to passengery["<<picked<<endl;
						}
					j++;
					}
				}
			}
			cout<<"executing"<<endl;
			score+=10;
		}
		else picked=-1;
		cout<<"picked is "<<picked<<endl;
	}
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	mytime+=1;
	if(x2<1000 && righta)
	{
		x2++;
	}
	else if(righta)
	{
		righta=false;
		lefta=true;
		x2-=3;
	}
	else if(x2>10 && lefta)
		x2--;
	else{
		lefta=false;
		righta=true;
		x2+=3;
	}
	
		
	// implement your functionality here
//	moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	srand(time(0));
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by muhammad shahnawaz"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
