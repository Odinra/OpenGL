#include <GL/glut.h>



float rotateTorus = 30;
float rotateCube = 15;
float rotateTeapot = 10;

static void init(void)
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 0.15 };
   GLfloat mat_shininess[] = { 100.0 };
   GLfloat position[] = { 0.5, 0.5, 1.0, 0.0 };

   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);

}

void display(void)
{
   GLfloat mat_solid[] = { 0.75, 0.75, 0.0, 1.0 };
   GLfloat mat_zero[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_transparent[] = { 0.0, 0.8, 0.8, 0.6 };
   GLfloat mat_emission[] = { 0.0, 0.3, 0.3, 0.6 };

      GLfloat mat_solid2[] = { 0.75, 0.75, 0.75, .45 };
   GLfloat mat_zero2[] = { 0.3, 0.3, .3, 1.0 };
   GLfloat mat_transparent2[] = { 0.8, 0.0, 0.8, 0.3 };
   GLfloat mat_emission2[] = { 0.3, 0.3, 0.3, 0.6 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glPushMatrix ();
  
      glTranslatef (-0.15, -0.15, 0); 
	  glRotatef (rotateCube, 1.0, 1.0, 0.0);
      glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid);
      glutSolidCube(.5);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef (0.15, 0.15, 0);
      glRotatef (15, 1.0, 1.0, 0.0);
      glRotatef (rotateTorus, 0.0, 1.0, 0.0);
      glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent);
      glEnable (GL_BLEND);
      glDepthMask (GL_FALSE);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE);
      glutSolidTorus(.25, .25,360,360);
      glDepthMask (GL_TRUE);
      glDisable (GL_BLEND);
   glPopMatrix ();

   glPushMatrix ();
      glTranslatef (1, .15, 0);
      glRotatef (rotateTeapot, 1.0, 1.0, 1.0);
      glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission2);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_transparent2);
      glEnable (GL_BLEND);
      glDepthMask (GL_FALSE);
      glBlendFunc (GL_ONE_MINUS_SRC_ALPHA, GL_ONE);
      glutSolidTeapot(.5);
      glDepthMask (GL_TRUE);
      glDisable (GL_BLEND);
   glPopMatrix ();

  glPushMatrix ();
      glTranslatef (0.55, -0.15, 0);
      glRotatef (15, 1.0, 1.0, 0.0);
      glRotatef (rotateTorus, 0.0, 1.0, 0.0);
      glMaterialfv(GL_FRONT, GL_EMISSION, mat_zero2);
      glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_solid2);
      glEnable (GL_BLEND);
      glDepthMask (GL_FALSE);
      glBlendFunc (GL_SRC_ALPHA, GL_ONE);
      glutSolidSphere(.25, 360, 360);
      glDepthMask (GL_TRUE);
      glDisable (GL_BLEND);
   glPopMatrix ();

   glutSwapBuffers();
}

void reshape(int w, int h)
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


void move(void)
{
	rotateTorus += .5;
	if(rotateTorus >= 360)
		rotateTorus = 0;

	rotateCube += 1;
	if(rotateCube >= 360)
		rotateCube = 0;

	rotateTeapot -= .75;
	if(rotateTeapot <= 0)
		rotateTeapot = 360;

	glutPostRedisplay();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(500, 500);
   glutCreateWindow(argv[0]);
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutIdleFunc(move);
   glutMainLoop();
   return 0;
}