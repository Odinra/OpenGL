#include <Windows.h>
#include <gl/glut.h>
#include <iostream>

using namespace std;

//globals
static int view = 7;
static int ViewX = 600;
static int ViewY = 600;
int Hour = 0, iHCount = 0;
int Day =0;
int iZoom = 1;
void displayHelp();
bool bOrtho = false;


//viewport function
void setViewPort(int w, int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//test whether in ortho or perspective mode
	if (!bOrtho)
		gluPerspective(60,(GLfloat)w/(GLfloat)h, 1.0, 2000);
	else
		glOrtho(0,w,0,h,1,20000);

	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	gluLookAt(0.0, 150, 45, 0.0, 0.0, 0.0, 0, 1.0, 2.0);
}
//set the window
void SetWindow(float left, float right, float bottom, float top)
{


	gluOrtho2D(left, right, bottom, top);
}
//initialization
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
	//show help in unused window
	displayHelp();

}

void display(void)
{
	//planets
	glClear(GL_COLOR_BUFFER_BIT);	
	//sun
	glColor3f(1, .8, .2);
	glPushMatrix();
	glutWireSphere(5, 30, 30);
	glPopMatrix();
	//mercury
	glColor3f(0.8862745098039216,0.8862745098039216,0.8862745098039216);
	glPushMatrix();
	glTranslatef(30,0,0);
	glScalef(0.0035714285714286,0.0035714285714286,0.0035714285714286);
	glutWireSphere(5,15, 15);
	glPopMatrix();
	//Venus
	glColor3f(0.5686274509803922,0.5294117647058824,0.5686274509803922);
	glPushMatrix();
	glTranslatef(55,0,0);
	glScalef(0.0085714285714286,0.0085714285714286,0.0085714285714286);
	glutWireSphere(5,15,15);
	glPopMatrix();


	//Earth
	glColor3f(0,0.2431372549019608,0.2823529411764706);
	glPushMatrix();

	glRotatef((GLfloat)Day, 0, 0, 1);
	glTranslatef(75,0,0);
	glRotatef((GLfloat)Hour,0,0,1);
	glScalef(0.0091428571428571,0.0091428571428571,0.0091428571428571);
	glutWireSphere(5,15,15);
	//Moon.
	glColor3f(0.8392156862745098,0.8352941176470588,0.7529411764705882);
	glPushMatrix();	
	glRotatef((GLfloat)Day / 0.0777777777777778 , 0, 0, 1);
	glRotatef((GLfloat)Day / 0.0777777777777778 , 1, 0, 0);
	glTranslatef(19.219925,0,0);
	glScalef(0.2715625,0.2715625,0.2715625);
	glutWireSphere(5,15,15);
	glPopMatrix();
	glPopMatrix();


	//Mars
	glColor3f(0.8705882352941176,0.5254901960784314, 0.1647058823529412);
	glPushMatrix();
	glTranslatef(115,0,0);
	glScalef(.005,.005,.005);
	glutWireSphere(5,15,15);
	glPopMatrix();
	//Jupiter
	glColor3f(0.592156862745098,0.5529411764705882, 0.4980392156862745);
	glPushMatrix();
	glTranslatef(390,0,0);
	glScalef(.1,.1,.1);
	glutWireSphere(5,15,15);
	glPopMatrix();
	//Saturn
	glColor3f(0.7254901960784314,0.6235294117647059, 0.4666666666666667);
	glPushMatrix();
	glTranslatef(700,0,0);
	glScalef(0.8571428571428571,0.8571428571428571,0.8571428571428571);
	glutWireSphere(5,15,15);
	glPopMatrix();
	//Uranus
	glColor3f(0.0980392156862745,0.4431372549019608, 0.5647058823529412);
	glPushMatrix();
	glTranslatef(1450,0,0);
	glScalef(0.0371428571428571,0.0371428571428571,0.0371428571428571);
	glutWireSphere(5,15,15);
	glPopMatrix();
	//Neptune
	glColor3f(0.4392156862745098,0.7176470588235294,0.7294117647058824);
	glPushMatrix();
	glTranslatef(2250,0,0);
	glScalef(0.0357142857142857,0.0357142857142857,0.0357142857142857);
	glutWireSphere(5,15,15);
	glPopMatrix();
	//Pluto
	glColor3f(0.196078431372549,0.203921568627451,0.2156862745098039);
	glPushMatrix();
	glTranslatef(300,0,0);
	glScalef(0.0021428571428571,0.0021428571428571,0.0021428571428571);
	glutWireSphere(5,15,15);
	glPopMatrix();

	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{switch(key)
{
case 'h'://hours
	Hour = (Hour+15)%360;
	iHCount++;
	if(iHCount >= 24)
	{
		iHCount = 0;
		Day = (Day + 1)%360;
	}
	glutPostRedisplay();
	break;
case 'd'://days
	Day = (Day + 1)%360;
	glutPostRedisplay();
	break;
case 'D'://days*10
	Day = (Day + 10)%360;
	glutPostRedisplay();
	break;
case 'w'://zoom on y
	iZoom = 1;
	glTranslatef(0,iZoom, 0);
	glutPostRedisplay();
	break;
case 'q'://zoom on y
	iZoom = 1;
	glTranslatef(0,-iZoom, 0);
	glutPostRedisplay();
	break;
case 's'://zoom on x
	iZoom = 1;
	glTranslatef(iZoom, 0, 0);
	glutPostRedisplay();
	break;
case 'a'://zoom on x
	iZoom = 1;
	glTranslatef(-iZoom,0, 0);
	glutPostRedisplay();
	break;
case 'x'://zoom on z
	iZoom = 1;
	glTranslatef(0, 0,-iZoom);
	glutPostRedisplay();
	break;
case 'z'://zoom on z
	iZoom = 1;
	glTranslatef(0, 0, iZoom);
	glutPostRedisplay();
	break;
case 'o'://set to ortho mode
	bOrtho = true;
	setViewPort(ViewX, ViewY);
	glutPostRedisplay();
	break;
case 'p'://set to perspective mode
	bOrtho = false;
	setViewPort(ViewX, ViewY);
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
	glutCreateWindow("Solar System");
	glutKeyboardFunc(keyboard);

	init();

	glutDisplayFunc(display);

	setViewPort(ViewX, ViewY);
	//SetWindow(0, 600, 0, 600);
	glutMainLoop();
}
//display help info on the second unused screen
void displayHelp()
{
	printf("\n***************** \t\tHelp\t\t *****************\n\n");

	printf("Keyboard\n\n");

	printf(" %s\t\t%s\n", "Q W zoom in and Out");
	printf(" %s\t\t%s\n", "A S zoom left and right");
	printf(" %s\t\t%s\n", "Z X Zoom Up and Down");
	printf(" %s\t\t\t%s\n", "O", " Ortho Mode (Sun starts in bottom left corner in Ortho Mode");
	printf(" %s\t\t\t%s\n", "P", " Perspective Mode");

	printf(" %s\t\t%s\n", "h, d, D", "change the houes, Days, and 10 Days respecively");

	printf("\n\n***************** \t\tHelp\t\t *****************\n\n");
}