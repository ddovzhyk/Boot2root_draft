from turtle import *
# used library turtle to draw
import turtle    
import re

screen = turtle.Screen()
screen.setup(640, 640)

def paintForward(spaces):
    turtle.forward(spaces)

def paintBackward(spaces):
    turtle.backward(spaces)

def paintLeft(degrees):
    turtle.left(degrees)

def paintRight(degrees):
    turtle.right(degrees)

# handle input
for command in open('turtle'):
    argument = re.search(r'\d+', command)
    if argument:
        argument = int(argument.group(0))
        if "gauche" in command:
            paintLeft(argument)
        elif "Avance" in command:
            paintForward(argument)
        elif "droite" in command:
            paintRight(argument)
        elif "Recule" in command:
            paintBackward(argument)
        else:
            pass
            
turtle.exitonclick()