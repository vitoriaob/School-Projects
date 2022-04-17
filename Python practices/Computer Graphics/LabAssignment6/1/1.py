import glfw
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np

def render():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glEnable(GL_DEPTH_TEST)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE)
    glLoadIdentity()   
    
    myOrtho(-5,5, -5,5, -8,8)
    myLookAt(np.array([5,3,5]), np.array([1,1,-1]), np.array([0,1,0]))
    
    drawFrame()
    glColor3ub(255,255,255)
    drawCubeArray()

def myOrtho(left, right, bottom, top, near, far):
    delta = right-left
    beta = right+left
    delta2 = top-bottom
    beta2 = top+bottom
    delta3 = near-far
    beta3 = near+far
    Transform = np.array([[2/delta, 0, 0, (-beta)/delta],
                         [0, 2/delta2, 0, (-beta2)/delta2],
                         [0,0, 2/delta3, (-beta3)/delta3],
                         [0,0,0,1]])
    Transposed = Transform.T
    glMultMatrixf(Transposed)

def myLookAt(eye, at, up):
    delta = eye-at
    forw = delta / np.sqrt(np.dot(delta,delta))

    side = np.cross(up, forw)
    side = side/ np.sqrt(np.dot(side,side))

    up_proj = np.cross(forw,side)

    pos = [np.dot(-eye, side), np.dot(-eye/2, up), np.dot(-eye, forw)]

    Transform = np.array([np.append(side, pos[0]), np.append(up_proj, pos[1]), np.append(forw, pos[2]), np.array([0.0,0.0,0.0,1.0])])
    Transpose = Transform.T
    glMultMatrixf(Transpose)
    

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
    if not glfw.init():
        return
    window = glfw.create_window(480,480,'2020049061', None,None)
    if not window:
        glfw.terminate()
        return
    glfw.make_context_current(window)
    #glfw.set_key_callback(window, key_callback)

    while not glfw.window_should_close(window):
        glfw.poll_events()
        render()
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    main()
