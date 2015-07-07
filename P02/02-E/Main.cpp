#include <Windows.h>
#include <gl/glut.h>
#include <fstream>
using namespace std;
//float cx = 300.0, cy = 300.0;
//float H = 600.0, W = 600.0, aspect = 0.7;
//
//void init(void)
//{
//	glClearColor(1, 1, 1.0, 0.0);
//	glColor3f(1.0, 0.0, 0.0);
//	glLineWidth(4.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 600, 0.0, 600);
//}
//void SetWindow(float left, float right, float bottom, float top)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(left, right, bottom, top);
//}
//void drawTxtFile()
//{
//	ifstream inStream;
//	inStream.open("Knight.txt");
//	if(inStream.fail())
//		return;
//	glClear(GL_COLOR_BUFFER_BIT);
//	GLint numpolys, numLines, x, y;
//	inStream >> numpolys;
//	for(int j= 0; j < numpolys; j++)
//	{
//		inStream >> numLines;
//		glBegin(GL_LINE_STRIP);
//		for (int i = 0; i < numLines; i++)
//		{
//			inStream >> x >> y;
//			glVertex2i(x, y);
//		}
//		glEnd();
//	}
//
//	glFlush();
//	inStream.close();
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	drawTxtFile();
//}
//void keyboard(unsigned char key, int mouseX, int mouseY)
//{
//	switch(key)
//	{
//	case 'Z':
//		W *= 1.1;
//		H = W * aspect;
//
//		SetWindow(cx - W, cx + W, cy - H, cy + H);
//		display();
//		break;
//	case 'z':
//		W *= .9;
//		H = W * aspect;
//
//		SetWindow(cx - W, cx + W, cy - H, cy + H);
//		display();
//		break;
//	case 'q':
//		exit(0);
//	default:
//		break;
//	}
//
//}
//
//
//
//void mouse(int button, int state, int x, int y)
//{
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//		W *= .9;
//	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//		W *= 1.1;
//	H = W * aspect;
//
//	SetWindow(cx - W, cx + W, cy - H, cy + H);
//	display();
//}
//
//
//
//
//void main (int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(660,240);
//	glutInitWindowSize(600,600);
//	glutCreateWindow("Knight");
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouse);
//	init();
//	glutDisplayFunc(display);
//
//	glutMainLoop();
//}

// #include <GL/gl.h>
//#include <GL/glut.h>
//#include <stdlib.h>
//#include <math.h>
//
////angle of rotation
//float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;
//
//float lastx, lasty;
//
////positions of the cubes
//float positionz[10];
//float positionx[10];
//
//void cubepositions (void) { //set the positions of the cubes
//
//    for (int i=0;i<10;i++)
//    {
//    positionz[i] = rand()%5 + 5;
//    positionx[i] = rand()%5 + 5;
//    }
//}
//
////draw the cube
//void cube (void) {
//    for (int i=0;i<10;i++)
//    {
//    glPushMatrix();
//    glTranslated(-positionx[i + 1] * 10, 0, -positionz[i + 1] *10); //translate the cube
//    glutSolidCube(2); //draw the cube
//    glPopMatrix();
//    }
//}
//
//void init (void) {
//cubepositions();
//}
//
//void enable (void) {
//    glEnable (GL_DEPTH_TEST); //enable the depth testing
//    glEnable (GL_LIGHTING); //enable the lighting
//    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
//    glShadeModel (GL_SMOOTH); //set the shader to smooth shader
//
//}
//
//void camera (void) {
//    glRotatef(xrot,1.0,0.0,0.0);  //rotate our camera on teh x-axis (left and right)
//    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
//    glTranslated(-xpos,-ypos,-zpos); //translate the screen to the position of our camera
//}
//
//void display (void) {
//    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
//    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
//    glLoadIdentity();  
//    camera();
//    enable();
//    cube(); //call the cube drawing function
//    glutSwapBuffers(); //swap the buffers
//    angle++; //increase the angle
//}
//
//void reshape (int w, int h) {
//    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
//    glMatrixMode (GL_PROJECTION); //set the matrix to projection
//
//    glLoadIdentity ();
//    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 1000.0); //set the perspective (angle of sight, width, height, , depth)
//    glMatrixMode (GL_MODELVIEW); //set the matrix back to model
//
//}
//
//void keyboard (unsigned char key, int x, int y) {
//    if (key=='q')
//    {
//    xrot += 1;
//    if (xrot >360) xrot -= 360;
//    }
//
//    if (key=='z')
//    {
//    xrot -= 1;
//    if (xrot < -360) xrot += 360;
//    }
//
//    if (key=='w')
//    {
//    float xrotrad, yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xrotrad = (xrot / 180 * 3.141592654f);
//    xpos += float(sin(yrotrad)) ;
//    zpos -= float(cos(yrotrad)) ;
//    ypos -= float(sin(xrotrad)) ;
//    }
//
//    if (key=='s')
//    {
//    float xrotrad, yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xrotrad = (xrot / 180 * 3.141592654f);
//    xpos -= float(sin(yrotrad));
//    zpos += float(cos(yrotrad)) ;
//    ypos += float(sin(xrotrad));
//    }
//
//    if (key=='d')
//    {
//    float yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xpos += float(cos(yrotrad)) * 0.2;
//    zpos += float(sin(yrotrad)) * 0.2;
//    }
//
//    if (key=='a')
//    {
//    float yrotrad;
//    yrotrad = (yrot / 180 * 3.141592654f);
//    xpos -= float(cos(yrotrad)) * 0.2;
//    zpos -= float(sin(yrotrad)) * 0.2;
//    }
//
//    if (key==27)
//    {
//    exit(0);
//    }
//}
//
//void mouseMovement(int x, int y) {
//    int diffx=x-lastx; //check the difference between the current x and the last x position
//    int diffy=y-lasty; //check the difference between the current y and the last y position
//    lastx=x; //set lastx to the current x position
//    lasty=y; //set lasty to the current y position
//    xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
//    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
//}
//
//int main (int argc, char **argv) {
//    glutInit (&argc, argv);
//    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
//    glutInitWindowSize (500, 500);
//    glutInitWindowPosition (100, 100);
//    glutCreateWindow ("A basic OpenGL Window");
//    init ();
//    glutDisplayFunc (display);
//    glutIdleFunc (display);
//    glutReshapeFunc (reshape);
//
//    glutPassiveMotionFunc(mouseMovement); //check for mouse movement
//
//    glutKeyboardFunc (keyboard);
//    glutMainLoop ();
//    return 0;
//}

