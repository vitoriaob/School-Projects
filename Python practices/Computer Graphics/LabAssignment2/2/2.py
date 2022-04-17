import glfw
from OpenGL.GL import *

#Adapting code from class 2 given by professor 이윤상

def render(option):
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    glBegin(option)
    glVertex2f(-0.5, 0.5)
    glVertex2f(-0.5,-0.5)
    glVertex2f(0.5,-0.5)
    glVertex2f(0.5,0.5)
    glEnd()

def main(option):
    # Initialize the library
    if not glfw.init():
        return
    # Create a windowed mode window and its OpenGL context
    window = glfw.create_window(640,480,"Hello World", None,None)
    if not window:
        glfw.terminate()
        return

    # Make the window's context current
    glfw.make_context_current(window)

    # Loop until the user closes the window
    while not glfw.window_should_close(window):
        # Poll events
        glfw.poll_events()

        # Render here, e.g. using pyOpenGL
        render(option)

        # Swap front and back buffers
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    index = input("Insert the type number: ")
    types = [GL_POLYGON, GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_TRIANGLES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_QUADS, GL_QUAD_STRIP]
    option = types[int(index)]
    main(option)
    

