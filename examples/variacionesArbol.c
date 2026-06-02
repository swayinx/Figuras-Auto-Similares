#include <CSFML/Graphics/Shader.h>
#include <CSFML/Window/Keyboard.h>

#include "../turtlec.h"

void branch(Turtle* t, float length, int deep, float angle) {
    if (deep == 0) return;

    turtleForward(t, length);

    turtleLeft(t, angle);
    branch(t, length * 0.7, deep - 1, angle);

    turtleRight(t, 2 * angle);
    branch(t, length * 0.7, deep - 1, angle);

    turtleLeft(t, angle);

    if (deep <= 3) {
        turtleSetColor(t, 32, 171, 17);
    } else {
        turtleSetColor(t, 71, 44, 44);
    }
    turtleBackward(t, length);
}

int main(void) {
    TurtleApp* app = turtleAppCreate(800, 800, "arbol");
    if (app == NULL) return 1;
    Turtle* t = turtleAppGetTurtle(app);

    turtleSetSpeed(t, 15);
    turtleLeft(t, 90);
    turtlePenUp(t);
    turtleBackward(t, 200.0);
    turtlePenDown(t);

    branch(t, 150.0, 5, 30.0);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
