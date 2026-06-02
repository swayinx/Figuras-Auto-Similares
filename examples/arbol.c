#include "../turtlec.h"

void branch(Turtle* t, float length, int deep, float angle) {
    if (deep == 0) return;

    turtleForward(t, length);

    turtleLeft(t, angle);
    branch(t, length * 0.7, deep - 1, angle);

    turtleRight(t, 2 * angle);
    branch(t, length * 0.7, deep - 1, angle);

    turtleLeft(t, angle);
    turtleBackward(t, length);
}

int main(void) {
    TurtleApp* app = turtleAppCreate(800, 800, "arbol");
    if (app == NULL) return 1;
    Turtle* t = turtleAppGetTurtle(app);

    branch(t, 50.0, 4, 30.0);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
