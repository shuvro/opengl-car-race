#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;


int lineStatus = 1;
float lineX = 0;
float lineY = 0;

int treeStatus = 1;
float treeX = 0;
float treeY = 0;

bool LeftKeyPressed = false,RightKeyPressed = false;
float posX=0,posY=0,posZ=0;


float oponentX=0,oponentY=1600,oponentZ=0;
bool oponentstat= true,dropped=false;



float oponentX1=0,oponentY1=1600,oponentZ1=0,OoponentX=0;
bool oponentstat1= true,dropped1=false;
int score =   0;
char buffer[10];
float xx;

int mainX=800,mainY=400 ;
int opOneX=600, opOneY=600;


bool gameFlag=false;
bool GOFlag=false;



void randomOponent(int max ,int min)
{
	static bool first = true;
	if (first)
	{
		srand (time(NULL));
		first=false;
	}

	oponentX= min+ rand()%(max-min);
}

void randomOponent1(int max ,int min)
{
	static bool first = true;
	if (first)
	{
		srand (time(NULL));
		first=false;
	}

	oponentX= min+ rand()%(max-min);
}

void drawString (void * font, char *s, float x, float y){ //scoreFunction
	glRasterPos2f(x, y);
	glColor3f(1, 1, 1);
	for (int i = 0; i < strlen (s); i++)
		glutBitmapCharacter (font, s[i]);
}
void drawString1 (void * font, char *s, float x, float y){ //scoreFunction
	glRasterPos2f(x, y);
	glColor3f(1, 1, 1);
	for (int i = 0; i < strlen (s); i++)
		glutBitmapCharacter (font, s[i]);
}

void backGround()
{

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(0,0);
	glVertex2i(2000, 0);
	glVertex2i(2000, 1500);
	glVertex2i(0,1500);
	glEnd();




}

void MainCar() //Main Car
{
	{	
		glPushMatrix();
		for(int i=0;i<10;i++)
		{
			glTranslatef(posX,posY,posZ);
		}

		glBegin(GL_POLYGON); //outer box
		glColor3f(0.0, 0.0, 0.10);
		glVertex2i(800,300);
		glVertex2i(900,300);
		glVertex2i(900, 400);
		glVertex2i(800,400);
		glEnd();


		glBegin(GL_POLYGON); //back part
		glColor3f(0.0, 0.0, 0.1);
		glVertex2i(810, 270);
		glVertex2i(890,270);
		glVertex2i(900, 300);
		glVertex2i(800,300);

		glEnd();



		glBegin(GL_POLYGON); 
		glColor3f(0.1, 0.3, 0.3);///middle box  back part
		glVertex2i(800,300);
		glVertex2i(900,300);
		glVertex2i(880, 330);
		glVertex2i(820,330);
		glEnd();


		glBegin(GL_POLYGON); //middle box
		glColor3f(0.3, 0.0, 0.4);

		glVertex2i(820, 330);
		glVertex2i(880,330);
		glVertex2i(880,370);
		glVertex2i(820,370);

		glEnd();

		glBegin(GL_POLYGON); 
		glColor3f(0.1, 0.3, 0.3);///middle box fornt part

		glVertex2i(820, 370);
		glVertex2i(880,370);
		glVertex2i(900,400);
		glVertex2i(800,400);

		glEnd();

		glBegin(GL_POLYGON); 
		glColor3f(0.0, 0.0, 0.1);//front part

		glVertex2i(mainX,mainY); //mainX=800 mainY=400 
		glVertex2i(mainX+100,mainY);
		glVertex2i(mainX+90,mainY+30);
		glVertex2i(mainX+10,mainY+30);
		glEnd();

		glPopMatrix();

	}

}

