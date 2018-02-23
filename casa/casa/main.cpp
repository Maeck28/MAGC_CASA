//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Moreno Marín Christian				******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(255.0f, 255.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview
	//
	
	glBegin(GL_TRIANGLES);
	glColor3f(255,0,0);

	glVertex3f(2, 0, -1.2);
	glVertex3f(4.7, 2, -1.2);
	glVertex3f(2.5, 2, -1.2);
	

	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(255, 0, 0);
	glVertex3f(7.5,0, -1.2);
	glVertex3f(6.8,2, -1.2);
	glVertex3f(4.7,2, -1.2);
	
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(255, 0, 0);

	glVertex3f(6.5,3.3, -1.2);
	glVertex3f(9.2,5.5, -1.2);
	glVertex3f(6, 5.5, -1.2);

	glEnd();
	
	glBegin(GL_TRIANGLES);

	glColor3f(255, 0, 0);
	glVertex3f(6,5.5, -1.2);
	glVertex3f(4.7, 8.5, -1.2);
	glVertex3f(3.5,5.5, -1.2);
	
	glEnd();

	glBegin(GL_TRIANGLES);

	glColor3f(255, 0, 0);
	glVertex3f(3.5, 5.5, -1.2);
	glVertex3f(0.5,5.5, -1.2);
	glVertex3f(3,3.3, -1.2);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(255, 0, 0);
	glVertex3f(2.5, 2, -1.2);
	glVertex3f(6.8, 2, -1.2);
	glVertex3f(6,5.5, -1.2);
	glVertex3f(3.5, 5.5, -1.2);

	glEnd();

	glFlush();

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-10,10,-10,10,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

