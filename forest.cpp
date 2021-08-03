#include<windows.h>
#include<GL\glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>
#define PI 3.1416

GLint i, j, k;
GLfloat sun_spin = 0, sun_x = 0, sun_y = 0;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0, str = 500.0, mn = 500.0;
GLfloat sr = 0.0, sg = 0.749, sb = 1.0;
GLfloat spin = 0.0;

void init(void)
{
    glClearColor(.40, .110, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void circle(GLdouble rad)
{
    GLint points = 50;
    GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
    GLdouble theta = 0.0;

    glBegin(GL_POLYGON);
    {
        for (i = 0; i <= 50; i++, theta += delTheta)
        {
            glVertex2f(rad * cos(theta), rad * sin(theta));
        }
    }
    glEnd();
}

void Sun_Model() {
    glPushMatrix();
    glTranslatef(500, 0, 0);
    circle(30);
    glPopMatrix();
}

void Moving_Sun_Model() {
    glPushMatrix();
    glRotatef(-sun_spin, 0, 0, -.009);
    Sun_Model();
    glPopMatrix();
}

void cloud_model_one() {
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 225, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(355, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(350, 210, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(345, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(335, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(330, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(325, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(315, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(310, 204, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(305, 204, 0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Two() {
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(305, 205, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(334, 207, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 207, 0);
    circle(10);
    glPopMatrix();
}

void cloud_model_Three() {
    glColor3f(1.25, 0.924, 0.930);

    glPushMatrix();
    glTranslatef(300, 200, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 220, 0);
    circle(16);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 210, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(380, 200, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(360, 190, 0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(320, 190, 0);
    circle(20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(340, 190, 0);
    circle(20);
    glPopMatrix();
}

void hill_big() {
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
    glVertex2i(70, 70);
    glVertex2i(200, 225);
    glVertex2i(330, 70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(200, 225);
    glVertex2i(230, 190);
    glVertex2i(220, 180);
    glVertex2i(200, 190);
    glVertex2i(190, 180);
    glVertex2i(170, 190);
    glEnd();
}

void hill_small() {
    glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
    glVertex2i(250, 100);
    glVertex2i(310, 175);
    glVertex2i(370, 100);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
    glVertex2i(310, 175);
    glVertex2i(330, 150);
    glVertex2i(325, 140);
    glVertex2i(310, 150);
    glVertex2i(300, 140);
    glEnd();
}

void Bush_One_Model() {
    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(125, 70);
    glVertex2i(150, 80);
    glVertex2i(160, 90);
    glVertex2i(170, 90);
    glVertex2i(180, 100);
    glVertex2i(190, 105);
    glVertex2i(200, 108);
    glVertex2i(300, 110);
    glVertex2i(300, 70);
    glEnd();
}

void Bush_Two_Model() {
    glColor3f(0.1, 1.293, 0.0);
   
    glPushMatrix();
    glTranslatef(430, 90, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(420, 87, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(410, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(400, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(390, 70, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(445, 80, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(455, 75, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(465, 70, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(470, 65, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(480, 60, 0);
    circle(30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(485, 55, 0);
    circle(20);
    glPopMatrix();
}

void field() {
    glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
    glVertex2i(0, 50);
    glVertex2i(0, 70);
    glVertex2i(1000, 70);
    glVertex2i(1000, 50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 1.293, 0.0);
    glVertex2i(0, 0);
    glVertex2i(0, 50);
    glVertex2i(1000, 50);
    glVertex2i(1000, 0);
    glEnd();
}

void Tree_Model_One() {
    glPushMatrix();
    glTranslatef(110, 110, 0);
    circle(15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(110, 100, 0);
    circle(15);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(109, 70);
    glVertex2f(109, 90);
    glVertex2f(111, 90);
    glVertex2f(111, 70);
    glEnd();
}

void Tree_Model_Two() {
    glPushMatrix();
    glTranslatef(130, 130, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(125, 126, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(135, 126, 0);
    circle(10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 125, 0);
    circle(10);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(129, 110);
    glVertex2f(129, 124);
    glVertex2f(131, 124);
    glVertex2f(131, 110);
    glEnd();
}

void Tree_Model_Three() {
    glBegin(GL_POLYGON);
    glVertex2f(105, 123);
    glVertex2f(133, 175);
    glVertex2f(161, 123);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
    glVertex2f(132, 110);
    glVertex2f(132, 124);
    glVertex2f(134, 124);
    glVertex2f(134, 110);
    glEnd();
}

void Sun() {
    glColor3f(1, 1, 0);
    glPushMatrix();
    Moving_Sun_Model();
    glPopMatrix();
}

void cloud_one() {
    glPushMatrix();
    glTranslatef(cx, -40, 0);
    cloud_model_one();
    glPopMatrix();
}

void cloud_two() {
    glPushMatrix();
    glTranslatef(bx + 100, 150, 0);
    cloud_model_one();
    glPopMatrix();
}

void cloud_three() {
    glPushMatrix();
    glTranslatef(ax - 80, 80, 0);
    cloud_model_Two();
    glPopMatrix();
}

void cloud_four() {
    glPushMatrix();
    glTranslatef(dx + 300, 125, 0);
    cloud_model_Two();
    glPopMatrix();
}

void cloud_five() {
    glPushMatrix();
    glTranslatef(ax + -300, 170, 0);
    cloud_model_Three();
    glPopMatrix();
}

void cloud_six() {
    glPushMatrix();
    glTranslatef(cx + -500, 20, 0);
    cloud_model_Three();
    glPopMatrix();
}

void Hill_Big_One() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_big();
    glPopMatrix();
}

void Hill_Big_Two() {
    glPushMatrix();
    glTranslatef(550, -20, 0);
    hill_big();
    glPopMatrix();
}

void Hill_Small_One() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    hill_small();
    glPopMatrix();
}

void Bush_One() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Bush_One_Model();
    glPopMatrix();
}

void Bush_Two() {
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Bush_Two_Model();
    glPopMatrix();
}

void Bush_Three() {
    glPushMatrix();
    glTranslatef(400, 0, 0);
    Bush_Two_Model();
    glPopMatrix();
}

void Bush_Four() {
    glColor3f(0.833, 1., 0.0);
    glPushMatrix();
    glTranslatef(380, 0, 0);
    Bush_One_Model();
    glPopMatrix();
}

void Tree_One() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Two() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(540, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Three() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(750, 0, 0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Four() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(292, 40, 0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Five() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(30, -20, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Six() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(50, -10, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Seven() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(322, 0, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Eight() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(350, -15, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Nine() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(760, -25, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Ten() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(90, -2, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Eleven() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(125, 0, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Twelve() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(408, -22, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Thirteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(567, -89, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Fourteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(560, -70, 0);
    Tree_Model_One();
    glPopMatrix();
}

void Tree_Fifteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(236, -68, 0);
    Tree_Model_Two();
    glPopMatrix();
}

void Tree_Sixteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(595, -89, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Seventeen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(500, -89, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void Tree_Eighteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(356, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_Nineteen() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(200, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_Twenty() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(78, -65, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyOne() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(156, -82, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyTwo() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-72, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyThree() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(56, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyFour() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(200, -100, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyFive() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-23, -82, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentySix() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(143, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentySeven() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(283, -78, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyEight() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(100, -110, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_TwentyNine() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-100, -99, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_Thirty() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-87, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyOne() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-69, -95, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyTwo() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(-12, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyThree() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(34, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyFour() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(169, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyFive() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(273, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtySix() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(344, -96, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtySeven() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(398, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyEight() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(438, -72, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_ThirtyNine() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(454, -109, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_Forty() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(696, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_FortyOne() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(734, -104, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_FortyTwo() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(638, -100, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_FortyThree() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(790, -100, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_FortyFour() {
    glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(820, -110, 0);
    Tree_Model_Three();
    glPopMatrix();
}
void Tree_FortyFive() {
     glColor3f(0.0, 0.5, 0.0);
    glPushMatrix();
    glTranslatef(846, -100, 0);
    Tree_Model_Three();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);

    Sun();
    Hill_Big_One();
    Bush_Four();
    Hill_Big_Two();
    Hill_Small_One();
    cloud_three();
    cloud_four();
    Bush_One();
    Bush_Two();
    Bush_Three();
    cloud_one();
    Tree_One();
    Tree_Two();
    Tree_Three();
    Tree_Four();
    Tree_Five();
    Tree_Six();
    Tree_Seven();
    Tree_Eight();
    Tree_Nine();
    Tree_Ten();
    Tree_Eleven();
    Tree_Twelve();
    cloud_two();
    cloud_five();
    cloud_six();
    field();
    Tree_Thirteen();
    Tree_Fourteen();
    Tree_Fifteen();
    Tree_Sixteen();
    Tree_Seventeen();
    Tree_Eighteen();
    Tree_Nineteen();
    Tree_Twenty();
    Tree_TwentyOne();
    Tree_TwentyTwo();
    Tree_TwentySeven();
    Tree_TwentyThree();
    Tree_TwentyFour();
    Tree_TwentyFive();
    Tree_TwentySix();
    Tree_TwentyEight();
    Tree_TwentyNine();
    Tree_Thirty();
    Tree_ThirtyOne();
    Tree_ThirtyTwo();
    Tree_ThirtyThree();
    Tree_ThirtyFour();
    Tree_ThirtyFive();
    Tree_ThirtySix();
    Tree_ThirtySeven();
    Tree_ThirtyEight();
    Tree_ThirtyNine();
    Tree_Forty();
    Tree_FortyOne();
    Tree_FortyTwo();
    Tree_FortyThree();
    Tree_FortyFour();
    Tree_FortyFive();
    glFlush();
}

void sun_move() {
    sun_spin = sun_spin + 0.0008;
}

void move_right() {
    sun_move();
    spin = spin + .1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;
    if (cx > 1000) {
        cx = -300;
    }
    if (bx > 1000) {
        bx = -400;
    }
    if (cx > 1000) {
        cx = -400;
    }
    if (dx > 1000) {
        dx = -500;
    }
    glutPostRedisplay();
}

void mouse(int key, int state, int x, int y) {
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(1900, 1900);
    glutCreateWindow("A forest scene");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}