void oponent1()
{
	glBegin(GL_POLYGON); //outer box
	glColor3f(0.0, 0.0, 0.10);
	glVertex2i(600,500);
	glVertex2i(700,500);
	glVertex2i(700, 600);
	glVertex2i(600,600);
	glEnd();


	glBegin(GL_POLYGON); //back part
	glColor3f(0.0, 0.0, 0.1);
	glVertex2i(610, 470);
	glVertex2i(690,470);
	glVertex2i(700, 500);
	glVertex2i(600,500);

	glEnd();



	glBegin(GL_POLYGON); 
	glColor3f(0.1, 0.3, 0.3);///middle box  back part
	glVertex2i(600,500);
	glVertex2i(700,500);
	glVertex2i(680, 530);
	glVertex2i(620,530);
	glEnd();


	glBegin(GL_POLYGON); //middle box
	glColor3f(0.19, 0.32, 0.12);

	glVertex2i(620, 530);
	glVertex2i(680,530);
	glVertex2i(680,570);
	glVertex2i(620,570);

	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.1, 0.3, 0.3);///middle box fornt part

	glVertex2i(620, 570);
	glVertex2i(680,570);
	glVertex2i(700,600);
	glVertex2i(600,600);

	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.0, 0.1);//front part

	glVertex2i(opOneX,opOneY);  //opOneX=600, opOneY=600
	glVertex2i(opOneX+100,opOneY);
	glVertex2i(opOneX+90,opOneY+30);
	glVertex2i(opOneX+10,opOneY+30);
	glEnd();

	glPopMatrix();





}




void oponent2()
{
	glBegin(GL_POLYGON); //outer box
	glColor3f(0.0, 0.0, 0.10);
	glVertex2i(1000,500);
	glVertex2i(1100,500);
	glVertex2i(1100, 600);
	glVertex2i(1000,600);
	glEnd();


	glBegin(GL_POLYGON); //back part
	glColor3f(0.0, 0.0, 0.1);
	glVertex2i(1010, 470);
	glVertex2i(1090,470);
	glVertex2i(1100, 500);
	glVertex2i(1000,500);

	glEnd();



	glBegin(GL_POLYGON); 
	glColor3f(0.1, 0.3, 0.3);///middle box  back part
	glVertex2i(1000,500);
	glVertex2i(1100,500);
	glVertex2i(1080, 530);
	glVertex2i(1020,530);
	glEnd();


	glBegin(GL_POLYGON); //middle box
	glColor3f(0.19, 0.32, 0.12);

	glVertex2i(1020, 530);
	glVertex2i(1080,530);
	glVertex2i(1080,570);
	glVertex2i(1020,570);

	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.1, 0.3, 0.3);///middle box fornt part

	glVertex2i(1020, 570);
	glVertex2i(1080,570);
	glVertex2i(1100,600);
	glVertex2i(1000,600);

	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.0, 0.1);//front part

	glVertex2i(1000,600);
	glVertex2i(1100,600);
	glVertex2i(1090,630);
	glVertex2i(1010,630);
	glEnd();

	glPopMatrix();




}



