

//direction control spindle

#include <GL/freeglut.h>
#include <GL/gl.h>
#include<stdio.h>





float i=2;

void display()
{

    glClearColor(0.0,0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
   // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();


    glRotatef(i,0.0,0.0,1.0);


glColor3f(1,1,1);
   glutWireTorus(0.05,0.8,30,20);



//horizontal and vertical edges//
   //upper edge.//
      glBegin(GL_POLYGON);
   	    glColor3f(1,0,0);
   	    glVertex2f(-0.05,0.0);
   	    glVertex2f(0.05,0.0);
   	    glVertex2f(0.0,0.8);

   	    glEnd();

   	    //lowe edge.//
   	    glBegin(GL_POLYGON);
   	    glColor3f(0,1,0);
   	    glVertex2f(0.05,0.0);
   	    glVertex2f(-0.05,0.0);
   	    glVertex2f(0.0,-0.8);

       glEnd();

       //left edge.//
       glBegin(GL_POLYGON);
        glColor3f(0,0,1);
         glVertex2f(0.0,0.05);
         glVertex2f(0.0,-0.05);
         glVertex2f(-0.8,0.0);

           glEnd();

           //right edge.//
                glBegin(GL_POLYGON);
                     glColor3f(1,0,1);
                       glVertex2f(0.0,0.05);
                        glVertex2f(0.0,-0.05);
                         glVertex2f(0.8,0.0);

                                      glEnd();


                  /////diagonal edges......!//
                                      //+,+//
                                      glBegin(GL_POLYGON);
                                       glColor3f(1,1,0);
                                      glVertex2f(-0.04,0.04);
                                      glVertex2f(0.04,-0.04);
                                       glVertex2f(0.7,0.7);

                                       glEnd();
                                       //--//
                                       glBegin(GL_POLYGON);
                                       glColor3f(1,1,0);
                                      glVertex2f(-0.04,0.04);
                                      glVertex2f(0.04,-0.04);
                                       glVertex2f(-0.7,-0.7);

                                       glEnd();

                                       //-+//

                                       glBegin(GL_POLYGON);
                                        glColor3f(1,1,0);
                                         glVertex2f(-0.04,-0.04);
                                        glVertex2f(0.04,0.04);
                                           glVertex2f(-0.7,0.7);

                                             glEnd();

                                        //+-//
                                           glBegin(GL_POLYGON);
                                           glColor3f(1,1,0);
                                           glVertex2f(-0.04,-0.04);
                                           glVertex2f(0.04,0.04);
                                           glVertex2f(0.7,-0.7);


                                            glEnd();


                                            glPopMatrix();


                                           glFlush();


                                           glutSwapBuffers();


}

void timer(int v)
{

	i+=0.2;
    glutPostRedisplay();

  glutTimerFunc(10,timer,v);



}

void mouse(int button, int state, int x, int y)
{

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {


  } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
  {

	    i-=2;


  }
}





/* Main method - main entry point of application
the freeglut library does the window creation work for us,
regardless of the platform. */
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



