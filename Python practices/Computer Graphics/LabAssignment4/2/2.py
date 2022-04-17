import glfw
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np

def render(M):

    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    
    #draw coordinates
    glBegin(GL_LINES)
    glColor3ub(255, 0, 0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([1.,0.]))
    glColor3ub(0, 255, 0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([0.,1.]))
    glEnd()

    glColor3ub(255, 255, 255)

    #draw point p
    glBegin(GL_POINTS)
    glVertex2fv((M @ np.array([1., 0., 0.]))[:-1])
    glEnd()

    glBegin(GL_LINES)
    glVertex2fv((M @ np.array([0., 0., 0.]))[:-1])
    glVertex2fv((M @ np.array([.5, 0., 0.]))[:-1])
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
        t = glfw.get_time()
        #Rotation
        R = np.array([[np.cos(t), -np.sin(t), 0.], [np.sin(t), np.cos(t), 0.], [0., 0., 1.]])
        #Translation
        M = np.array ([[1., 0., 1.], [0., 1., 1.], [0., 0., 1.]])

        T = R @ M
    
        render(T)

        # Swap front and back buffers
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    main()
