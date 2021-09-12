#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#define height 480

int redx=510;
int redy=295;

int greenx=510;
int greeny=255;

int bluex=510;
int bluey=215;

int grey;
int insert;

void * stroke_fonts[2] = {
GLUT_STROKE_ROMAN,
GLUT_STROKE_MONO_ROMAN
};

void glPrintString(int fontnum, char* s)
{
	if (s && strlen(s))
	{
		while (*s)
		{
			glutStrokeCharacter(stroke_fonts[fontnum], *s);
			s++;
		}
	}
}

void myInit(void)
{
glClearColor(1.0,1.0,1.0,0.0); //white background
glPointSize(25);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();


gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void cizgiler(int x1,int y1,int x2,int y2,int x)
{
	glBegin(GL_LINES);
	glColor3f(x,x,x);
	glVertex2i(x1,y1);
	glVertex2i(x1,y2);

	glVertex2i(x1,y2);
	glVertex2i(x2,y2);

	glVertex2i(x2,y2);
	glVertex2i(x2,y1);
	
	glVertex2i(x2,y1);
	glVertex2i(x1,y1);
	glEnd();
	glFlush();
}


void yazilar(void)
{
	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(505, 385, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "Insert New Node");
	glPopMatrix();
	glFlush();
	
	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(500,335, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "Sphere");
	glPopMatrix();
	glFlush();

	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(580,335, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "Cube");
	glPopMatrix();
	glFlush();
//
	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(485,285, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "R");
	glPopMatrix();

	glFlush();
	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(485,245, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "G");
	glPopMatrix();
	glFlush();

	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(485,205, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "B");
	glPopMatrix();
	glFlush();

	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(505,145, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "Insert/Select Edge");
	glPopMatrix();
	glFlush();

	glPushMatrix();
		glColor3f(0,0,0);
		glTranslatef(525,85, 0.0);
		glScalef(15/152.38, 40/152.38, 1);
		glPrintString(0, "Delete Item");
	glPopMatrix();
	glFlush();


}

void myMouse(int button, int state, int x, int y)
{
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		

		if(x>=500 && x<= 620 && (height-y)>=380 && (height-y)<= 420)
		{
			insert=1;
			glColor3f(0.5,0.5,0.5);
			glRecti(500,380,620,420);
			cizgiler(500,380,620,420,0);

			glColor3f(1.0,1.0,1.0);
			glRecti(490,140,630,180);
			cizgiler(490,140,630,180,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(500,80,620,120);
			cizgiler(500,80,620,120,0);
			
			yazilar();
			glFlush();
			
		}
		
		if(insert==1)
		{
			
			if(x>=490 && x<= 555 && (height-y)>=330 && (height-y)<= 370)
			{
				glColor3f(0.5,0.5,0.5);
				glRecti(490,330,555,370);
				cizgiler(490,330,555,370,0);
				
				glColor3f(1,1,1);
				glRecti(560,330,630,370);
				cizgiler(560,330,630,370,0);

				yazilar();
				glFlush();
			}
			if(x>=560 && x<= 630 && (height-y)>=330 && (height-y)<= 370)
			{
				glColor3f(0.5,0.5,0.5);
				glRecti(560,330,630,370);
				cizgiler(560,330,630,370,0);
				
				glColor3f(1,1,1);
				glRecti(490,330,555,370);
				cizgiler(490,330,555,370,0);

				yazilar();
				glFlush();
			}
		}

		
		if(x>=490 && x<= 630 && (height-y)>=140 && (height-y)<= 180)
		{
			insert=0;
			
			if(grey==1)
			{
				glColor3f(1,1,1);
				glRecti(490,140,630,180);
				cizgiler(490,140,630,180,0);
				grey=0;

				glColor3f(1.0,1.0,1.0);
				glRecti(500,380,620,420);
				cizgiler(500,380,620,420,0);

				glColor3f(1.0, 1.0, 1.0);
				glRecti(500,80,620,120);
				cizgiler(500,80,620,120,0);

				yazilar();
				glFlush();
			}else 
			{
				
				glColor3f(0.5,0.5,0.5);
				glRecti(490,140,630,180);
				cizgiler(490,140,630,180,0);
				grey=1;

				glColor3f(1.0,1.0,1.0);
				glRecti(500,380,620,420);
				cizgiler(500,380,620,420,0);

				glColor3f(1.0, 1.0, 1.0);
				glRecti(500,80,620,120);
				cizgiler(500,80,620,120,0);

				yazilar();
				glFlush();
			}

		}			
		
		if(x>=500 && x<= 620 && (height-y)>=80 && (height-y)<= 120)
		{
			insert=0;

			glColor3f(0.5,0.5,0.5);
			glRecti(500,80,620,120);
			cizgiler(500,80,620,120,0);

			glColor3f(1.0,1.0,1.0);
			glRecti(490,140,630,180);
			cizgiler(490,140,630,180,0);
			
			glColor3f(1.0, 1.0, 1.0);
			glRecti(500,380,620,420);
			cizgiler(500,380,620,420,0);

			yazilar();
			glFlush();
		}

		if(x>=510 && x<= 610 && (height-y)>=275 && (height-y)<= 315)
		{
			insert=0;
			redx=x;
			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,275,610,315);
			cizgiler(510,275,610,315,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,235,610,275);
			cizgiler(510,235,610,275,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,195,610,235);
			cizgiler(510,195,610,235,0);
			//
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(redx,redy);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(greenx,greeny);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(bluex,bluey);
			glEnd();
			glFlush();

		}

		if(x>=510 && x<= 610 && (height-y)>=235 && (height-y)< 275)
		{
			insert=0;
			greenx=x;
			//glutPostRedisplay();
			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,275,610,315);
			cizgiler(510,275,610,315,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,235,610,275);
			cizgiler(510,235,610,275,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,195,610,235);
			cizgiler(510,195,610,235,0);
			//
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(redx,redy);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(greenx,greeny);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(bluex,bluey);
			glEnd();
			glFlush();
		}

		if(x>=510 && x<= 610 && (height-y)>=195 && (height-y)< 235)
		{
			insert=0;
			bluex=x;
			//	glutPostRedisplay();
			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,275,610,315);
			cizgiler(510,275,610,315,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,235,610,275);
			cizgiler(510,235,610,275,0);

			glColor3f(1.0, 1.0, 1.0);
			glRecti(510,195,610,235);
			cizgiler(510,195,610,235,0);
			//
			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(redx,redy);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(greenx,greeny);
			glEnd();
			glFlush();

			glBegin(GL_POINTS);
			glColor3f(0.0, 0.0, 0.0);
			glVertex2i(bluex,bluey);
			glEnd();
			glFlush();
		}
	}
}

