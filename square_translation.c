/*
 * minu.c
 *
 *  Created on: Apr 12, 2014
 *      Author: chintan
 */
#include <GL/glut.h>
#include <GL/glut.h>

float i=0,j=0,k=0,l=0,m=0,n=1;

void display()
{
	glClearColor(0.0,0.0,0.0,0.0);

	glClear(GL_COLOR_BUFFER_BIT);



	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);


	glMatrixMode(GL_MODELVIEW);
///////square 1////////////
	glPushMatrix();

	glTranslatef(i,i,0);
	glRotatef(m,0,0,1);
	glScalef(n,n,0);
	glBegin(GL_QUADS);

	glColor3f(1.0f,0.0f,0.0f);

	glVertex2f(0.7,0.7);

	 glVertex2f(0.9,0.7);

	 glVertex2f(0.9,0.9);

	glVertex2f(0.7,0.9);


	glEnd();


	glPopMatrix();

///////////////////square 2/////////////////////

	glPushMatrix();

		glTranslatef(j,i,0);
		glRotatef(m,0,0,1);
		glScalef(n,n,0);
		glBegin(GL_QUADS);

		glColor3f(0.0f,1.0f,0.0f);

		glVertex2f(-0.7,0.7);

		 glVertex2f(-0.9,0.7);

		 glVertex2f(-0.9,0.9);

		glVertex2f(-0.7,0.9);


		glEnd();


		glPopMatrix();


		/////////////square3///////////////////

		glPushMatrix();

				glTranslatef(k,k,0);
				glRotatef(m,0,0,1);
				glScalef(n,n,0);
				glBegin(GL_QUADS);

				glColor3f(0.0f,0.0f,1.0f);

				glVertex2f(-0.7,-0.7);

				 glVertex2f(-0.9,-0.7);

				 glVertex2f(-0.9,-0.9);

				glVertex2f(-0.7,-0.9);


				glEnd();


				glPopMatrix();

	//////////////////////////square4///////////////////////

				glPushMatrix();

						glTranslatef(l,j,0);
						glRotatef(m,0,0,1);
						glScalef(n,n,0);
						glBegin(GL_QUADS);

						glColor3f(1.0f,1.0f,0.0f);

						glVertex2f(0.7,-0.7);

						 glVertex2f(0.9,-0.7);

						 glVertex2f(0.9,-0.9);

						glVertex2f(0.7,-0.9);


						glEnd();


						glPopMatrix();


	glFlush();

	glutSwapBuffers();


}


void timer(int v)
{

	if(j<0.4)
	{
	i-=0.001,j+=0.001,k+=0.001,l-=0.001;
	n-=0.001;
	}
	else
	{
		m+=0.1;
		n-=0.0001;

	}


    glutPostRedisplay();

  glutTimerFunc(1,timer,v);



}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(display);
    glutTimerFunc(1,timer,0);
    //glutMouseFunc(mouse);
  // glutSpecialFunc(Special);

    glutMainLoop();
    return 0;
}