#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

//angle of rotation
float xpos = 0, ypos = 0, zpos = 0, xrot = 0, yrot = 0, angle=0.0;

float cRadius = 10.0f; // our radius distance from our character

float lastx, lasty;

//positions of the cubes
float positionz[10];
float positionx[10];

void cubepositions (void) { //set the positions of the cubes

    for (int i=0;i<10;i++)
    {
    positionz[i] = rand()%5 + 1;
    positionx[i] = rand()%5 + 1;
    }
}

//draw the cube
void cube (void) {
    for (int i=0;i<10 - 1;i++)
    {
    glPushMatrix();
    glTranslated(-positionx[i + 1] * 10, 0, -positionz[i + 1] *10); //translate the cube
    glutSolidCube(2); //draw the cube
    glPopMatrix();
    }
}

void init (void) {
    cubepositions();
}

void enable (void) {
    glEnable (GL_DEPTH_TEST); //enable the depth testing
    glEnable (GL_LIGHTING); //enable the lighting
    glEnable (GL_LIGHT0); //enable LIGHT0, our Diffuse Light
    glEnable (GL_COLOR_MATERIAL);
    glShadeModel (GL_SMOOTH); //set the shader to smooth shader

}

void display (void) {
    glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//clear the color buffer and the depth buffer
    enable();
    
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -cRadius);
    glRotatef(xrot,1.0,0.0,0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(2); //Our character to follow
    
    glRotatef(yrot,0.0,1.0,0.0);  //rotate our camera on the y-axis (up and down)
    glTranslated(-xpos,0.0f,-zpos); //translate the screen to the position of our camera
    glColor3f(1.0f, 1.0f, 1.0f);
    cube(); //call the cube drawing function

    glutSwapBuffers(); //swap the buffers
    angle++; //increase the angle
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); //set the viewport to the current window specifications
    glMatrixMode (GL_PROJECTION); //set the matrix to projection

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 100.0); //set the perspective (angle of sight, width, height, , depth)
    glMatrixMode (GL_MODELVIEW); //set the matrix back to model

}

void keyboard (unsigned char key, int x, int y) {
    if (key=='q')
    {
    xrot += 1;
    if (xrot >360) xrot -= 360;
    }

    if (key=='z')
    {
    xrot -= 1;
    if (xrot < -360) xrot += 360;
    }

    if (key=='w')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f);
    xpos += float(sin(yrotrad));
    zpos -= float(cos(yrotrad));
    ypos -= float(sin(xrotrad));
    }

    if (key=='s')
    {
    float xrotrad, yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xrotrad = (xrot / 180 * 3.141592654f);
    xpos -= float(sin(yrotrad));
    zpos += float(cos(yrotrad));
    ypos += float(sin(xrotrad));
    }

    if (key=='d')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos += float(cos(yrotrad)) * 0.2;
    zpos += float(sin(yrotrad)) * 0.2;
    }

    if (key=='a')
    {
    float yrotrad;
    yrotrad = (yrot / 180 * 3.141592654f);
    xpos -= float(cos(yrotrad)) * 0.2;
    zpos -= float(sin(yrotrad)) * 0.2;
    }

    if (key==27)
    {
    exit(0);
    }
}

void mouseMovement(int x, int y) {
    int diffx=x-lastx; //check the difference between the current x and the last x position
    int diffy=y-lasty; //check the difference between the current y and the last y position
    lastx=x; //set lastx to the current x position
    lasty=y; //set lasty to the current y position
    xrot += (float) diffy; //set the xrot to xrot with the addition of the difference in the y position
    yrot += (float) diffx;    //set the xrot to yrot with the addition of the difference in the x position
}

int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("A basic OpenGL Window");
    init ();
    glutDisplayFunc (display);
    glutIdleFunc (display);
    glutReshapeFunc (reshape);

    glutPassiveMotionFunc(mouseMovement); //check for mouse movement

    glutKeyboardFunc (keyboard);
    glutMainLoop ();
    return 0;
}