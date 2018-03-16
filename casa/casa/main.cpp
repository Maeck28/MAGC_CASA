//      Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Guevara Chávez Marco Antonio//
//*************	Version: Visual Studio 2015						******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h

// LOS OBJETOS SE MUEVEN CON MAYUSCULAS Y MINUSCULAS
//EL HOMBRO SE MUEVE CON LA LETRA H 
// CODO CON LA LETRA C
//MUÑECA CON LA LETRA M
// DEDO PULGAR CON O
// DEDO INDICE CON I
// DEDO MEDIO CON U
// DEDO ANULAR Y
// DEDO MEÑIQUE CON T

#include "Main.h"
float angHombro = 0.0f;
float angCodo = 0.0f;
float angMuni = 0.0f;
float angDedP = 0.0f;
float angDedI = 0.0f;
float angMed = 0.0;
float angAn = 0.0;
float angMe = 0.0;

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
float roty = 0.0;


void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
														//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
														//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
							//glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
							//glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
							//glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
						  //glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
						  //glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
						  //glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
														//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(roty, 0, 1, 0);

	//Poner Código Aquí.

	//cabeza
	glPushMatrix();
	glScalef(4, 4, 4);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();

	//ojos
	glPushMatrix();
	glTranslatef(-0.5, 0 , 2);
	glScalef(.52, .52, .1);
	glColor3f(0, .1, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 2);
	glScalef(.52, .52, .1);
	glColor3f(0, .1, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0, -3, 0);
	
	//cuello
	glPushMatrix();
	glScalef(3, 2, 3);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	glTranslatef(0, -6, 0);
	//torso
	glPushMatrix();
	glScalef(10, 10, 3);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//pierna izquierda
	//muslo
	glTranslatef(2.5, -7.5, 0);

	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glTranslatef(0, -3, 0);
	//rodilla
	glPushMatrix();
	glScalef(2, 1, 3);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0, -3, 0);

	//espinilla
	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(1, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glTranslatef(0, -2.75, 0);

	//tobillo
	glPushMatrix();
	glScalef(2, 0.5, 3);
	glColor3f(1, 0, 0.5);
	prisma();
	glPopMatrix();

	glTranslatef(0, -1.25, 0);
	//pie
	glPushMatrix();
	glScalef(2, 2, 3);
	glColor3f(0.5, 0, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glPopMatrix();

	glTranslatef(3, 21.5, 0);

	//brazo izquierdo
	//Hombro
	glPushMatrix();
	glRotatef(angHombro, 0, 0, 1);
	glPushMatrix();
	glScalef(1, 2, 2);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();

	//Bicep
	glPushMatrix();
	glTranslatef(2, 0, 0);
	glScalef(3, 2, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//Codo
	glRotatef(angCodo, 0, 1, 0);
	glPushMatrix();
	glTranslatef(3.75, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Antebrazo
	glPushMatrix();
	glTranslatef(6, 0, 0);
	glScalef(4, 2, 2);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Muñeca
	glRotatef(angMuni, 0, 1, 0);
	glPushMatrix();
	glTranslatef(8.25, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();

	//Mano
	glPushMatrix();
	glTranslatef(9.5, 0, 0);
	glScalef(2, 2, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

    //dedo pulgar
	glPushMatrix();
	glRotatef(angDedP, 1, 0, 0);
	glTranslatef(9.75, 1.25, 0);
	glScalef(.3,.5, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angDedP, 1, 0, 0);
	glTranslatef(9.75, 1.75, 0);
	glScalef(.3, .5, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();
	
	//dedo indice
	glPushMatrix();
	glRotatef(angDedI, 0, 1, 0);
	glTranslatef(10.75, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angDedI, 0, 1, 0);
	glTranslatef(11.25, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angDedI, 0, 1, 0);
	glTranslatef(11.75, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//dedo medio
	
	glPushMatrix();
	glRotatef(angMed, 0, 1, 0);
	glTranslatef(10.75, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angMed, 0, 1, 0);
	glTranslatef(11.25, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angMed, 0, 1, 0);
	glTranslatef(11.75, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//dedo anular
	glPushMatrix();
	glRotatef(angAn, 0, 1, 0);
	glTranslatef(10.75, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angAn, 0, 1, 0);
	glTranslatef(11.25, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angAn, 0, 1, 0);
	glTranslatef(11.75, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();
	//meñique
	glPushMatrix();
	glRotatef(angMe, 0, 1, 0);
	glTranslatef(10.75, -.75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angMe, 0, 1, 0);
	glTranslatef(11.25, -.75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPopMatrix();


	//Brazo derecha
	//Hombro
	glPushMatrix();
	glTranslatef(-11, 0, 0);
	glRotatef(-angHombro, 0, 0, 1);
	glPushMatrix();	
	glScalef(1, 2, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	//Bicep
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	glScalef(3, 2, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//Codo
	glRotatef(-angCodo, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-3.75, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(1, 0, 0);
	prisma();
	glPopMatrix();

	//Antebrazo
	glPushMatrix();
	glTranslatef(-6, 0, 0);
	glScalef(4, 2, 2);
	glColor3f(0, 1, 0);
	prisma();
	glPopMatrix();

	//Muñeca
	glRotatef(-angMuni, 0, 1, 0);
	glPushMatrix();
	glTranslatef(-8.25, 0, 0);
	glScalef(0.5, 2, 2);
	glColor3f(1, 1, 1);
	prisma();
	glPopMatrix();

	//Mano
	glPushMatrix();
	glTranslatef(-9.5, 0, 0);
	glScalef(2, 2, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//dedo pulgar
	glPushMatrix();
	glRotatef(-angDedP, 1, 0, 0);
	glTranslatef(-9.75, 1.25, 0);
	glScalef(.3, .5, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angDedP, 1, 0, 0);
	glTranslatef(-9.75, 1.75, 0);
	glScalef(.3, .5, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	//dedo indice
	glPushMatrix();
	glRotatef(-angDedI, 0, 1, 0);
	glTranslatef(-10.75, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angDedI, 0, 1, 0);
	glTranslatef(-11.25, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angDedI, 0, 1, 0);
	glTranslatef(-11.75, .75, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//dedo medio

	glPushMatrix();
	glRotatef(-angMed, 0, 1, 0);
	glTranslatef(-10.75, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angMed, 0, 1, 0);
	glTranslatef(-11.25, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angMed, 0, 1, 0);
	glTranslatef(-11.75, .25, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();

	//dedo anular
	glPushMatrix();
	glRotatef(-angAn, 0, 1, 0);
	glTranslatef(-10.75, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angAn, 0, 1, 0);
	glTranslatef(-11.25, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angAn, 0, 1, 0);
	glTranslatef(-11.75, -.25, 0);
	glScalef(.5, .3, 2);
	glColor3f(0, 0, 1);
	prisma();
	glPopMatrix();
	//meñique
	glPushMatrix();
	glRotatef(-angMe, 0, 1, 0);
	glTranslatef(-10.75, -.75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-angMe, 0, 1, 0);
	glTranslatef(-11.25, -.75, 0);
	glScalef(.5, .3, 2);
	glColor3f(1, 1, 0);
	prisma();
	glPopMatrix();
	
	glPopMatrix();


	//pie derecho
	//muslo

	glTranslatef(-7.5, -11.5, 0);
	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(0.6, 0, 0.5);
	prisma();
	glPopMatrix();
	glTranslatef(0, -3, 0);
	//rodilla
	glPushMatrix();
	glScalef(2, 1, 3);
	glColor3f(1, 0, 1);
	prisma();
	glPopMatrix();

	glTranslatef(0, -3, 0);

	//espinilla
	glPushMatrix();
	glScalef(2, 5, 3);
	glColor3f(1, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glTranslatef(0, -2.75, 0);

	//tobillo
	glPushMatrix();
	glScalef(2, 0.5, 3);
	glColor3f(1, 0, 0.5);
	prisma();
	glPopMatrix();

	glTranslatef(0, -1.25, 0);
	//pie
	glPushMatrix();
	glScalef(2, 2, 3);
	glColor3f(0.5, 0, 0.5);
	prisma();
	glPopMatrix();





	glutSwapBuffers();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.3f;
		break;
	case 's':
	case 'S':
		transZ -= 0.3f;
		break;
	case 'a':
	case 'A':

		break;
	case 'd':
	case 'D':
			break;
	case 'h':
		if (angHombro <= 80)
			angHombro += 1;
		break;
	case 'H':
		if (angHombro >= -80)
			angHombro -= 1;
		break;
	case 'c':
		if (angCodo <= 0)
			angCodo += 1;
		break;
	case 'C':
		if (angCodo >= -120)
			angCodo -= 1;
		break;
	case 'm':
		if (angMuni <= 0)
			angMuni += 1;
		break;
	case 'M':
		if (angMuni >= -70)
			angMuni -= 1;
		break;
	case 'o':
		if (angDedP <= 100)
			angDedP += 1;
		break;
	case 'O':
		if (angDedP >= 0)
			angDedP -= 1;
		break;
	case 'i':
		if (angDedI <= 0)
			angDedI += 1;
		break;
	case 'I':
		if (angDedI >= -100)
			angDedI -= 1;
		break;
	case 'u':
		if (angMed <= 0)
			angMed += 1;
		break;
	case 'U':
		if (angMed >= -100)
			angMed -= 1;
		break;
	case 'y':
		if (angAn <= 0)
			angAn += 1;
		break;
	case 'Y':
		if (angAn >= -100)
			angAn -= 1;
		break;
	case 't':
		if (angMe <= 0)
			angMe += 1;
		break;
	case 'T':
		if (angMe >= -100)
			angMe -= 1;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		roty -= 0.5;
		break;
	case GLUT_KEY_RIGHT:
		roty += 0.5;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
						   //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Ejercicio Casa"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}