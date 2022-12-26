#include <random>
#include <chrono>
#include <GL/glut.h>

const char* WINDOW_NAME = "Random Shapes";
const int WINDOW_HEIGHT = 400;
const int WINDOW_WIDTH  = 400;

/**
 * Initializes the window.
 * @param argc argument count passed from main
 * @param argv argument vector passed from main
 */
void init(int &argc, char** &argv);
/**
 * Setup the initial scene
 */
void scene();
/**
 * When space is pressed, generate new random drawing
 * @param key The key pressed
 * @param x mouse x position when key is pressed
 * @param y mouse y position when key is pressed
 */
void onSpace(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    init(argc, argv);
    // Initial scene
    glutDisplayFunc(scene);
    // Listen for space bar
    glutKeyboardFunc(onSpace);
    glutMainLoop();

    return 0;
}

void init(int &argc, char** &argv) {
    // Initialize window
    glutInit(&argc, argv);
    // Size of window
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    // Where the window shows up from the top left of the screen
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-WINDOW_WIDTH)/2, (glutGet(GLUT_SCREEN_HEIGHT)-WINDOW_HEIGHT)/2);
    /*
     * Set the display modes
     * GLUT_RGBA - RGBA Color Scheme
     * GLUT_DOUBLE - Double buffer window (smoother animation)
     * GLUT_STENCIL - Stencil style buffer (good for 2D)
     */
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_STENCIL);
    // Create window
    glutCreateWindow(WINDOW_NAME);
}

void scene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    using namespace std::chrono;

    milliseconds currentTimeMillis = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    std::default_random_engine generator(currentTimeMillis.count());
    std::uniform_real_distribution<double> distribution(-1,1);

    glBegin(GL_POLYGON);
        for (int i = 0; i < 5; i++)
            glVertex2d(distribution(generator), distribution(generator));
        glColor4ub(255, 100, 0,255);
    glEnd();

    glutSwapBuffers();
}

void onSpace(unsigned char key, int x, int y) {
    // 32 is the ASCII value of space
    if (key == 32) {
        scene();
    }
}

