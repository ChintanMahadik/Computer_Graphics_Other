
//quad spin
#include <GL/glut.h>
#include <GL/glut.h>


int i=1,j;

void display()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	 glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	 glColor3f(1,0,0.1);
	glRotatef(j,1,1,1);
	glScalef(i,i,0);

	glBegin(GL_POLYGON);
	glVertex2f(-0.5,0.5);
	glVertex2f(-0.5,-0.5);



	glVertex2f(0.5,-0.5);
	glVertex2f(0.5,0.5);


	glEnd();
	glFlush();

}

void timer(int v)
{

    glutPostRedisplay();

  glutTimerFunc(10,timer,v);



}

/*void mouse(int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {

   j+=1;
  } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {

	    j-=1;


  }
}*/

void Special(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP : j+=2; break;
		case GLUT_KEY_DOWN :j-=2; break;
		case GLUT_KEY_LEFT : i+=0.1; break;
	    case GLUT_KEY_RIGHT :i-=0.1; break;
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
   glutSpecialFunc(Special);

    glutMainLoop();
    return 0;
}

