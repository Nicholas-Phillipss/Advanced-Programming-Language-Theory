import random 
import math 
import turtle 
from turtle import *
 
def montePi(numDarts):    
    inCircle = 0       
    for i in range(numDarts): 
        x = random.random() 
        y = random.random() 
        distance = math.sqrt(x**2 + y**2)   
  
        if distance <= 1: 
            inCircle = inCircle + 1 
 
    pi = inCircle / numDarts * 4 
    return pi 
 
def showMontePi(numDarts): 
    wn = turtle.Screen() 
    drawingT = turtle.Turtle() 
    
    wn.setworldcoordinates(-2, -2, 2, 2) 
    
    drawingT.up() 
    drawingT.goto(-1, 0) 
    drawingT.down() 
    drawingT.goto(1, 0) 
    
    drawingT.up() 
    drawingT.goto(0, 1) 
    drawingT.down() 
    drawingT.goto(0, -1) 
    
    inCircle = 0 
    drawingT.up() 
 
    for i in range(numDarts): 
        x = random.random() 
        y = random.random() 
 
        distance = math.sqrt(x**2 + y**2) 
 
        drawingT.goto(x, y) 
        
        if distance <= 1: 
            inCircle = inCircle + 1 
            drawingT.color("blue") 
        else: 
            drawingT.color("red") 
            
        drawingT.dot() 
 
    pi = inCircle / numDarts * 4 
    wn.exitonclick()     
    return pi 

#Allows for 100 differnet points to be placed on the python graph
y = showMontePi(25)

print(y)