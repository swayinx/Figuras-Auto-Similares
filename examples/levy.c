#include <math.h>

#include "../turtlec.h"

void levy(Turtle* t, float length, int depth) {
    if (depth == 0) {
        turtleForward(t, length);
        return;
    }
    turtleLeft(t, 45);
    levy(t, length / sqrt(2), depth - 1);

    turtleRight(t, 90);
    levy(t, length / sqrt(2), depth - 1);

    turtleLeft(t, 45);
}

int main(void) {
    TurtleApp* app = turtleAppCreate(800, 800, "arbol");
    if (app == NULL) return 1;
    Turtle* t = turtleAppGetTurtle(app);

    turtleSetSpeed(t, 30);
    turtlePenUp(t);
    turtleBackward(t, 200.0);
    turtlePenDown(t);

    levy(t, 300.0, 10);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
