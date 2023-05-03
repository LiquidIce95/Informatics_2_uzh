#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>

int main(int argc, char** argv) {
    Display* display;
    Window window;
    XEvent event;
    const char* title = "X11 Window Example";
    const unsigned int width = 400;
    const unsigned int height = 300;

    /* Connect to the X server */
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Failed to open X display\n");
        exit(1);
    }

    /* Create the window */
    window = XCreateSimpleWindow(display, DefaultRootWindow(display), 0, 0, width, height, 0, 0, 0);
    XStoreName(display, window, title);
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    /* Event loop */
    while (1) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            /* Redraw the window */
            XClearWindow(display, window);
        } else if (event.type == KeyPress) {
            /* Exit the program when a key is pressed */
            break;
        }
    }

    /* Clean up and exit */
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}
