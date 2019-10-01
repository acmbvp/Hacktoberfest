# -*- coding: utf-8 -*-
"""
Created on Wed Oct 10 11:40:53 2018

@author: Anjali
"""

import cv2
#import numpy as np
def empty_func():
    pass

def main():
    windowName = "Transition Demo"
    cv2.namedWindow(windowName)
    
    path = "F:\\opencv\\misc\\"
    img_path1 = path + "4.2.01.tiff"
    img_path2 = path + "4.2.03.tiff"

    
    img1 = cv2.imread(img_path1)
    img2 = cv2.imread(img_path2)


    output = cv2.addWeighted(img1, 0.5, img2, 0.5, 0)    
    cv2.createTrackbar("alpha", windowName, 0, 100000, empty_func)
    
    while(True):
        
        cv2.imshow(windowName, output)
        
        if cv2.waitKey(1) == 27:
            break
        
        alpha = cv2.getTrackbarPos('alpha', windowName) / 100000
        beta = 1 - alpha
        
        output = cv2.addWeighted(img1, alpha, img2, beta, 0)
        
        print (alpha, beta)
        
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()
