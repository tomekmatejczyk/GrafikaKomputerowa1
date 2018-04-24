// opengl_stos_modelowania.cpp : Defines the entry point for the console application.
//dwunastoscian
//dwudziestoscian

#include "stdafx.h"


/*
(c) Janusz Ganczarski
http://www.januszg.hg.pl
JanuszG@enter.net.pl
*/

#include <GL/glut.h>
#include <stdlib.h>

// stałe do obsługi menu podręcznego

enum
{
	// aspekt obrazu - całe okno
	FULL_WINDOW,
	// aspekt obrazu 1:1
	ASPECT_1_1,
	// wyjście
	EXIT
};

// aspekt obrazu

int aspect = FULL_WINDOW;

// rozmiary bryły obcinania

const GLdouble left = -10.0;
const GLdouble right = 10.0;
const GLdouble bottom = -10.0;
const GLdouble top = 10.0;
const GLdouble near_ = 50.0;
const GLdouble far_ = 70.0;

// współczynnik skalowania

GLfloat scale = 1.0;

// kąty obrotu

GLfloat rotatex = 0.0;
GLfloat rotatey = 0.0;

// przesunięcie

GLfloat translatex = 0.0;
GLfloat translatey = 0.0;

// wskaŸnik naciśnięcia lewego przycisku myszki

int button_state = GLUT_UP;

// poło¿enie kursora myszki

int button_x, button_y;

void Icosahedron()
{
	glutWireIcosahedron();
}

// funkcja rysująca blok 3x3

void Cube3x3()
{
	glutWireCube(1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(0.0, -1.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(0.0, 1.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(0.0, 1.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(1.0);
}

// funkcja rysująca blok 2x2

void Cube2x2()
{
	glutWireCube(1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(0.0, -1.0, 0.0);
	glutWireCube(1.0);
	glTranslatef(-1.0, 0.0, 0.0);
	glutWireCube(1.0);
}

// funkcja rysująca piramidę z sześcianów

void Pyramid()
{
	//poziom 1
	for (int i = -11; i <= 11; i+=2)
	{
		for (int j = -11; j <= 11; j+=2)
		{
			glPushMatrix();

			glTranslatef(i, j, 0.0);

			Icosahedron();

			glPopMatrix();

		}
		
	}
	

	//poziom 2


	/*glPushMatrix();

	glTranslatef(0.0, 0.0, 2.0);*/


	for (int i = -10; i <= 10; i += 2)
	{
		for (int j = -10; j <= 10; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 2.0);

			Icosahedron();

			glPopMatrix();

		}

	}
	
	//poziom 3

	//glPushMatrix();

	//glTranslatef(0.0, 0.0, 4.0);


	for (int i = -9; i <= 9; i += 2)
	{
		for (int j = -9; j <= 9; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 4.0);

			Icosahedron();

			glPopMatrix();

		}

	}
	//poziom 4

	//glPushMatrix();

	//glTranslatef(0.0, 0.0, 6.0);


	for (int i = -8; i <= 8; i += 2)
	{
		for (int j = -8; j <= 8; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 6.0);

			Icosahedron();

			glPopMatrix();

		}

	}
	//poziom 5
/*
	glPushMatrix();

	glTranslatef(0.0, 0.0, 8.0);*/


	for (int i = -7; i <= 7; i += 2)
	{
		for (int j = -7; j <= 7; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 8.0);

			Icosahedron();

			glPopMatrix();

		}
	}

	//poziom 6
	for (int i = -6; i <= 6; i += 2)
	{
		for (int j = -6; j <= 6; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 10.0);

			Icosahedron();

			glPopMatrix();

		}
	}

	//poziom 7
	for (int i = -5; i <= 5; i += 2)
	{
		for (int j = -5; j <= 5; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 12.0);

			Icosahedron();

			glPopMatrix();

		}
	}

	//poziom 8
	for (int i = -4; i <= 4; i += 2)
	{
		for (int j = -4; j <= 4; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 14.0);

			Icosahedron();

			glPopMatrix();

		}
	}
	//poziom 9
	for (int i = -3; i <= 3; i += 2)
	{
		for (int j = -3; j <= 3; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 16.0);

			Icosahedron();

			glPopMatrix();

		}
	}
	//poziom 10
	for (int i = -2; i <= 2; i += 2)
	{
		for (int j = -2; j <= 2; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 18.0);

			Icosahedron();

			glPopMatrix();

		}
	}
	//poziom 11
	for (int i = -1; i <= 1; i += 2)
	{
		for (int j = -1; j <= 1; j += 2)
		{
			glPushMatrix();

			glTranslatef(i, j, 20.0);

			Icosahedron();

			glPopMatrix();

		}
	}

	// szczyt

	glPushMatrix();

	glTranslatef(0.0, 0.0, 22.0);

	Icosahedron();

	glPopMatrix();




	/*
	// podstawa 6x6
	//sciana a
	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(5.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(11.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	
	//sciana c
	glPushMatrix();
	glTranslatef(-1.0, -3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-11.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();




	glPushMatrix();
	glTranslatef(1.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(5.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(7.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(9.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(11.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();

	//sciana c
	glPushMatrix();
	glTranslatef(-1.0, -3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-5.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-7.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-9.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-11.0, 3.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();



	//sciana b
	glPushMatrix();
	glTranslatef(1.0, -1.0, 0.0);
	Icosahedron();
	glPopMatrix();


	//sciana d
	glPushMatrix();
	glTranslatef(-1.0, 1.0, 0.0);
	Icosahedron();
	glPopMatrix();
	glPushMatrix();
	
	*/

