/*Christopher King
Section 1031
Tower O' Rings*/
#include <Windows.h>
#include <gl/glut.h>

static int spinC = 0;
static int spinM = 0;

int ViewX = 600;
int ViewY = 600;
int iX = 0, iY = 0, iZ = 15;
int iV = -1, iC = 1;
bool bSmooth = true;

void setViewPort(int w, int h)
{
	glViewport(0,0,(GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)w/(GLfloat)h, 1, 100000000.0);
	glMatrixMode(GL_MODELVIEW);
	if (bSmooth)
		glShadeModel(GL_SMOOTH);
	else
		glShadeModel(GL_FLAT);

	glLoadIdentity();
	gluLookAt(iX,iY,iZ,0,0,0,0,1,0);
}
void init(void)
{
	GLfloat mat_specular[] = {.25, .50, .75, 1.0};
	GLfloat mat_shininess[] = {1};
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0};
	GLfloat white_light[] = {0, 1.0, 0, 1.0};
	GLfloat lmodel_ambient[] = {1.0, 1.0, 1., 1.0};
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glEnable(GL_LIGHT1);

	glClearColor(0,0,0,0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}
void display(void)
{

	GLfloat Position[] = {0.0, 0.0, 5, 1.0};
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0, -.25, 0);
	glPushMatrix();
	glRotated((GLdouble)spinM, 0.0, 1.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glTranslated(0.0, 0, 9);
	glDisable(GL_LIGHTING);
	glColor3f(0.0, 1.0, 1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	GLfloat light_position[] = {1.0, 1.0, 1.0, 0};
	//glRotated((GLdouble)spinM, 0, 1, 0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
	glPopMatrix();
	//tower
	glColor3f(.75, 0, .25);
	glPushMatrix();
	glRotatef(0, 0, 0, 0);
	glScalef(1, 10, 1);
	glTranslatef(0,0,0);
	glutSolidCube(1);
	glColor3f(.75, .25, 0);
	//Base
	glPushMatrix();
	glRotatef(1,0,0,0);
	glScalef(10,.1,1);
	glTranslatef(0,-5,0);
	glutSolidCube(1);
	glPopMatrix();
	//Top
	glPushMatrix();
	glRotatef(1,0,0,0);
	glScalef(1,.1,1);
	glTranslatef(0,6,0);
	glutSolidSphere(1,360,360);
	glPopMatrix();
	/**************************************************************************
	RINGS
	**************************************************************************/
	glColor3f(1,1,0);
	glPushMatrix();
	glScalef(1,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,9);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0,1);
	glPushMatrix();
	glScalef(.9,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,7);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0,0);
	glPushMatrix();
	glScalef(.8,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,5);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,0,1);
	glPushMatrix();
	glScalef(.7,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,3);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,1,0);
	glPushMatrix();
	glScalef(.6,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,1);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0,1,1);
	glPushMatrix();
	glScalef(.5,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-1);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0.6470588235294118,0);
	glPushMatrix();
	glScalef(.4,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-3);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(1,0.8431372549019608,0);
	glPushMatrix();
	glScalef(.3,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-5);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0.0980392156862745,0.0980392156862745,0.4392156862745098);
	glPushMatrix();
	glScalef(.25,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,0,-7);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();

	glColor3f(0.6901960784313725,0.1882352941176471,0.3764705882352941);
	glPushMatrix();
	glScalef(.25,.05,.5);
	glRotatef(90,1,0,0);
	glTranslatef(0,-0,-9);
	glutSolidTorus(1.0, 2, 15, 15);
	glPopMatrix();


	glPopMatrix();



	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'c':
		{
			/*iX = (iX + 1) % 15;*/
			iX += iC;
			if (iX > 15)
				iC *= -1;
			else if (iX < -15)
				iC *= -1;


			iZ += iV;
			if ( iZ < -15)
				iV *= -1;
			else if ( iZ > 15)
				iV *= -1;

			setViewPort(ViewX, ViewY);
			glutPostRedisplay();
		}
		break;
	case 'C':
		{
			spinC = (spinC - 5) % 360;
			iX -= iC;
			if (iX > 15)
				iC *= -1;
			else if (iX < -15)
				iC *= -1;


			iZ -= iV;
			if ( iZ < -15)
				iV *= -1;
			else if ( iZ > 15)
				iV *= -1;

			setViewPort(ViewX, ViewY);
			glutPostRedisplay();
		}
		break;
	case 'f':
		bSmooth = false;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
		break;
	case 's':
		bSmooth = true;
		setViewPort(ViewX, ViewY);
		glutPostRedisplay();
		break;
	case 'm':
		{
			spinM = (spinM + 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'M':
		{
			spinM = (spinM + 5) % 360;
			glutPostRedisplay();
		}
		break;
	case 'l':
		{
			glEnable(GL_LIGHT1);
			glutPostRedisplay();
		}
		break;
	case 'L':
		{
			glDisable(GL_LIGHT1);
			glutPostRedisplay();
		}
		break;
	default:
		break;
	}
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(600, 600);
	glutCreateWindow(" ");
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);

	setViewPort(ViewX, ViewY);
	glutMainLoop();
}