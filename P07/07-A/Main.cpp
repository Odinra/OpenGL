#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

GLuint RectangleList = 1, Wings = 2, Body = 3, Propellor = 4;

double propellation = 0;

void keyboard(unsigned char key, int x, int y);
void displayHelp();
void propellate();
void reshape(GLsizei w, GLsizei h)
{
   glViewport(0, 0, (GLint) w, (GLint) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //if (w <= h)
   //   glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
   //          1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   //else
   //   glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
   //          1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   gluPerspective(30, (GLfloat)w/(GLfloat)w, .1, 1000);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0,0,-5,0,0,0,0,1,0);
}


void init(void)
{
	glNewList(RectangleList, GL_COMPILE);
	glColor3f(0.6313,0.5137,0.4235);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex3f(0,0, 0);
			glColor3f(0.349, 0.3607, 0.3058);	
		glVertex3f(.2,0, 0);
			glColor3f(0.349, 0.3607, 0.3058);
		glVertex3f(0,0, .1);
			glColor3f(0.6313,0.5137,0.4235);
		glVertex3f(.2, 0, .1);
	glEnd();
		glTranslatef(.2,0,0);

	glEndList();

	glNewList(Wings, GL_COMPILE);
	GLuint i;
/*Top Wing
Top*/
	glTranslatef(-1,0,0);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
	glTranslatef(-2.0,0,.1);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
	glTranslatef(-2.0,0,.1);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
/*Top Wing 
Front*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-2.0,.1,0);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
/*Top Wing 
Bottom*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-2.0,.1,0);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
	glTranslatef(-2.0,0,.1);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
	glTranslatef(-2.0,0,.1);
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);
/*Top Wing
Back*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-2.0,.1,0);	
	for(i = 0; i < 10; i++)
		glCallList(RectangleList);

/*Bottom Wing
Top*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.8,-1.1,0);
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);
	glTranslatef(-1.6,0,.1);
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);

/*Bottom Wing
Front*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.6,.1,0);	
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);

/*Bottom Wing
Bottom*/	
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.6,.1,0);	
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);
	glTranslatef(-1.6,0,.1);
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);

/*Bottom Wing
Back*/
	glRotatef(90, 1, 0, 0);
	glTranslatef(-1.6,.1,0);		
	for(i = 0; i < 8; i++)
		glCallList(RectangleList);
/*Bottom Wing
Left*/
	glRotatef(90,0,0,1);
	glTranslatef(-.2,0,0);		
			glCallList(RectangleList);
/*Bottom Wing
Right*/
	glTranslatef(-.2,1.6,0);		
			glCallList(RectangleList);
			/*Top Wing
Right*/
	glTranslatef(-.3,.2,1.2);
		glCallList(RectangleList);
	glScalef(.5,1,1);
		glCallList(RectangleList);
/*Bottom Wing
Left*/
	glScalef(2,1,1);
	glTranslatef(-.3,-2,0);		
			glCallList(RectangleList);
	glScalef(.5,1,1);
		glCallList(RectangleList);

	glEndList();
	

	glNewList(Body, GL_COMPILE);
