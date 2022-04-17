import glfw
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np


def render(commands):
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()

    #draw coordinates
    glBegin(GL_LINES)
    glColor3ub(255,0,0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([1.,0.]))
    glColor3ub(0,255,0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([0.,1.]))
    glEnd()

    glColor3ub(255,255,255)
    for argument in commands:
        if(argument == '1'):
            glLoadIdentity()
            commands = []
        elif(argument == 'Q'):
            glTranslate(-0.1,0.,0.)
        elif(argument == 'E'):
            glTranslate(0.1,0.,0.)
        elif(argument == 'A'):
            glRotate(10, 0., 0., 1.)
        elif(argument == 'D'):
            glRotate(-10, 0., 0., 1.)
        
    drawTriangle()

def drawTriangle():
    glBegin(GL_TRIANGLES)
    glVertex2fv(np.array([0.,.5]))
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([.5,0.]))
    glEnd()

commands = []
def key_callback(window, key, scancode, action, mods):
   
    if action == glfw.PRESS or action == glfw.REPEAT:
        if key == glfw.KEY_1:
            commands.append('1')
        elif key == glfw.KEY_Q:
            commands.append('Q')
        elif key == glfw.KEY_E:
            commands.append('E')
        elif key == glfw.KEY_A:
            commands.append('A')
        elif key == glfw.KEY_D:
            commands.append('D')
def main():
    # Initialize the library
    if not glfw.init():
        return
    # Create a windowed mode window and its OpenGL context
    window = glfw.create_window(480,480,"2020049061", None,None)
    if not window:
        glfw.terminate()
        return
    
    glfw.make_context_current(window)
    glfw.set_key_callback(window, key_callback)
    
    # Loop until the user closes the window
    while not glfw.window_should_close(window):
         
        # Poll events
        glfw.poll_events()
        render(commands)    
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    main()
