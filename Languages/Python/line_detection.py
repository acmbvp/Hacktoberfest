# -*- coding: utf-8 -*-
"""
Created on Thu Oct 18 02:13:33 2018

@author: Anjali
"""

import cv2
import numpy as np

def main():
    cap = cv2.VideoCapture(0)
    
    windowName = "liveCamera"
    cv2.namedWindow(windowName)
    
    if cap.isOpened:
        ret , frame = cap.read()
    else:
        ret = False
    
    while ret :
        
        ret, frame = cap.read()
        grey = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        canny = cv2.Canny(grey, 100, 200, L2gradient = True)
        
        lines = cv2.HoughLines(canny, 1, np.pi/180, 50)
        
        if lines is not None:
            for rho, theta in lines[0]:
                a = np.cos(theta)
                b = np.sin(theta)
                x0 = a*rho
                y0 = b*rho
                
                x1 = int(x0 + 1000*(-b))
                y1 = int(y0 + 1000*(a))
                x2 = int(x0 - 1000*(-b))
                y2 = int(y0 - 1000*(a))
        
                cv2.line(frame, (x1,y1), (x2, y2), (0,255, 0), 2)   
                
        cv2.imshow(windowName, frame)
            
        if cv2.waitKey(1) == 27:
            break
        
    cap.release()
    cv2.destroyAllWindows()
    
if __name__ == "__main__":
    main()