glCallList(Wings);
	glScalef(5.5, 5.5, 5.5);
	glTranslatef(-.8,.15,-.1);
	glRotatef(356, 0, 0, 1);
	for( i =0; i < 5; i++)
		glCallList(RectangleList);
	glTranslatef(-1, 0, -.1);
	for( i =0; i < 5; i++)
		glCallList(RectangleList);
	glTranslatef(-1, .05, .1);
		glRotatef(8, 0, 0, 1);
	for( i =0; i < 5; i++)
		glCallList(RectangleList);
	glTranslatef(-1, 0, -.1);
	for( i =0; i < 5; i++)
		glCallList(RectangleList);
	glTranslatef(-.017, -.195, 0);
	glRotatef(86, 0, 0, 1);
	for( i =0; i < 1; i++)
		glCallList(RectangleList);
	glTranslatef(-.2, 0, .1);
	for( i =0; i < 1; i++)
		glCallList(RectangleList);
	glTranslatef(-.13, 1, 0);
	glScalef(.3, 1, 1);
	for( i =0; i < 1; i++)
		glCallList(RectangleList);
	glTranslatef(-.2, 0, -.1);
	for( i =0; i < 1; i++)
		glCallList(RectangleList);
	glScalef(3.3333333333333333333333333333333333333333333333333333333333333333333333,.0475,1);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-.1275, 0, 20.9);
	for( i =0; i < 210; i++)
	{
		glCallList(RectangleList);
		glScaled(.995f,1,1);
		glTranslatef(-.2005,0,-.1);
		
	}
	for (i=0; i < 210; i++)
	{
		glScaled(1.005,1,1);
		glTranslatef(0, 0, .1);
	}
	glTranslatef(-.0675,.2,0);
	for( i =0; i < 210; i++)
	{
		glCallList(RectangleList);
		glScaled(.995f,1,1);
		glTranslatef(-.2005,0,-.1);
		
	}
	glEndList();
	glNewList(Propellor, GL_COMPILE);
	
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-.75,.0625, 0);
	glVertex3f(.75,.0625, 0);
	glVertex3f(-.75,-.125, 0);
	glVertex3f(.75, -.125, 0);

	glEnd();

	glEndList();
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	displayHelp();
}
void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0,1,0);
	
	glPushMatrix();
		glCallList(Body);
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(1,1,1);

	
	//glTranslatef(-0.75, -.65, -.56);
	glTranslatef(-0.75, -.65, -.56);
	//glTranslatef(0.75, .65, .56);
	glTranslatef(.75,0.09375,0);
	glRotatef(propellation,0,0,1);
	glTranslatef(-.75,-0.09375,0);
	//glPushMatrix();
	for (int i = 0; i < 5; i++)
	{
		//glPushMatrix();
		
				glTranslatef(.75,0.09375,0);
		glRotatef(72, 0, 0,1);
		glTranslatef(-.75,-0.09375,0);
		
		glCallList(Propellor);
		//glPopMatrix();
	}
	//glPopMatrix();
	glColor3f(0,0,0);
	glTranslatef(.75, .125, 0);
	glutSolidSphere(.25, 36, 36);

		
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void main (int argc, char** argv)
{
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(800,600);
	glutCreateWindow("Display Lists");	
	init();
	glutReshapeFunc(reshape);	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(propellate);

	glutMainLoop();
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'q':
	case 'Q':
		glRotatef(1,1,0,0);
		glutPostRedisplay();
		break;
	case 'a':
	case 'A':
		glRotatef(1,-1,0,0);
		glutPostRedisplay();
		break;
	case 'w':
	case 'W':
		glRotatef(1,0,1,0);
		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		glRotatef(1, 0, -1, 0);
		glutPostRedisplay();
		break;
	case 'e':
	case 'E':
		glRotatef(1,0,0,1);
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		glRotatef(1,0,0,-1);
		glutPostRedisplay();
		break;
			case 'j':
	case 'J':
		glTranslatef(.1,0,0);
		glutPostRedisplay();
		break;
	case 'l':
	case 'L':
		glTranslatef(-.1,0,0);
		glutPostRedisplay();
		break;
	case 'i':
	case 'I':
		glTranslatef(0,.1,0);
		glutPostRedisplay();
		break;
	case 'k':
	case 'K':
		glTranslatef(0,-.1,0);
		glutPostRedisplay();
		break;
	case 27:
		exit(0);

	default: break;
	}
}

void displayHelp()
{
	printf("\n***************** \t\tHelp\t\t *****************\n\n");

	printf("Keyboard\n\n");

	printf("Q and A rotate on the X Axis\n");
	printf("W and S rotate on the Y Axis\n");
	printf("E and D rotate on the Z Axis\n");
	printf("I and K move the camera Up and Down\n");
	printf("J and L move the camera Left and Right\n");

	printf("\n\n***************** \t\tHelp\t\t *****************\n\n");
}

void propellate()
{
	propellation += .5;
	if ( propellation > 360)
		propellation = 0;
	glutPostRedisplay();
}