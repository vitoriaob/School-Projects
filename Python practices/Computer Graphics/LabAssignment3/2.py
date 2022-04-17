import numpy as np
import glfw
from OpenGL.GL import *




def render(T):
    glClear(GL_COLOR_BUFFER_BIT)
    glLoadIdentity()
    
    #draw coordinate
    glBegin(GL_LINES)
    glColor3ub(255, 0, 0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([1.,0.]))
    glColor3ub(0, 255, 0)
    glVertex2fv(np.array([0.,0.]))
    glVertex2fv(np.array([0.,1.]))
    glEnd()
    
    #draw triangle
    glBegin(GL_TRIANGLES)
    glColor3ub(255, 255, 255)
    glVertex2fv((T @ np.array([0.,.5, 1.]))[:-1])
    glVertex2fv((T @ np.array([0.,0.,1.]))[:-1])
    glVertex2fv((T @ np.array([.5,0.,1.]))[:-1])
    glEnd()
    
def dict(index):
        #T1 = Scale by 0.9 times in x
        T1 = np.array ([[0.9, 0., 0.], [0., 1., 0.], [0., 0., 0.9]])
        
        #T2 = Scale by 1.1 times in x
        T2 = np.array ([[1.1, 0., 0.], [0., 1., 0.], [0., 0., 1.1]])
        
        #T3 = Rotate by 10 degrees counterclockwise
        t = np.radians(10)
        T3 = np.array([[np.cos(t), -np.sin(t), 0.], [np.sin(t), np.cos(t), 0.], [0., 0., 1.]])
        
        #T4 = Rotate by 10 degrees clockwise
        T4 = np.array([[np.cos(t), np.sin(t), 0.], [-np.sin(t), np.cos(t), 0.], [0., 0., 1.]])
        
        #T5 = Shear by a factor of -0.1 in x direction
        T5 = np.array ([[1.,np.sin(-0.1), 0.], [ 0., 1,  0.], [0., 0., 1.]])
        
        #T6 = Shear by a factor of 0.1 in x direction
        T6 = np.array ([[1.,np.sin(0.1),0.], [0., 1, 0.], [0., 0., 1.]])
        
        #T7 = Reflection across x axis
        T7 = np.array ([[1., 0., 0.], [0., -1., 0.], [0., 0., 1.]])
        
        #T8 = Reset the triangle with identity matrix
        T8 = np.identity(3)
        
        options = {'W': T1, 'E': T2, 'S': T3 , 'D': T4, 'X':T5,'C': T6, 'R': T7, '1':T8}

        return(options[index])
    


def main(gComposedM):
    # Initialize the library
    if not glfw.init():
        return
    # Create a windowed mode window and its OpenGL context
    window = glfw.create_window(480,480,"2020049061", None,None)
    if not window:
        glfw.terminate()
        return
    
    glfw.make_context_current(window)
    glfw.swap_interval(1)
    
    # Loop until the user closes the window
    while not glfw.window_should_close(window):
         
        # Poll events
        glfw.poll_events()
        
        index = input("Input:")
        
        if(index == '1'):
            gComposedM = np.identity(3)
            
        else:
            opt = dict(index)
            gComposedM = opt @ gComposedM
        
        render(gComposedM)
        # Swap front and back buffers
        glfw.swap_buffers(window)

    glfw.terminate()

if __name__ == "__main__":
    gComposedM = np.identity(3)
    print("Press one to start")
    main(gComposedM)
