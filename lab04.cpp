#include<stdio.h>
#include<GL/glut.h>

int i=0,j,n;
float m[10][3];

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( 0 , 100 , 0 , 100 );

}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    glBegin(GL_LINE_LOOP);

            glColor3f( 1.0 , 0.0 , 0.0 );

            for( i = 0 ; i < n ; i++ )
                glVertex2f( m[i][0] , m[i][1] );



    glEnd();

    glutSwapBuffers();

}

void reshape( int w , int h ){

    glViewport( 0 , 0 , w , h  );

}

int main( int argc, char **argv ){

    printf( "\n Enter the no: of vertices : " );
    scanf( "%d",&n );

    printf( "\n Enter the points (x,y) : " );
    for( i = 0 ; i < n ; i++ )
        scanf( "%f%f",& m[i][0], &m[i][1] );

    for( i = 0 ; i < n ; i++ )
        m[i][2] = 1 ;


    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 650 , 650 );
    glutInitWindowPosition( 10 , 10 );
    glutCreateWindow( "2D Trans" );

    init();

    //callback functions
    glutDisplayFunc( display );
    glutIdleFunc( display );
    glutReshapeFunc(reshape);

    glutMainLoop();

}
