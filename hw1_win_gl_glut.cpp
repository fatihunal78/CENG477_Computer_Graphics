#include <stdio.h>
#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <math.h>

#define Width 640
#define Height 480

const int MAX_POINTS = 100 ;
int Npoints=0;
int Points[MAX_POINTS][3] ;
int Pointdistance[MAX_POINTS];
int Lines[1000][4];

int sel;
int pnt;
int line;
int dst;
int lineno=0;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0) ;
	glColor3f(0.0, 0.0, 0.0) ;
	glPointSize(4.0) ;
	glMatrixMode(GL_PROJECTION) ;
	glLoadIdentity() ;
	gluOrtho2D(0.0, 640.0, 0.0, 480.0) ;
}

void mydrag(int x,int y)
{
	if(sel)
	{
	Points[dst][0]=x;
	Points[dst][1]=Height-y;
	}
	glutPostRedisplay() ;
}
void myMouse(int button, int state, int x, int y)
{
	int i;
	int min;

	if( button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN )
	{
		if( Npoints < MAX_POINTS )
		{
			Points[Npoints][0] = x ;
			Points[Npoints][1] = Height - y ;
			Npoints++ ;
		}

	}

	if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
		line=1;
		
		for(i=0;i<Npoints;i++)
		{
			Pointdistance[i]=sqrt( (abs(Points[i][0]-x) * abs(Points[i][0]-x)) +
				(abs(Points[i][1]- (Height-y)) * abs(Points[i][1]- (Height-y)) ) );
		}	

		pnt=0;	

		for(i=1;i<Npoints;i++)
		{
			if(Pointdistance[pnt] > Pointdistance[i])
			{
				pnt=i;
			}
		}
		
		Lines[lineno][0]=Points[dst][0];
		Lines[lineno][1]=Points[dst][1];
		Lines[lineno][2]=Points[pnt][0];
		Lines[lineno][3]=Points[pnt][1];
		lineno++;
	} else line=0;
	
	if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		sel=1;

		for(i=0;i<Npoints;i++)
		{
			Pointdistance[i]=sqrt( (abs(Points[i][0]-x) * abs(Points[i][0]-x)) +
				(abs(Points[i][1]- (Height-y)) * abs(Points[i][1]- (Height-y)) ) );
		}	

		min=0;	

		for(i=1;i<Npoints;i++)
		{
			if(Pointdistance[min] > Pointdistance[i])
			{
				min=i;
			}
		}

		for(i=0;i<Npoints;i++)
		{
			if(i==min)
			{
				Points[i][2]=1;
				dst=i;
			}
			else Points[i][2]=0;
		}
	} else sel=0;


	
	glutPostRedisplay() ;
}

void myDisplay(void) 
{
	glClear(GL_COLOR_BUFFER_BIT) ;
	glBegin(GL_POINTS) ;
	int i ;
	for(i = 0; i < Npoints ; i++ )
	{
		if(Points[i][2]==1)
		{
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(Points[i][0],Points[i][1]) ;
		}
		else
		{
		glColor3f(0.0, 0.0, 0.0);
		glVertex2i(Points[i][0],Points[i][1]) ;
		}
	}
	glEnd() ;

	for(i=0;i<lineno;i++)
	{
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(Lines[i][0],Lines[i][1]);
	glVertex2i(Lines[i][2],Lines[i][3]);
	glEnd();
	}
	glutSwapBuffers() ;
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv) ;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB) ;
	glutInitWindowSize(Width, Height) ;
	glutInitWindowPosition(0,0) ;
	glutCreateWindow("graph homework") ;
	myInit() ;
	glutDisplayFunc(myDisplay) ;
	glutMouseFunc(myMouse) ;
	glutMotionFunc(mydrag);
	
	glutMainLoop() ;
}



