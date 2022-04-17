import glfw
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np

def render():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    #glEnable(GL_DEPTH_TEST)
    glLoadIdentity()
    
    
    gluPerspective(45,1,1,10)
    #Replace this gluLookAt(3,3,3, 0,0,0, 0,1,0)

    #rotate 35.3 over x
    glRotatef(35.3, 1, 0, 0)
    #rotate -45 over y
    glRotatef(-45, 0, 1, 0)
    #translation to center w.r.t. camera position
    glTranslatef(-3, -3, -3)   
    
    drawFrame()
    glColor3ub(255,255,255)
    drawCubeArray()

def drawUnitCube():
    glBegin(GL_LINES)
    vertices= ((0.5, -0.5, -0.5),(0.5, 0.5, -0.5),(-0.5, 0.5, -0.5),(-0.5, -0.5, -0.5),(0.5, -0.5, 0.5),(0.5, 0.5, 0.5),(-0.5, -0.5, 0.5),(-0.5, 0.5, 0.5))
    edges = ((0,1),(0,3),(0,4),(2,1),(2,3),(2,7),(6,3),(6,4),(6,7),(5,1),(5,4),(5,7))
    for e in edges:
        for vertex in e:
            glVertex3fv(vertices[vertex])
    glEnd()

def drawCubeArray():
    for i in range(5):
        for j in range(5):
            for k in range(5):
                glPushMatrix()
                glTranslate(i,j,-k-1)
                glScalef(.5,.5,.5)
                drawUnitCube()
                glPopMatrix()

def drawFrame():
    glBegin(GL_LINES)
    glColor3ub(255,0,0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([1.,0.,0.]))
    glColor3ub(0,255,0)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,1.,0.]))
    glColor3ub(0,0, 255)
    glVertex3fv(np.array([0.,0.,0.]))
    glVertex3fv(np.array([0.,0.,1.]))
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