void droppedOponent()
{

	if ((oponentstat==true) && (gameFlag==true))
	{

		if(oponentY<=-60)
		{
			if((posX==-30) && ((oponentX>=-490) && (oponentX<=-390)))
			{
				cout<<"Collision YO 1 value of oponentX:) "<<oponentX<<endl;
				gameFlag=false;
			}
			else if((posX==-25) && ((oponentX>=-440) && (oponentX<=-340)))
			{
				cout<<"Collision YO 2 value of oponentX:) "<<oponentX<<endl;
				gameFlag=false;
			}
			else if((posX==-20) && ((oponentX>=-390) && (oponentX<=-290)))
			{
				cout<<"Collision YO 3 value of oponentX:) "<<oponentX<<endl;
				gameFlag=false;
			}
			else if((posX==-15) && ((oponentX>=-340) && (oponentX<=-240)))
			{
				cout<<"Collision YO 4:) "<<endl;
				gameFlag=false;
			}
			else if((posX==-10) && ((oponentX>=-290) && (oponentX<=-190)))
			{
				cout<<"Collision YO 5:) "<<endl;
				gameFlag=false;
			}
			else if((posX==-5) && ((oponentX>=-240) && (oponentX<=-140)))
			{
				cout<<"Collision YO 6:) "<<endl;
				gameFlag=false;

			}
			else if((posX==0) && ((oponentX>=-190) && (oponentX<=-90)))
			{
				cout<<"Collision YO 7:) "<<endl;
				gameFlag=false;
			}
			else if((posX==5) && ((oponentX>=-140) && (oponentX<=-40)))
			{
				cout<<"Collision YO 8:) "<<endl;
				gameFlag=false;
			}
			else if((posX==10) && ((oponentX>=-90) && (oponentX<=10)))
			{
				cout<<"Collision YO 9:) "<<endl;
				gameFlag=false;
			}
			else if((posX==15) && ((oponentX>=-40) && (oponentX<=60)))
			{
				cout<<"Collision YO 10:) "<<endl;
				gameFlag=false;
			}
			else if((posX==20) && ((oponentX>=10) && (oponentX<=110)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==25) && ((oponentX>=60) && (oponentX<=160)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==30) && ((oponentX>=110) && (oponentX<=210)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==35) && ((oponentX>=160) && (oponentX<=260)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==40) && ((oponentX>=210) && (oponentX<=310)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==45) && ((oponentX>=260) && (oponentX<=360)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}
			else if((posX==50) && ((oponentX>=310) && (oponentX<=410)))
			{
				cout<<"Collision YO :) "<<endl;
				gameFlag=false;
			}

		}


		if(gameFlag==true)
		{
			oponentY-=1;
			score++;

		}


		//cout<<"y of opponent1: "<<opOneY+oponentY<<endl;

	}
	//cout<<"x value " <<opOneX+oponentX<<endl;
	while (oponentY<=-600)
	{

		oponentY=1600;

		randomOponent(200,-500);
		dropped=true;

	}


	glPushMatrix();
	glTranslatef(oponentX, oponentY, oponentZ);

	oponent2();
	glPopMatrix();
	//cout<<"x of opponent1: "<<oponentX<<endl;
	//cout<<"Y: "<<oponentY<<endl;
}






/*
void droppedOponent1()
{

if ((oponentstat1==true) && (gameFlag==true))
{

if(oponentY1<=-60)
{
if((posX==-30) && ((oponentX1>=-490) && (oponentX1<=-390)))
{
cout<<"Collision YO 1 value of oponentX:) "<<oponentX<<endl;
gameFlag=false;
}
else if((posX==-25) && ((oponentX1>=-440) && (oponentX1<=-340)))
{
cout<<"Collision YO 2 value of oponentX:) "<<oponentX<<endl;
gameFlag=false;
}
else if((posX==-20) && ((oponentX1>=-390) && (oponentX1<=-290)))
{
cout<<"Collision YO 3 value of oponentX:) "<<oponentX<<endl;
gameFlag=false;
}
else if((posX==-15) && ((oponentX1>=-340) && (oponentX1<=-240)))
{
cout<<"Collision YO 4:) "<<endl;
gameFlag=false;
}
else if((posX==-10) && ((oponentX1>=-290) && (oponentX1<=-190)))
{
cout<<"Collision YO 5:) "<<endl;
gameFlag=false;
}
else if((posX==-5) && ((oponentX1>=-240) && (oponentX1<=-140)))
{
cout<<"Collision YO 6:) "<<endl;
gameFlag=false;

}
else if((posX==0) && ((oponentX1>=-190) && (oponentX1<=-90)))
{
cout<<"Collision YO 7:) "<<endl;
gameFlag=false;
}
else if((posX==5) && ((oponentX1>=-140) && (oponentX1<=-40)))
{
cout<<"Collision YO 8:) "<<endl;
gameFlag=false;
}
else if((posX==10) && ((oponentX1>=-90) && (oponentX1<=10)))
{
cout<<"Collision YO 9:) "<<endl;
gameFlag=false;
}
else if((posX==15) && ((oponentX1>=-40) && (oponentX1<=60)))
{
cout<<"Collision YO 10:) "<<endl;
gameFlag=false;
}
else if((posX==20) && ((oponentX1>=10) && (oponentX1<=110)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==25) && ((oponentX1>=60) && (oponentX1<=160)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==30) && ((oponentX1>=110) && (oponentX1<=210)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==35) && ((oponentX1>=160) && (oponentX1<=260)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==40) && ((oponentX1>=210) && (oponentX1<=310)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==45) && ((oponentX1>=260) && (oponentX1<=360)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}
else if((posX==50) && ((oponentX1>=310) && (oponentX1<=410)))
{
cout<<"Collision YO :) "<<endl;
gameFlag=false;
}

}
}

if(gameFlag==true)
{
oponentY1-=1;
score++;

}
while (oponentY1<=-500)
{
oponentY1=1600;

randomOponent1(200,-600);
dropped1=true;

}


glPushMatrix();
glTranslatef(oponentX1, oponentY1, oponentZ1);

oponent1();
glPopMatrix();

//cout<<"Y: "<<oponentY<<endl;
}

*/

void tree0()
{
	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(190,-600);
	glVertex2i(220,-600);
	glVertex2i(220, -400);
	glVertex2i(190,-400);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,-500);
	glVertex2i(300,-500);
	glVertex2i(200,-300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,-450);
	glVertex2i(300,-450);
	glVertex2i(200,-250);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,-400);
	glVertex2i(300,-400);
	glVertex2i(200,-200);
	glEnd();

	//''''''''''''''' axis op...............





	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(1680,-600);
	glVertex2i(1710,-600);
	glVertex2i(1710,-400);
	glVertex2i(1680,-400);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,-500);
	glVertex2i(1790,-500);
	glVertex2i(1690,-300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,-450);
	glVertex2i(1790,-450);
	glVertex2i(1690,-250);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,-400);
	glVertex2i(1790,-400);
	glVertex2i(1690,-200);
	glEnd();

}
void tree1()
{
	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(-190,0);
	glVertex2i(-220,0);
	glVertex2i(-220, 200);
	glVertex2i(-190,200);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-120,100);
	glVertex2i(-300,100);
	glVertex2i(-200,300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-120,150);
	glVertex2i(-300,150);
	glVertex2i(-200,350);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-120,200);
	glVertex2i(-300,200);
	glVertex2i(-200,400);
	glEnd();

	//''''''''''''''' axis op...............





	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(-1680,0);
	glVertex2i(-1710,0);
	glVertex2i(-1710,200);
	glVertex2i(-1680,200);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-1610,100);
	glVertex2i(-1790,100);
	glVertex2i(-1690,300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-1610,150);
	glVertex2i(-1790,150);
	glVertex2i(-1690,350);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(-1610,200);
	glVertex2i(-1790,200);
	glVertex2i(-1690,400);
	glEnd();







	////------------------------
	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(190,0);
	glVertex2i(220,0);
	glVertex2i(220, 200);
	glVertex2i(190,200);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,100);
	glVertex2i(300,100);
	glVertex2i(200,300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,150);
	glVertex2i(300,150);
	glVertex2i(200,350);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,200);
	glVertex2i(300,200);
	glVertex2i(200,400);
	glEnd();









	//...............oposite tree..........................



	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(1680,0);
	glVertex2i(1710,0);
	glVertex2i(1710,200);
	glVertex2i(1680,200);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,100);
	glVertex2i(1790,100);
	glVertex2i(1690,300);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,150);
	glVertex2i(1790,150);
	glVertex2i(1690,350);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,200);
	glVertex2i(1790,200);
	glVertex2i(1690,400);
	glEnd();


}






