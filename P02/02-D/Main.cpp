#include <Windows.h>
#include <gl/glut.h>
#include <fstream>
using namespace std;

void init(void)
{
	glClearColor(1, 1, 1.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600, 0.0, 600);
}
void keyboard(unsigned char key, int mouseX, int mouseY)
{
	switch(key)
	{
	case 'q':
		exit(0);
	default:
		break;
	}
}

void drawTxtFile()
{
	ifstream inStream;
	inStream.open("Knight.txt");
	if(inStream.fail())
		return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for(int j= 0; j < numpolys; j++)
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}

	glFlush();
	inStream.close();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawTxtFile();
	//glFlush();
}

void main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(660,240);
	glutInitWindowSize(600,600);
	glutCreateWindow("Knight");
	glutKeyboardFunc(keyboard);

	init();
	glutDisplayFunc(display);

	glutMainLoop();
}