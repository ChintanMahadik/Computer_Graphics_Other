/*
 * hypnotise.c
 *
 *  Created on: Apr 4, 2014
 *      Author: chintan
 */


#include <GL/glut.h>
#include <GL/glut.h>


int i=0;

void display()
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	        glClear(GL_COLOR_BUFFER_BIT);
	    	glColor3f(1.0f,0.0f,0.0f);
	    	glRotatef(i,1,1,1);
	    	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	    	glutWireTorus(0.04,0.8,40,20);

	    	glBegin(GL_POLYGON);

	    	glColor3f(1,1,1);

	    	glVertex2f(0,0);
	    	glVertex2f(0,0.4);
	    	glVertex2f(0,0.4);
	    	glVertex2f(0.2,0.7);

	    	glColor3f(1,1,1);

	    	glVertex2f(0,0);
	        glVertex2f(0,-0.4);
	        glVertex2f(0,-0.4);
	        glVertex2f(-0.2,-0.7);

	        glColor3f(1,1,1);


	        glVertex2f(0,0);
	    	glVertex2f(-0.4,0);
	    	glVertex2f(-0.4,0);
	    	glVertex2f(-0.7,0.2);

	    	glColor3f(1,1,1);

	    	glVertex2f(0,0);
	    	glVertex2f(0.4,0);
	    	glVertex2f(0.4,0);
	    	glVertex2f(0.7,-0.2);

//diagonal
	    	glColor3f(0,0,0);

	    	glVertex2f(0,0);
	    	glVertex2f(0.28,0.28);
	    	glVertex2f(0.28,0.28);
	    	glVertex2f(0.65,0.4);

	    	glColor3f(0,0,0);

	    	glVertex2f(0,0);
	    	glVertex2f(-0.28,-0.28);
	    	glVertex2f(-0.28,-0.28);
	    	glVertex2f(-0.65,-0.4);

	    	glColor3f(0,0,0);

	    	glVertex2f(0,0);
	    	glVertex2f(-0.28,0.28);
	    	glVertex2f(-0.28,0.28);
	    	glVertex2f(-0.4,0.65);

	    	glColor3f(0,0,0);

	    	glVertex2f(0,0);
	    	glVertex2f(0.28,-0.28);
	    	glVertex2f(0.28,-0.28);
	    	glVertex2f(0.4,-0.65);



	    	glEnd();




	    	glFlush();
}

void timer(int v)
{

    glutPostRedisplay();

  glutTimerFunc(10,timer,v);



}

void mouse(int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {

   i+=2;
  } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {

	    i-=2;


  }
}


int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(display);
   glutTimerFunc(1,timer,0);//timer function to repeat itself at every step//
    glutMouseFunc(mouse);
   // glutSpecialFunc(special);

    glutMainLoop();
    return 0;
}