void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glColor3f(1.0, 1.0, 1.0);
glRecti(480,0,640,480);
cizgiler(480,0,640,480,0);

glColor3f(1.0, 1.0, 1.0);
glRecti(500,380,620,420);
cizgiler(500,380,620,420,0);

glColor3f(0.5, 0.5, 0.5);
glRecti(490,330,555,370);
cizgiler(490,330,555,370,0);

glColor3f(1.0, 1.0, 1.0);
glRecti(560,330,630,370);
cizgiler(560,330,630,370,0);

//
glColor3f(1.0, 1.0, 1.0);
glRecti(481,275,510,315);
cizgiler(481,275,510,315,1);

glColor3f(1.0, 1.0, 1.0);
glRecti(481,235,510,275);
cizgiler(481,235,510,275,1);

glColor3f(1.0, 1.0, 1.0);
glRecti(481,195,510,235);
cizgiler(481,195,510,235,1);
//
glColor3f(1.0, 1.0, 1.0);
glRecti(510,275,610,315);
cizgiler(510,275,610,315,0);

glColor3f(1.0, 1.0, 1.0);
glRecti(510,235,610,275);
cizgiler(510,235,610,275,0);

glColor3f(1.0, 1.0, 1.0);
glRecti(510,195,610,235);
cizgiler(510,195,610,235,0);
//

glBegin(GL_POINTS);
glColor3f(0.0, 0.0, 0.0);
glVertex2i(redx,redy);
glEnd();
glFlush();

glBegin(GL_POINTS);
glColor3f(0.0, 0.0, 0.0);
glVertex2i(greenx,greeny);
glEnd();
glFlush();

glBegin(GL_POINTS);
glColor3f(0.0, 0.0, 0.0);
glVertex2i(bluex,bluey);
glEnd();
glFlush();

//
glColor3f(1.0, 1.0, 1.0);
glRecti(490,140,630,180);
cizgiler(490,140,630,180,0);

glColor3f(1.0, 1.0, 1.0);
glRecti(500,80,620,120);
cizgiler(500,80,620,120,0);

glFlush();
yazilar();

}

int main(int argc, char** argv)
{
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(640,480); 


glutInitWindowPosition(100, 150);


glutCreateWindow("Button Example");


myInit();
glutDisplayFunc(myDisplay);
glutMouseFunc(myMouse);
glutMainLoop(); 
return 1;
}