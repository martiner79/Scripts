import turtle
import random

s = turtle.Screen()
s.title("Primer Proyecto")
s.bgcolor("gray")

jugador1 = turtle.Turtle()
jugador2 = turtle.Turtle()

jugador1.hideturtle()
jugador1.shape("turtle")
jugador1.color("green","green")
jugador1.shapesize(2,2,2)
jugador1.pensize(3)

jugador2.hideturtle()
jugador2.shape("turtle")
jugador2.color("blue","blue")
jugador2.shapesize(2,2,2)
jugador2.pensize(3)



jugador1.penup()
jugador1.goto(200,200)
jugador1.pendown()
jugador1.circle(40)

jugador1.penup()
jugador1.goto(-200,225)
jugador1.showturtle()

jugador2.penup()
jugador2.goto(200,-200)
jugador2.pendown()
jugador2.circle(40)

jugador2.penup()
jugador2.goto(-200,-175)
jugador2.showturtle()

dado = (1,2,3,4,5,6)

for i in range(10):
    if jugador1.pos() >= (200,200):
        print("La tortuga verde ha ganado")
    elif jugador2.pos() >= (200,-200):
        print("La tortuga azul ha ganado")
    else:
        print("Error en el juego")
    





turtle.done()