void tree2()
{

	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(190,450);
	glVertex2i(220,450);
	glVertex2i(220, 650);
	glVertex2i(190,650);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,550);
	glVertex2i(300,550);
	glVertex2i(200,750);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,600);
	glVertex2i(300,600);
	glVertex2i(200,800);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,650);
	glVertex2i(300,650);
	glVertex2i(200,850);
	glEnd();


	//-----------------opposite 2---------------
	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(1680,450);
	glVertex2i(1710,450);
	glVertex2i(1710, 650);
	glVertex2i(1680,650);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,550);
	glVertex2i(1790,550);
	glVertex2i(1690,750);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,600);
	glVertex2i(1790,600);
	glVertex2i(1690,800);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,650);
	glVertex2i(1790,650);
	glVertex2i(1690,850);
	glEnd();

}




void tree3()
{

	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(190,950);
	glVertex2i(220,950);
	glVertex2i(220, 1150);
	glVertex2i(190,1150);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,1050);
	glVertex2i(300,1050);
	glVertex2i(200,1250);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,1100);
	glVertex2i(300,1100);
	glVertex2i(200,1300);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2,0.1);
	glVertex2i(120,1150);
	glVertex2i(300,1150);
	glVertex2i(200,1350);
	glEnd();
	//--------------------op 3------------




	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.3, 0.0);
	glVertex2i(1680,950);
	glVertex2i(1710,950);
	glVertex2i(1710, 1150);
	glVertex2i(1680,1150);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,1050);
	glVertex2i(1790,1050);
	glVertex2i(1690,1250);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,1100);
	glVertex2i(1790,1100);
	glVertex2i(1690,1300);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2,0.1);
	glVertex2i(1610,1150);
	glVertex2i(1790,1150);
	glVertex2i(1690,1350);
	glEnd();

}


