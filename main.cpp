#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

//Game Speed
int FPS = 50;
//Game Track
int start=0;
int gv=0;
int level = 0;
//Track Score
int score = 0;
//Form move track
int fieldDivTopMost = 0;
int fieldDivTop = 0;
int fieldDivMdl = 0;
int fieldDivBtm = 0;
//For Card Left / RIGHT
int lrIndex = 0 ;
//Players Coming
int player1 = 0;
int lrIndex1=0;
int player2 = +35;
int lrIndex2=0;
int player3 = +70;
int lrIndex3=0;
//For Display TEXT
const int font1=0x0005;  //TIMES_ROMAN_24
const int font2=0x0008 ; //HELVETICA_18
const int font3=0x0003;  //BY_13
char s[30];

void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}



void startGame(){
    //Field
    glColor3f(0.000, 0.592, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Left margin
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(23,100);
    glVertex2f(23,0);
    glEnd();

    //Right margin
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77,0);
    glVertex2f(77,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();


    fieldDivTop--;
    if(fieldDivTop<-100){
        fieldDivTop =20;
        score++;
    }

    fieldDivMdl--;
    if(fieldDivMdl<-60){
        fieldDivMdl =60;
        score++;
    }

    fieldDivBtm--;
    if(fieldDivBtm<-20){
        fieldDivBtm=100;
        score++;
    }

    //Score Board
     glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80,97);
    glVertex2f(100,97);
    glVertex2f(100,98-8);
    glVertex2f(80,98-8);
    glEnd();

    //Print Score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95,(void *)font3,buffer);
    //level Print
    if(score % 50 == 0){
        int last = score /50;
        if(last!=level){
            level = score /50;
            FPS=FPS+2;
        }
    }
    char level_buffer [50];
    sprintf (level_buffer, "LEVEL: %d", level);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95-4,(void *)font3,level_buffer);

    //Increse Speed With level

    //Player
        //Ball
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+30,1);
    glVertex2f(lrIndex+30,3);
    glVertex2f(lrIndex+30+2,3);
    glVertex2f(lrIndex+30+2,1);
    glEnd();
    //Player hands
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26-2,7);
    glVertex2f(lrIndex+26-2,5.5);
    glVertex2f(lrIndex+30+2,5.5);
    glVertex2f(lrIndex+30+2,7);
    glEnd();
        //Player Body
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,1);
    glVertex2f(lrIndex+26,8);
    glVertex2f(lrIndex+30,8);
    glVertex2f(lrIndex+30,1);
    glEnd();
    //Player shorts
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,2.5);
    glVertex2f(lrIndex+26,4);
    glVertex2f(lrIndex+30,4);
    glVertex2f(lrIndex+30,2.5);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,1);
    glVertex2f(lrIndex+26,1.75);
    glVertex2f(lrIndex+30,1.75);
    glVertex2f(lrIndex+30,1);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+27.9,1);
    glVertex2f(lrIndex+27.9,4);
    glVertex2f(lrIndex+28.1,4);
    glVertex2f(lrIndex+28.1,1);
    glEnd();
    //Player head
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,9.5);
    glVertex2f(lrIndex+26,7.5);
    glVertex2f(lrIndex+30,7.5);
    glVertex2f(lrIndex+30,9.5);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex+26,9.5);
    glVertex2f(lrIndex+26,10);
    glVertex2f(lrIndex+30,10);
    glVertex2f(lrIndex+30,9.5);
    glEnd();

    //Opposite player1 1