/*
	// drugi poziom 5x5
	glPushMatrix();
	glTranslatef(0.0, 0.0, 1.0);
	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	Cube3x3();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.0, -1.0, 0.0);
	Cube2x2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-2.0, 2.0, 0.0);
	Cube2x2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.0, -1.0, 0.0);
	Cube3x3();
	glPopMatrix();
	glPopMatrix();

	// trzeci poziom 4x4
	glPushMatrix();
	glTranslatef(0.0, 0.0, 2.0);
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0.0);
	Cube2x2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.5, 1.5, 0.0);
	Cube2x2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5, 1.5, 0.0);
	Cube2x2();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.5, -0.5, 0.0);
	Cube2x2();
	glPopMatrix();
	glPopMatrix();

	// czwarty poziom 3x3
	glPushMatrix();
	glTranslatef(0.0, 0.0, 3.0);
	Cube3x3();
	glPopMatrix();

	// piąty poziom 2x2
	glPushMatrix();
	glTranslatef(0.0, 0.0, 4.0);
	glTranslatef(-0.5, 0.5, 0.0);
	Cube2x2();
	glPopMatrix();

	// szósty poziom 1x1
	glPushMatrix();
	glTranslatef(0.0, 0.0, 5.0);
	glutWireCube(1.0);
	glPopMatrix();

	*/
}

// funkcja generująca scenę 3D

void Display()
{
	// kolor tła - zawartość bufora koloru
	glClearColor(1.0, 1.0, 1.0, 1.0);

	// czyszczenie bufora koloru
	glClear(GL_COLOR_BUFFER_BIT);

	// wybór macierzy modelowania
	glMatrixMode(GL_MODELVIEW);

	// macierz modelowania = macierz jednostkowa
	glLoadIdentity();

	// przesunięcie układu współrzędnych obiektu do środka bryły odcinania
	glTranslatef(0, 0, -(near_ + far_) / 2);

	// przesunięcie obiektu - ruch myszką
	glTranslatef(translatex, translatey, 0.0);

	// skalowanie obiektu - klawisze "+" i "-"
	glScalef(scale, scale, scale);

	// obroty obiektu - klawisze kursora
	glRotatef(rotatex, 1.0, 0, 0);
	glRotatef(rotatey, 0, 1.0, 0);

	// kolor krawędzi obiektu
	glColor3f(0.0, 0.0, 0.0);

	// rysowanie piramidy
	Pyramid();

	// skierowanie poleceń do wykonania
	glFlush();

	// zamiana buforów koloru
	glutSwapBuffers();
}

