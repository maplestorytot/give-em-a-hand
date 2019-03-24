import cv2
import numpy as np
import serial
import time
import math
ser = serial.Serial('COM4', 9600, timeout=0)

mouth_cascade = cv2.CascadeClassifier('./haarcascade_mcs_mouth.xml')

if mouth_cascade.empty():
  raise IOError('Unable to load the mouth cascade classifier xml file')

cap = cv2.VideoCapture(0)
ds_factor = 0.5


sentCommand=0
counter=32
while True:
    incomingdata=ser.readline()
    # print('from arduino', incomingdata)
    ret, frame = cap.read()
    frame = cv2.resize(frame, None, fx=ds_factor, fy=ds_factor, interpolation=cv2.INTER_AREA)
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    mouth_rects = mouth_cascade.detectMultiScale(gray, 1.7, 11)
    for (x,y,w,h) in mouth_rects:
        y = int(y - 0.15*h)
        truex=math.fabs(mouth_rects[0][0]-255)
        truey=math.fabs(mouth_rects[0][1]-255)
        cv2.rectangle(frame, (x,y), (x+w,y+h), (0,255,0), 3)
        # if sentCommand!=1:
        print('x',truex)
        print('y',truey)
        absoluteDistance=pow(pow(truex,2)+pow(truey,2),1/2)
        # print(absoluteDistance)
        angle=180*math.atan(truey/truex)/math.pi
        print('angle in degrees: ',angle)
        sentCommand=1
        ser.write(bytes([int(angle)]))
        # print(bytes([int(angle)]))
        time.sleep(0.5)



        break

    cv2.imshow('Mouth Detector', frame)
    
    c = cv2.waitKey(1)
    if c == 27:
        break


cap.release()
cv2.destroyAllWindows()