//Player hands
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26-2,player1+100+7);
    glVertex2f(lrIndex1+26-2,player1+100+5.5);
    glVertex2f(lrIndex1+30+2,player1+100+5.5);
    glVertex2f(lrIndex1+30+2,player1+100+7);
    glEnd();
        //Player Body
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,player1+100+1);
    glVertex2f(lrIndex1+26,player1+100+8);
    glVertex2f(lrIndex1+30,player1+100+8);
    glVertex2f(lrIndex1+30,player1+100+1);
    glEnd();
    //Player shorts
    glColor3f(1.000, 0.00, 0.00);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,player1+100+2.5);
    glVertex2f(lrIndex1+26,player1+100+4);
    glVertex2f(lrIndex1+30,player1+100+4);
    glVertex2f(lrIndex1+30,player1+100+2.5);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,player1+100+1);
    glVertex2f(lrIndex1+26,player1+100+1.75);
    glVertex2f(lrIndex1+30,player1+100+1.75);
    glVertex2f(lrIndex1+30,player1+100+1);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+27.9,player1+100+1);
    glVertex2f(lrIndex1+27.9,player1+100+4);
    glVertex2f(lrIndex1+28.1,player1+100+4);
    glVertex2f(lrIndex1+28.1,player1+100+1);
    glEnd();
    //Player head
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,player1+100+9.5);
    glVertex2f(lrIndex1+26,player1+100+7.5);
    glVertex2f(lrIndex1+30,player1+100+7.5);
    glVertex2f(lrIndex1+30,player1+100+9.5);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1+26,player1+100+9.5);
    glVertex2f(lrIndex1+26,player1+100+10);
    glVertex2f(lrIndex1+30,player1+100+10);
    glVertex2f(lrIndex1+30,player1+100+9.5);
    glEnd();

    player1--;
    if(player1<-100){
        player1=0;
        lrIndex1=lrIndex;
    }
    //Dispossession player1
    if((abs(lrIndex-lrIndex1)<8) && (player1+100<10)){
            start = 0;
            gv=1;

    }

    //Opposite player 2
    //Player hands
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26-2,player2+100+7);
    glVertex2f(lrIndex2+26-2,player2+100+5.5);
    glVertex2f(lrIndex2+30+2,player2+100+5.5);
    glVertex2f(lrIndex2+30+2,player2+100+7);
    glEnd();
        //Player Body
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,player2+100+1);
    glVertex2f(lrIndex2+26,player2+100+8);
    glVertex2f(lrIndex2+30,player2+100+8);
    glVertex2f(lrIndex2+30,player2+100+1);
    glEnd();
    //Player shorts
    glColor3f(1.000, 0.00, 0.00);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,player2+100+2.5);
    glVertex2f(lrIndex2+26,player2+100+4);
    glVertex2f(lrIndex2+30,player2+100+4);
    glVertex2f(lrIndex2+30,player2+100+2.5);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,player2+100+1);
    glVertex2f(lrIndex2+26,player2+100+1.75);
    glVertex2f(lrIndex2+30,player2+100+1.75);
    glVertex2f(lrIndex2+30,player2+100+1);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+27.9,player2+100+1);
    glVertex2f(lrIndex2+27.9,player2+100+4);
    glVertex2f(lrIndex2+28.1,player2+100+4);
    glVertex2f(lrIndex2+28.1,player2+100+1);
    glEnd();
    //Player head
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,player2+100+9.5);
    glVertex2f(lrIndex2+26,player2+100+7.5);
    glVertex2f(lrIndex2+30,player2+100+7.5);
    glVertex2f(lrIndex2+30,player2+100+9.5);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2+26,player2+100+9.5);
    glVertex2f(lrIndex2+26,player2+100+10);
    glVertex2f(lrIndex2+30,player2+100+10);
    glVertex2f(lrIndex2+30,player2+100+9.5);
    glEnd();
    player2--;
    if(player2<-100){
        player2=0;
        lrIndex2=lrIndex;
    }
    //dispossession player2
    if((abs(lrIndex-lrIndex2)<8) && (player2+100<10)){
            start = 0;
            gv=1;
    }
    //Opposite player 3
    //Player hands
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26-2,player3+100+7);
    glVertex2f(lrIndex3+26-2,player3+100+5.5);
    glVertex2f(lrIndex3+30+2,player3+100+5.5);
    glVertex2f(lrIndex3+30+2,player3+100+7);
    glEnd();
        //Player Body
    glColor3f(0.000, 0.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,player3+100+1);
    glVertex2f(lrIndex3+26,player3+100+8);
    glVertex2f(lrIndex3+30,player3+100+8);
    glVertex2f(lrIndex3+30,player3+100+1);
    glEnd();
    //Player shorts
    glColor3f(1.000, 0.00, 0.00);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,player3+100+2.5);
    glVertex2f(lrIndex3+26,player3+100+4);
    glVertex2f(lrIndex3+30,player3+100+4);
    glVertex2f(lrIndex3+30,player3+100+2.5);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,player3+100+1);
    glVertex2f(lrIndex3+26,player3+100+1.75);
    glVertex2f(lrIndex3+30,player3+100+1.75);
    glVertex2f(lrIndex3+30,player3+100+1);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+27.9,player3+100+1);
    glVertex2f(lrIndex3+27.9,player3+100+4);
    glVertex2f(lrIndex3+28.1,player3+100+4);
    glVertex2f(lrIndex3+28.1,player3+100+1);
    glEnd();
    //Player head
    glColor3f(0.9, 0.9, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,player3+100+9.5);
    glVertex2f(lrIndex3+26,player3+100+7.5);
    glVertex2f(lrIndex3+30,player3+100+7.5);
    glVertex2f(lrIndex3+30,player3+100+9.5);
    glEnd();
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3+26,player3+100+9.5);
    glVertex2f(lrIndex3+26,player3+100+10);
    glVertex2f(lrIndex3+30,player3+100+10);
    glVertex2f(lrIndex3+30,player3+100+9.5);
    glEnd();
    player3--;
    if(player3<-100){
        player3=0;
        lrIndex3=lrIndex;
    }
    //dispossession player3
    if((abs(lrIndex-lrIndex3)<8) && (player3+100<10)){
            start = 0;
            gv=1;
    }
}

