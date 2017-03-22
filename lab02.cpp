#include<GL/glut.h>
#include<stdio.h>

void display(){

    glClear( GL_COLOR_BUFFER_BIT );


    glBegin( GL_TRIANGLES );

            glColor3f( 0.0 , 1.0 , 0.0 );

            glVertex3f( -0.5 , -0.5 , 0.0 );
            glVertex3f(  0.5 , -0.5 , 0.0 );
            glVertex3f(  0.0 ,  0.5 , 0.0 );

    glEnd();


    glutSwapBuffers();

}


void reshape(int w, int h){

    glViewport(0,0,w,h);

}


void init(){

    //color chan.  R     G     B     A
    glClearColor( 0.0, 0.0 , 0.0 , 1.0 );


}
int main(int argc, char** argv){

    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize( 500 , 500 );
    glutInitWindowPosition( 100 , 100 );
    glutCreateWindow( "My First OpenGL Program" );

    init();

    //callBack functions
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();


    return 0;

}

