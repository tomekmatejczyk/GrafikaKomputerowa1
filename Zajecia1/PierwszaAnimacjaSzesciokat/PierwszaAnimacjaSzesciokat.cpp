// PierwszaAnimacjaSzesciokat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat x1 = 150.0f;
GLfloat y1 = 100.0f;
GLsizei asize = 16;
GLsizei hsize = 12;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;

double PI = 3.14;
double radiany_stopnie(double rad)
{
	return rad * 180 / PI; 
}


void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.8f, 0.8f, 0.8f);

	glBegin(GL_POLYGON);

	//1
	glVertex2f(x1, y1);
	//2
	glVertex2f(x1 + (2.0f * asize), y1);
	//3
	glVertex2f(x1 + (4.0f * asize) , y1 + hsize);
	//4
	glVertex2f(x1 + (5.0f * asize), y1 + (3.0f * hsize));
	//5
	glVertex2f(x1 + (5.0f * asize), y1 + (5.0f * hsize));
	//6
	glVertex2f(x1 + (4.0f * asize), y1 + (7.0f * hsize));
	//7
	glVertex2f(x1 + (2.0f * asize), y1 + (8.0f * hsize));
	//8
	glVertex2f(x1 , y1 + (8.0f * hsize));
	//9
	glVertex2f(x1 - (2.0f * asize), y1 + (7.0f * hsize));
	//10
	glVertex2f(x1 - (3.0f * asize), y1 + (5.0f * hsize));
	//11
	glVertex2f(x1 - (3.0f * asize), y1 + (3.0f * hsize));
	//12
	glVertex2f(x1 - (2.0f * asize), y1 + (1.0f * hsize));


	glEnd();
	glutSwapBuffers();
}

void TimerFunction(int value) {
	if ((x1 + (asize * 5.0f) ) > windowWidth || (x1 - (asize * 3.0f)) < 0)
		xstep = -xstep;

	if (y1 + (8.0f * hsize) > windowHeight || y1 < 0)
		ystep = -ystep;

	x1 += xstep;
	y1 += ystep;


	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}


void SetupRC(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		windowHeight = 250.0f*h / w;
		windowWidth = 250.0f;
	}
	else
	{
		windowWidth = 250.0f*w / h;
		windowHeight = 250.0f;
	}

	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("szesciokat");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
	return 0;
}

