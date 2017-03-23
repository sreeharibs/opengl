#include<stdio.h>
#include<GL/glut.h>

int i=0,j,k,n;
float sum=0;
float m[10][3],mt[3][3],mPdt[10][3];

void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( 0 , 100 , 0 , 100 );

}

void matrixInit(){

   for(i=0;i<3;i++){}
	for(j=0;j<3;j++)
		mt[i][j]=(i=j);
}

void matrixMult(){

    for( i=0;i<n;i++ ){
            for( j=0;j<3;j++ ) {
                for( k=0;k<3;k++ )

                    sum=sum+m[i][k]*mt[k][j];

                mPdt[i][j]=sum;
                sum=0;
            }
   }


}

void matrixCopyPdt(){

    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
            m[i][j]=mPdt[i][j];


}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
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