// zmiana wielkości okna

void Reshape(int width, int height)
{
	// obszar renderingu - całe okno
	glViewport(0, 0, width, height);

	// wybór macierzy rzutowania
	glMatrixMode(GL_PROJECTION);

	// macierz rzutowania = macierz jednostkowa
	glLoadIdentity();

	// parametry bryły obcinania
	if (aspect == ASPECT_1_1)
	{
		// wysokość okna większa od wysokości okna
		if (width < height && width > 0)
			glFrustum(left, right, bottom*height / width, top*height / width, near_, far_);
		else

			// szerokość okna większa lub równa wysokości okna
			if (width >= height && height > 0)
				glFrustum(left*width / height, right*width / height, bottom, top, near_, far_);
	}
	else
		glFrustum(left, right, bottom, top, near_, far_);

	// generowanie sceny 3D
	Display();
}

// obsługa klawiatury

void Keyboard(unsigned char key, int x, int y)
{
	// klawisz +
	if (key == '+')
		scale += 0.1;
	else

		// klawisz -
		if (key == '-' && scale > 0.1)
			scale -= 0.1;

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa klawiszy funkcyjnych i klawiszy kursora

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
		// kursor w lewo
	case GLUT_KEY_LEFT:
		rotatey -= 1;
		break;

		// kursor w górę
	case GLUT_KEY_UP:
		rotatex -= 1;
		break;

		// kursor w prawo
	case GLUT_KEY_RIGHT:
		rotatey += 1;
		break;

		// kursor w dół
	case GLUT_KEY_DOWN:
		rotatex += 1;
		break;
	}

	// odrysowanie okna
	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obsługa przycisków myszki

void MouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamiętanie stanu lewego przycisku myszki
		button_state = state;

		// zapamiętanie poło¿enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

// obsługa ruchu kursora myszki

void MouseMotion(int x, int y)
{
	if (button_state == GLUT_DOWN)
	{
		translatex += 1.1 *(right - left) / glutGet(GLUT_WINDOW_WIDTH) * (x - button_x);
		button_x = x;
		translatey += 1.1 *(top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) * (button_y - y);
		button_y = y;
		glutPostRedisplay();
	}
}

// obsługa menu podręcznego

void Menu(int value)
{
	switch (value)
	{
		// obszar renderingu - całe okno
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// obszar renderingu - aspekt 1:1
	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

		// wyjście
	case EXIT:
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	// inicjalizacja biblioteki GLUT
	glutInit(&argc, argv);

	// inicjalizacja bufora ramki
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// rozmiary głównego okna programu
	glutInitWindowSize(400, 400);

	// utworzenie głównego okna programu
	glutCreateWindow("Stos modelowania");

	// dołączenie funkcji generującej scenę 3D
	glutDisplayFunc(Display);

	// dołączenie funkcji wywoływanej przy zmianie rozmiaru okna
	glutReshapeFunc(Reshape);

	// dołączenie funkcji obsługi klawiatury
	glutKeyboardFunc(Keyboard);

	// dołączenie funkcji obsługi klawiszy funkcyjnych i klawiszy kursora
	glutSpecialFunc(SpecialKeys);

	// obsługa przycisków myszki
	glutMouseFunc(MouseButton);

	// obsługa ruchu kursora myszki
	glutMotionFunc(MouseMotion);

	// utworzenie podmenu - aspekt obrazu
	int MenuAspect = glutCreateMenu(Menu);
#ifdef WIN32

	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
#else

	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);

	// menu główne
	glutCreateMenu(Menu);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);
#ifdef WIN32

	glutAddMenuEntry("Wyjście", EXIT);
#else

	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	// określenie przycisku myszki obsługującego menu podręczne
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	// wprowadzenie programu do obsługi pętli komunikatów
	glutMainLoop();
	return 0;
}

