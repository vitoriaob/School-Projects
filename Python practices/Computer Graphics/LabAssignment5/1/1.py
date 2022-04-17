import glfw
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np

def render():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glLoadIdentity()
    drawFrame()
    glColor3ub(255, 255, 255)
    drawTriangle()

    glTranslatef(0.6, 0, 0)
    glRotatef(30.,0.,0.,1.0)
    drawFrame()
    glColor3ub(0,0, 255)
    drawBox()

    glLoadIdentity()
    glRotatef(-90.,0.,0.,1.0)
    glTranslatef(0.3, 0, 0) 
    drawFrame()
    glColor3ub(255, 0, 0)
    drawTriangle()    

    

def drawFrame():
    glBegin(GL_LINES)
    glColor3ub(255, 0, 0)
    glVertex2fv([0., 0.])
    glVertex2fv([1., 0.])
    glColor3ub(0, 255, 0)
    glVertex2fv([0., 0.])
    glVertex2fv([0., 1.])
    glEnd()

def drawTriangle():
    glBegin(GL_TRIANGLES)
    glVertex2fv([0., .5])
    glVertex2fv([0., 0.])
    glVertex2fv([.5, 0.])
    glEnd()

def drawBox():
    glBegin(GL_QUADS)
    glVertex2fv([0., .5])
    glVertex2fv([0., 0.])
    glVertex2fv([.5, 0.])
    glVertex2fv([.5, .5])
    glEnd()

def main():
    # Initialize the library
    if not glfw.init():
        return
    # Create a windowed mode window and its OpenGL context
    window = glfw.create_window(480,480,"2020049061", None,None)
    if not window:
        glfw.terminate()
        return

    # Making the animation
    glfw.make_context_current(window)
    glfw.swap_interval(1)

    # Loop until the user closes the window
    while not glfw.window_should_close(window):
        
        # Poll events
        glfw.poll_events()
    
        render()

        # Swap front and back buffers
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    main()
