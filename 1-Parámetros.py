import turtle
import random

s = turtle.Screen()
s.title("Primer Proyecto")

jugador1 = turtle.Turtle()
jugador2 = turtle.Turtle()

jugador1.shape("turtle")
jugador1.color("green","green")

jugador2.shape("turtle")
jugador2.color("blue","blue")

jugador1.goto(-200,200)
jugador2.goto(-200,0)


turtle.done()
