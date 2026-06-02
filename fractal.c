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
 
    fractalTree(t, 100,6);




    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
} 