void fristDesign(){

        //Background
        glColor3f(0.000, 0.749, 1.000);
        glBegin(GL_POLYGON);
        glVertex2f(100,100);
        glVertex2f(0,100);
        glColor3f(0.686, 0.933, 0.933);
        glVertex2f(0,0);
        glVertex2f(100,0);
        glEnd();

        //Menu Place Holder
        glColor3f(0.098, 0.098, 0.439);
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();

        glColor3f(00, 0, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50+4+10);
        glVertex2f(32-4,50+4+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32+45,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32+45,50-15+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50-14+10);
        glVertex2f(32+46,50-14+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32-5,50+5+10);
        glVertex2f(32-5,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();

        //Text Information in Frist Page
        if(gv==1){
            glColor3f(1.000, 0.000, 0.000);
            renderBitmapString(35,60+10,(void *)font1,"GAME OVER");
            glColor3f(1.000, 0.000, 0.000);
            char buffer2 [50];
            sprintf (buffer2, "Your Score is : %d", score);
            renderBitmapString(33,60-4+10,(void *)font1,buffer2);

        }
        glColor3f(0.000, 0.000, 0.000);
        renderBitmapString(30,80,(void *)font1,"2D Football Game ");

        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(30,50+10,(void *)font2,"Press SPACE to START");
        renderBitmapString(30,50-3+10,(void *)font2,"Press ESC to Exit");

        glColor3f(1.000, 1.000, 1.000);
        renderBitmapString(30,50-6+10,(void *)font3,"Press UP to increase Speed");
        renderBitmapString(30,50-8+10,(void *)font3,"Press DWON to decrease Speed");
        renderBitmapString(30,50-10+10,(void *)font3,"Press RIGHT to turn Right");
        renderBitmapString(30,50-12+10,(void *)font3,"Press LEFT to turn Left");

        glColor3f(0.000, 0.000, 0.000);
        renderBitmapString(30-5,50-40,(void *)font2,"Project By:");
        renderBitmapString(30-5,50-43,(void *)font2,"Tintea Daniel");
}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(start==1){
        glClearColor(0.000, 0.392, 0.000,1);
        startGame();
    }

    else{
        fristDesign();
    }
    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y){
        switch (key) {
        case GLUT_KEY_DOWN:
            if(FPS>(50+(level*2)))
            FPS=FPS-2;
            break;
        case GLUT_KEY_UP:
            FPS=FPS+2;
            break;
        case GLUT_KEY_LEFT:
            if(lrIndex>=0){
                lrIndex = lrIndex - (FPS/10);
                if(lrIndex<0){
                    lrIndex=-1;
                }
            }
            break;
        case GLUT_KEY_RIGHT:
            if(lrIndex<=44){
                lrIndex = lrIndex + (FPS/10);
                if(lrIndex>44){
                    lrIndex = 45;
                }
            }
            break;

        default:
                break;
        }
}

void processKeys(unsigned char key, int x, int y) {
      switch (key)
            {
                case ' ':
            if(start==0){
                start = 1;
                gv = 0;
                FPS = 50;
                fieldDivTopMost = 0;
                fieldDivTop = 0;
                fieldDivMdl = 0;
                fieldDivBtm = 0;
                lrIndex = 0 ;
                player1 = 0;
                lrIndex1=0;
                player2 = +35;
                lrIndex2=0;
                player3 = +70;
                lrIndex3=0;
                score=0;
                level=0;
            }
             break;
             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,650);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Football Game");

    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0.184, 0.310, 0.310,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}
