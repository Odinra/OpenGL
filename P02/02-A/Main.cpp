#include <Windows.h>
#include <gl/glut.h>

GLuint listName = 1;


void reshape(GLsizei w, GLsizei h)
{
   glViewport(0, 0, (GLint) w, (GLint) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
             1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
             1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void init(void)
{
	glNewList(listName, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2f(0,0);
		glVertex2f(.1,0);
		glVertex2f(0,.1);
	glEnd();
		glRotatef(90, 1, 0, 0);
		glTranslatef(.01,.01,0);

	glEndList();
	glShadeModel(GL_FLAT);
}
void display(void)
{
	GLuint i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	for(i = 0; i < 2000; i++)
		glCallList(listName);
	glFlush();

}

void main (int argc, char** argv)
{
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(800,600);
	glutCreateWindow("Display Lists");	
	init();
	glutReshapeFunc(reshape);	
	glutDisplayFunc(display);

	glutMainLoop();
}