#include<stdio.h>
#include<GL/glut.h>

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( 0 , 100 , 0 , 100 );

}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
    glBegin(GL_POLYGON);

            glColor3f( 1.0 , 0.0 , 0.0 );

            glVertex2i( 10 , 30 );
            glVertex2i( 40 , 30 );
            glVertex2i( 35 , 20 );
            glVertex2i( 15 , 20 );

    glEnd();

    glutSwapBuffers();

}

void reshape( int w , int h ){

    glViewport( 0 , 0 , w , h  );

}

int main( int argc, char **argv ){

    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 650 , 650 );
    glutInitWindowPosition( 10 , 10 );
    glutCreateWindow( "My Ship" );

    init();

    //callback functions
    glutDisplayFunc( display );
    glutReshapeFunc(reshape);

    glutMainLoop();

}
