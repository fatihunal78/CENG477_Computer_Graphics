#include <GL/glut.h>
#include <cstdlib>

const GLfloat
        light_pos[]      = {0, 0, 0, 1} ,
        light_ambient[]  = {0.1, 0.1, 0.1, 1} ,
        light_diffuse[]  = {1, 1, 1, 1} ,
        light_specular[] = {1, 1, 1, 1} ;

static int iteration = 0;

static GLint
        slices = 30 ,
        stacks = 30 ;

void myCreateObjects(int iteration)
{
        GLfloat
                white[] = {1, 1, 1, 1},
                red[] = {1, 0, 0, 1},
                green[] = {0, 1, 0, 1},
                blue[] = {0, 1, 1, 1},
                spec_exp = 100;

        glPushAttrib(GL_LIGHTING_BIT);
        glDisable(GL_LIGHTING);
        glColor3ub(255, 255, 0);
        glutSolidSphere(5, slices, stacks);
        glPopAttrib();

        glMaterialfv(GL_FRONT, GL_AMBIENT, white);
        glMaterialfv(GL_FRONT, GL_SPECULAR, white);
        glMaterialf(GL_FRONT, GL_SHININESS, spec_exp);

        for (int i(1); i <=3; ++i) {
                glPushMatrix();
                glRotatef((iteration) * 3/i, 0, 1, 0);
                glTranslatef(i * 10, 0, 0);
                switch (i)
                {
                        case 1: glMaterialfv(GL_FRONT, GL_DIFFUSE, red) ;
                        break ;
                        case 2: glMaterialfv(GL_FRONT, GL_DIFFUSE, green) ;
                        break ;
                        case 3: glMaterialfv(GL_FRONT, GL_DIFFUSE, blue) ;
                        break ;
                        default: glMaterialfv(GL_FRONT, GL_DIFFUSE, white) ;
                }
                glutSolidSphere(2, slices, stacks);
                glPopMatrix();
        }
}

void myKeyHandler(unsigned char key, int x, int y)
{
        //While mouse over this window
        if (key == 'q') {
                exit(0);
        }
}

void myDisplay()
{
}

void myReshape(int w, int h)
{
        GLint border = 10 ;
        GLint size_of_curve ;
        GLint low_left_x, low_left_y ;
        if (w > h) {
                if (h < 2 * border) {
                        border = 0 ;
                } /* endif */
                size_of_curve = h - 2 * border ;
                low_left_x = static_cast<GLint>(0.5 * (w - size_of_curve)) ;
                low_left_y = border ;
        } else {
                if (w < 2 * border) {
                        border = 0 ;
                } /* endif */
                size_of_curve = w - 2 * border ;
                low_left_x = border ;
                low_left_y = static_cast<GLint>(0.5 * (h - size_of_curve)) ;
        } /* endif */
        glViewport(low_left_x, low_left_y, size_of_curve, size_of_curve) ;
}

void myIdle()
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        myCreateObjects(++iteration);
        glFlush();
        glutSwapBuffers();
        glutPostRedisplay();
}

void myInit()
{
        GLdouble aspect = 1;
        glClearColor(0.0, 0.0, 0.2, 0.0);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45, aspect, 50, -50);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 20, 80,  0, 0, 0,  0, 1, 0);

        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glShadeModel(GL_SMOOTH);
        glEnable(GL_DEPTH_TEST);

}


int main(int argc, char** argv)
{
       glutInit(&argc, argv);
       glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
       glutInitWindowSize(640, 480);
       glutInitWindowPosition(100, 150);
       glutCreateWindow("Solar System");
       glutKeyboardFunc(myKeyHandler);
       glutDisplayFunc(myDisplay);
       glutReshapeFunc(myReshape);
       glutIdleFunc(myIdle);
       myInit();
       glutMainLoop();
	   return 0;
}