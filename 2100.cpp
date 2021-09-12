#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#define height 480
#define NULL 0
#define BUFSIZE 512

int xStart, yStart, zStart;
int rotating, zooming;
int selectMode = 0;

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

/* cube modeling definitions */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

/* various globals used for rotating, zooming the image, */
/* and toggling the spinning sphere and lighting */
GLfloat yAngle = 10.0;   /* in degrees */
GLfloat xAngle = 10.0;   /* in degrees */
GLfloat zoom = 0.0;      /* translation along z-axis */

/* routine to draw a cube */
void drawBox(void)
{
  int i;

  for (i = 0; i < 6; i++) {
    glBegin(GL_POLYGON);
	glColor3f(0.3,0.4,0.6);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void drawScene()
{
  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 80.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 8.0,  /* eye is at (0,0,8) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

  /* draw cube and translated/rotated sphere */
  glPushMatrix();
    glTranslatef(0.0, 0.0, zoom);
    glRotatef(xAngle, 1.0, 0.0, 0.0);
    glRotatef(yAngle, 0.0, 1.0, 0.0);
    drawBox();
  glPopMatrix();
}

//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
/* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

	
glClearColor(1.0,1.0,1.0,0.0); //white background
glPointSize(25);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

//set the viewing coordinates
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



//<<<<<<<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_MIDDLE_BUTTON) {
	    	if (state == GLUT_DOWN) {
		  	rotating = 1;
		  	xStart = x;
		  	yStart = y;
	    	} else {
		  	rotating = 0;
	    	}
      	} else if (button == GLUT_RIGHT_BUTTON) {
	    	if (state == GLUT_DOWN) {
		  	zooming = 1;
		  	zStart = y;
	    	} else {
		  	zooming = 0;
	    	}
      	}

	
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
			glutPostRedisplay();
		}

		if(x>=510 && x<= 610 && (height-y)>=235 && (height-y)< 275)
		{
			insert=0;
			greenx=x;
			glutPostRedisplay();
		}

		if(x>=510 && x<= 610 && (height-y)>=195 && (height-y)< 235)
		{
			insert=0;
			bluex=x;
			glutPostRedisplay();
		}
	}
}

/* mouse motion function -- update rotated or zoomed scene */
void motion(int x, int y)
{
  if (rotating) {
    yAngle += (x - xStart);
    xAngle += (y - yStart);
    xStart = x;
    yStart = y;
    glutPostRedisplay();
  } else if (zooming) {
    zoom += (y - zStart)/10.0;
    zStart = y;
    glutPostRedisplay();
  }
}


//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT); // clear the screen

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

glFlush(); // send all output to display
yazilar();

}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
glutInit(&argc, argv); // initialize the toolkit
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(640,480); // set window size

// set window position on screen
glutInitWindowPosition(100, 150);

// open the screen window and set the name
glutCreateWindow("Button Example");

//register your functions
myInit();
glutDisplayFunc(myDisplay);
glutMouseFunc(myMouse);
glutMotionFunc(motion);
glutMainLoop(); // go into a perpetual loop
return 1;
}
