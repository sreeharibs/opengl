#include<stdio.h>
#include<GL/glut.h>

int i=0,j,k,n;
float xmin = -100 , xmax = 100 , ymin = -100 , ymax = 100 ;
float xd1,yd1,xd2,yd2;


void init(){

    glClearColor( 0.0,0.0,0.0,1.0 );
    gluOrtho2D( -300 , 300 , -300 , 300 );

}

int ABRL( float x, float y ){

    int c=0;

    if (y>ymax) c = c | 8 ;
    if (y<ymin) c = c | 4 ;
    if (x>xmax) c = c | 2 ;
    if (x<xmin) c = c | 1 ;

    return c;

}

void cohen( float x1, float y1, float x2, float y2 ){

    int c1  = ABRL( x1 , y1 );
    int c2  = ABRL( x2 , y2 );

    float m = (y2-y1)/(x2-x1);

    printf("\n\n %d %d %d", c1,c2,c1&c2);

    while( (c1|c2) > 0 ){



        if ( (c1&c2) > 0 ) {

            //trivially reject

            break;

        }

        //clip C1

        if ( (c1 & 8) > 0 ){

            y1 = ymax;
            x1 = x2 + 1/m*(y1-y2);

        }

       // repeat if for 4 2 1

        //similarly write code to clip c2


        //
        
        
        xd1 = x1;
        yd1 = y1;
        xd2 = x2;
        yd2 = y2;

        c1 = ABRL( xd1 , yd1 );
        c2 = ABRL( xd2 , yd2 );
    }




    printf("\n (%f,%f) & (%f,%f) ",xd1,yd1,xd2,yd2);


}

void display(){

    glClear( GL_COLOR_BUFFER_BIT );

    //static - ship
    glBegin(GL_LINE_LOOP);

            glColor3f( 0.0 , 1.0 , 0.0 );

            glVertex2i( xmin , ymin );
            glVertex2i( xmin , ymax );
            glVertex2i( xmax , ymax );
            glVertex2i( xmax , ymin );

    glEnd();

    glBegin(GL_LINES);

            glColor3f( 1.0 , 0.0 , 0.0 );

            glVertex2i( xd1 , yd1 );
            glVertex2i( xd2 , yd2 );

            printf("\n (%f,%f) & (%f,%f) ",xd1,yd1,xd2,yd2);

    glEnd();

    glutSwapBuffers();

}

void reshape( int w , int h ){

    glViewport( 0 , 0 , w , h  );

}

void keyPressed( unsigned char key , int x , int y ){

    cohen(xd1,yd1,xd2,yd2);

}

int main( int argc, char **argv ){

    printf( "\n Enter the LINE coordinates (x1,y1) and (x2,y2) : " );
    scanf( "%f%f%f%f", &xd1, &yd1, &xd2, &yd2 );

    glutInit( &argc , argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize( 650 , 650 );
    glutInitWindowPosition( 10 , 10 );
    glutCreateWindow( " Line Clipping " );

    init();

    //callback functions
    glutDisplayFunc( display );
    glutIdleFunc( display );
    glutReshapeFunc( reshape );
    glutKeyboardFunc( keyPressed );

    glutMainLoop();

    return 0;

}

