#include "../../turtlec.h"
#include "math.h"

void fractalTree(Turtle *t, float length, int depth){
  if(depth==0 || length<10)
    return;
  if (depth>5)
    turtleSetColor(t,120,70,20);
  else
    turtleSetColor(t,0,200,0);
  turtleForward(t, length);
  
  turtleLeft(t, 20);
  fractalTree(t, length*0.6, depth-1);
  
  turtleRight(t, 40);
  fractalTree(t, length*0.6, depth-1);

  turtleLeft(t, 20);
  if (depth>5)
    turtleSetColor(t,120,70,20);
  else
    turtleSetColor(t,0,200,0);
  turtleBackward(t, length);
}

void fractalTree2(Turtle *t, float length, int depth){
  if (depth==0 || length<5)
    return;
  if (length==100){
    turtleLeft(t,90);
  } 
  turtleForward(t, length);

  turtleLeft(t,30);
  fractalTree2(t, length/2, depth-1);

  turtleRight(t,60);
  fractalTree2(t, length/2, depth-1);

  turtleLeft(t,30);
  turtleBackward(t,length);
}

void fractalTree3(Turtle *t, float length, int depth){
  if (depth==0 || length<5)
    return;
     
  turtleForward(t, length);
   
  turtleLeft(t, 60);
  fractalTree3(t, length*0.7, depth-1);

  turtleRight(t, 120);
  fractalTree3(t, length*0.7, depth-1);

  turtleLeft(t, 60);
  fractalTree3(t, length*0.7, depth-1);
  turtleBackward(t, length);
}

void fractalTree4(Turtle *t, float length, int depth){
  if (depth==0 || length<5)
    return;
  turtleForward(t, length);

  turtleLeft(t, 30);
  fractalTree4(t, length*0.9, depth-1);

  turtleRight(t, 60);
  fractalTree4(t, length*0.4, depth-1);

  turtleLeft(t, 30);
  turtleBackward(t, length);
}

void fractalTree5(Turtle *t, float length, int depth){
  if (depth==0 || length<5)
    return;
  if (depth>5){
    turtleSetColor(t,255,0,0);
  }
  else if(depth>3)
    turtleSetColor(t,255,255,255);
  else 
    turtleSetColor(t, 255,0,0);
  turtleForward(t, length);

  turtleLeft(t, 30);
  fractalTree5(t, length*0.6, depth-1);

  turtleRight(t, 60);
  fractalTree5(t, length*0.6, depth-1);

  turtleLeft(t, 30);
  if (depth>5){
    turtleSetColor(t,255,0,0);
  }
  else if(depth>3)
    turtleSetColor(t,255,255,255);
  else 
    turtleSetColor(t, 255,0,0); 
  turtleBackward(t, length);
}


void levy(Turtle *t, float length, float depth){
  if (depth==0){
    turtleForward(t, length);
    return; 
  }

  turtleLeft(t, 45);
  levy(t, length/sqrt(2), depth-1);
  
  turtleRight(t, 90);
  levy(t, length/sqrt(2), depth-1);

  turtleLeft(t, 45);
}

int main(){
  TurtleApp *app = turtleAppCreate(600, 600, "arboles");

    if (app == NULL)
      return 1;

    Turtle *t = turtleAppGetTurtle(app);
                                                       
    turtlePenUp(t);
    turtleGoTo(t, 300, 300);
    turtlePenDown(t);

    turtleSetColor(t, 255, 100, 0);
    turtleSetSpeed(t, 2);
 
    //fractalTree(t, 100,6);
    //fractalTree2(t, 100, 4);
    //triangulo(t, 100, 2);
    //levy(t, 200, 1);
    //fractalTree3(t, 100, 4);
    //fractalTree4(t, 100, 4);
    fractalTree5(t, 100, 6);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}   
