
#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;
//variables
static int shoulder = 0;
static int elbow = 0;
static int head = 0;
static int hip = 0;
static int knees = 0;
static int torso = 0;
//viewport
void setViewPort(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h, 1.5, 20.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
//window
void SetWindow(float left, float right, float bottom, float top)
{

	
	gluOrtho2D(left, right, bottom, top);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);

}
//display with main portions of the robot
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(0.0, 0.0, 01.0);
	//Body
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef((GLfloat)torso, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0,1,0);
	glScalef(.75, 1.25, .50);
	glutWireCube(1.5);
	//left Upper Arm
	glPushMatrix();
	glTranslatef(0, .70, 0);
	glRotatef((GLfloat)shoulder, 1, 0, 0);
	glPushMatrix();
	glTranslatef(-1, -.5, 0);
	glScalef(.50, 1, .25);
	glutWireCube(1);
	//Left Lower Arm
	glPushMatrix();
	glTranslatef(0, -.5, 0);
	glRotatef((GLfloat)elbow, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, .5, 0);
	glScalef(1, 1, 1);
	glutWireCube(1);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Right Upper Arm
	glPushMatrix();
	glTranslatef(0, .70, 0);
	glRotatef((GLfloat)shoulder, 1, 0, 0);
	glPushMatrix();
	glTranslatef(1., -.5, 0);
	glScalef(.50, 1, .25);
	glutWireCube(1);
	//Right Lower Arm
	glPushMatrix();
	glTranslatef(0, -.5, 0);
	glRotatef((GLfloat)elbow, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, .5, 0);
	glScalef(1, 1, 1);
	glutWireCube(1);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Right Upper Leg
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef((GLfloat)hip, 0, 1, 0);
	glPushMatrix();
	glTranslatef(.5, -1.25, 0);
	glScalef(.25, 1, .5);
	glutWireCube(1);
	//Right Lower Leg
	glPushMatrix();
	glTranslatef(0, -.5, 0);
	glRotatef((GLfloat)knees, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, .5, 0);
	glScalef(1, 1, 1);
	glutWireCube(1);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//Left Upper Leg
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef((GLfloat)hip, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-.5, -1.25, 0);
	glScalef(.25, 1, .5);
	glutWireCube(1);
	//Left Lower Leg
	glPushMatrix();
	glTranslatef(0, -.5, 0);
	glRotatef((GLfloat)knees, -1, 0, 0);
	glPushMatrix();
	glTranslatef(0, .5, 0);
	glScalef(1, 1, 1);
	glutWireCube(1);

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//head
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef((GLfloat)head, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0,1.25, 0);
	glScalef(.75, .75, .75);
	glutWireCube(1);
	glPopMatrix();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
//rotations
void keyboard(unsigned char key, int x, int y)
{switch(key)
	{
	case'a':
		shoulder = (shoulder - 5)%360;
		glutPostRedisplay();
		break;
	case 'A':
		shoulder = (shoulder + 5)%360 ;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5)%360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5)%360;
		glutPostRedisplay();
		break;
	case 'l':
		hip = (hip + 5)%360;
		glutPostRedisplay();
		break;
	case 'L':
		hip = (hip - 5)%360;
		glutPostRedisplay();
		break;
	case 'h':
		head = (head + 5)%360;
		glutPostRedisplay();
		break;
	case 'H':
		head = (head - 5)%360;
		glutPostRedisplay();
		break;
	case 't':
		torso = (torso + 5)%360;
		glutPostRedisplay();
		break;
	case 'T':
		torso = (torso - 5)%360;
		glutPostRedisplay();
		break;
	case 'k':
		knees = (knees + 5)%360;
		glutPostRedisplay();
		break;
	case 'K':
		knees = (knees - 5)%360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
//main
void main (int argc, char** argv)
{
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600,600);
	glutCreateWindow(" Robot ");
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);

	setViewPort(600, 600);
	//SetWindow(0, 600, 0, 600);
	glutMainLoop();
}