void tree4()
{

	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.35, 0.1);
	glVertex2i(190,1400);
	glVertex2i(220,1400);
	glVertex2i(220, 1600);
	glVertex2i(190,1600);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,1500);
	glVertex2i(300,1500);
	glVertex2i(200,1700);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(120,1550);
	glVertex2i(300,1550);
	glVertex2i(200,1750);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2,0.1);
	glVertex2i(120,1600);
	glVertex2i(300,1600);
	glVertex2i(200,1800);
	glEnd();
	//----------op 4-----------

	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.35, 0.1);
	glVertex2i(1680,1400);
	glVertex2i(1710,1400);
	glVertex2i(1710, 1600);
	glVertex2i(1680,1600);
	glEnd();


	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,1500);
	glVertex2i(1790,1500);
	glVertex2i(1690,1700);
	glEnd();




	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2, 0.1);
	glVertex2i(1610,1550);
	glVertex2i(1790,1550);
	glVertex2i(1690,1750);
	glEnd();

	glBegin(GL_POLYGON); 
	glColor3f(0.0, 0.2,0.1);
	glVertex2i(1610,1600);
	glVertex2i(1790,1600);
	glVertex2i(1690,1800);
	glEnd();

}
void tree0Move()
{    
	if ((treeStatus == 1) && (gameFlag==true))
	{
		treeY +=0.5;
	}
	if (treeY<0)
	{
		treeY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	tree0();
	glPopMatrix();

}

void tree1Move()
{    
	if ((treeStatus == 1) && (gameFlag==true))
	{
		treeY -=0.5;
	}
	if (treeY<0)
	{
		treeY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	tree1();
	glPopMatrix();

}
void tree2Move()
{    
	if ((treeStatus == 1) && (gameFlag==true))
	{
		treeY -=0.5;
	}
	if (treeY<0)
	{
		treeY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	tree2();
	glPopMatrix();

}




void tree3Move()
{    
	if ((treeStatus == 1) && (gameFlag==true))
	{
		treeY -=0.5;
	}
	if (treeY<0)
	{
		treeY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	tree3();
	glPopMatrix();

}



void tree4Move()
{    
	if ((treeStatus == 1) && (gameFlag==true))
	{

		treeY -=0.5;
	}
	if (treeY<0)
	{
		treeY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	tree4();
	glPopMatrix();

}




/*	void box1Move()
{    
if (lineStatus == 1)
{
lineY -= 0.1;
}
if (lineY<-.5)
{
lineY = 1200;
}
glPushMatrix();
glTranslatef(0, lineY, 0);

box1();

glPopMatrix();



glPushMatrix();
glTranslatef(0, lineY, 0);

box2();

glPopMatrix();


} */

void road()
{
	//ground 1

	glBegin(GL_POLYGON); 
	glColor3f(0.4, 0.5, .1);
	glVertex2i(0, 0);
	glVertex2i(450, 0);
	glVertex2i(450, 1500);
	glVertex2i(0,1500);
	glEnd();



	glBegin(GL_POLYGON); 
	glColor3f(1.0, 1.0, 1.0);//line 1
	glVertex2i(450, 0);
	glVertex2i(500, 0);
	glVertex2i(500, 1500);
	glVertex2i(450,1500);
	glEnd();




	glBegin(GL_POLYGON); 
	//road
	glColor3f(0.4, 0.4, 0.2);
	glVertex2i(500, 0);
	glVertex2i(1400, 0);
	glVertex2i(1400, 1500);
	glVertex2i(500,1500);
	glEnd();


	glBegin(GL_POLYGON); 
	//line2
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(1400, 0);
	glVertex2i(1450, 0);
	glVertex2i(1450, 1500);
	glVertex2i(1400,1500);
	glEnd();



	glBegin(GL_POLYGON); 
	//ground
	glColor3f(0.4, 0.5, 0.1);
	glVertex2i(1450, 0);
	glVertex2i(2000, 0);
	glVertex2i(2000, 1500);
	glVertex2i(1450,1500);
	glEnd();

}





void linebox1()
{

	glBegin(GL_QUADS);  //1
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(900,-50);
	glVertex2i(950, -50);
	glVertex2i(950,-350);
	glVertex2i(900,-350);
	glEnd();
}

void linebox2()
{

	glBegin(GL_QUADS);  //3
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(900,-550);
	glVertex2i(950, -550);
	glVertex2i(950,-850);
	glVertex2i(900,-850);
	glEnd();

}
void linebox3()
{
	glBegin(GL_QUADS);  //3
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(900,50);
	glVertex2i(950, 50);
	glVertex2i(950,350);
	glVertex2i(900,350);
	glEnd();


}
void linebox4()
{
	glBegin(GL_QUADS);  //4
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(900,550);
	glVertex2i(950, 550);
	glVertex2i(950,850);
	glVertex2i(900,850);
	glEnd();
}
void linebox5()
{
	glBegin(GL_QUADS);  //5
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(900,1050);
	glVertex2i(950, 1050);
	glVertex2i(950,1350);
	glVertex2i(900,1350);
	glEnd();

}


void linebox1Move()
{    
	if( (lineStatus == 1) && (gameFlag==true))
	{
		lineY -=.5;
	}
	if (lineY<0)
	{
		lineY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	linebox1();
	glPopMatrix();

}
void linebox2Move()
{    
	if( (lineStatus == 1) && (gameFlag==true))
	{
		lineY -=.5;
	}
	if (lineY<0)
	{
		lineY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	linebox2();
	glPopMatrix();

}




void linebox3Move()
{    
	if( (lineStatus == 1) && (gameFlag==true))
	{
		lineY -=.5;
	}
	if (lineY<0)
	{
		lineY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	linebox3();
	glPopMatrix();

}



void linebox4Move()
{    
	if( (lineStatus == 1) && (gameFlag==true))
	{
		lineY -=.5;
	}
	if (lineY<0)
	{
		lineY = 1200;
	}
	glPushMatrix();
	glTranslatef(0, lineY, 0);
	linebox4();
	glPopMatrix();

}
void linebox5Move()
{    
	if( (lineStatus == 1) && (gameFlag==true))
	{
		lineY -=.5;
	}
	if (lineY<0)
	{
		lineY = 1200;
	}

	glPushMatrix();
	glTranslatef(0, lineY, 0);
	linebox5();
	glPopMatrix();

}




void myDisplay(void)

{     
	backGround();
	road();
	//box1();
	//box2();
	linebox1Move();
	linebox2Move();
	linebox3Move();
	linebox4Move();
	linebox5Move();

	droppedOponent();

	////droppedOponent1();

	tree0Move();
	tree1Move();
	tree2Move();
	tree3Move();
	tree4Move();

	MainCar();// car
	//box1Move();//oponent


	drawString(GLUT_BITMAP_9_BY_15,"Score:  ",600,1400);
	sprintf_s(buffer,"%d", score);
	drawString(GLUT_BITMAP_9_BY_15,buffer,750,1400);
	//cout << "POSX: "<<posX<<endl;

	glFlush();
	if(gameFlag==false && GOFlag==true)
	{
		drawString(GLUT_BITMAP_9_BY_15,"GAME OVER",1050,1400);
		sprintf_s(buffer,"%d", score);
	}


	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 2000.0, 0.0, 1500.0);
}

void keyboard(unsigned char key,int x,int y)

{

	if(key=='1')
	{		               //game start
		gameFlag =true;
		GOFlag = true;

	}
}

void handleSpecialKeypress(int key, int x, int y) {
	switch (key) {


	case GLUT_KEY_LEFT:

		LeftKeyPressed = true;
		if (!RightKeyPressed) {
			if( (posX>-30))
			{

				posX-=5;
				//cout<<"X position of main car"<<mainX+posX<<endl;
				//cout<<"X position of main car"<<mainY<<endl;
			}
		}
		break;
	case GLUT_KEY_RIGHT:
		RightKeyPressed = true;


		if (!LeftKeyPressed) {
			if( (posX<50))
			{
				posX+=5;

			}


		}

		break;
	}

}
void handleSpecialKeyReleased(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		LeftKeyPressed = false;
		break;
	case GLUT_KEY_RIGHT:
		RightKeyPressed = false;
		break;
	}

	glutPostRedisplay();
}

void main(int argc, char** argv)

{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(900, 1200);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("project");

	glutKeyboardFunc(keyboard);
	glutSpecialFunc(handleSpecialKeypress);
	glutSpecialUpFunc(handleSpecialKeyReleased);
	//glutMouseFunc(mouse);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
