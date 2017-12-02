


#include <GL/glut.h>
#include <GL/gl.h>
#include<stdio.h>

int i=0;
void display()
{

	 glClearColor(0.0,0.0, 0.0, 0.0);
	    glClear(GL_COLOR_BUFFER_BIT);
	    glRotatef(i,0.0,0.0,1.0);
	    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	 //   glTranslatef(0.01,0.0f,0.0f);

	    glColor3f(1,0,0);
	    glutWireTorus(0.05,0.8,40,7);

	    glColor3f(1,0,0);
	   	    glutWireTorus(0.05,0.6,30,9);

	   	 glColor3f(1,0,0);
	   		    glutWireTorus(0.05,0.4,20,11);

	   		 glColor3f(1,0,0);
	   			   		    glutWireTorus(0.04,0.2,10,13);

	   			   			   	 glColor3f(1,0,0);
	   			   			   		   		    glutWireTorus(0.04,0.08,5,15);



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
    glutTimerFunc(10,timer,0);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}




