
import turtle
import time
import random

retraso = 0.1
Score = 0
High_Score = 0

#Definimos el entorno de nuestro juego.

s = turtle.Screen()
s.setup(650,650)
s.bgcolor("orange")
s.title('Proyecto: "El juego de la Serpiente"')
s.tracer(0)

#A continuación daremos algunas cualidades a nuestro personaje.

serpiente = turtle.Turtle()
serpiente.speed(0)
serpiente.shape("square")
serpiente.penup()
serpiente.goto(0,0)
serpiente.direction = 'stop'
serpiente.color("green","black")

#Creamos nuestro objeto "comida" y la lista "cuerpo"(El cual especificaremos más adelante).

comida = turtle.Turtle()
comida.shape("circle")
comida.color("red","brown")
comida.penup()
comida.goto(0,100)
comida.speed(0)

cuerpo = []

#Especifícamos los detalles del marcador, tambien llamados en ingles "score, high score"

texto = turtle.Turtle()
texto.speed(0)
texto.color("black")
texto.penup()
texto.hideturtle()
texto.goto(0, 250)
texto.write("Score: 0\t\tHigh Score: 0", align = "center", font = ("arial", 20, "normal"))

#Definimos los métodos de DIRECCIÓN para nuestro objeto (no confundir con movimiento).

def arriba():
    if serpiente.direction != "down":
        serpiente.direction = "up"

def abajo():
    if serpiente.direction != "up":
        serpiente.direction = "down"

def izquierda():
    if serpiente.direction != "right":
        serpiente.direction = "left"

def derecha():
    if serpiente.direction != "left":
        serpiente.direction = "right"

#Ahora si, definimos los atributos del método "movimiento".

def movimiento():
    if serpiente.direction == 'up':
        y = serpiente.ycor()
        serpiente.sety(y + 20)

    if serpiente.direction == 'down':
        y = serpiente.ycor()
        serpiente.sety(y - 20)

    if serpiente.direction == 'left':
        x = serpiente.xcor()
        serpiente.setx(x - 20)

    if serpiente.direction == 'right':
        x = serpiente.xcor()
        serpiente.setx(x + 20)

    

#Mandamos a "escuchar" a la consola cuando presionamos las siguientes teclas y las definimos.

s.listen()
turtle.onkeypress(arriba, "Up")
turtle.onkeypress(abajo, "Down")
turtle.onkeypress(izquierda, "Left")
turtle.onkeypress(derecha, "Right")

        
while True:

    s.update()

    #Aquí especifícamos lo que pasará cuando la serpiente toque la pantalla. El juego la llevará a su punto inicial sin su cuerpo completo (fijarse en la diferencia cuando la serpiente se toca a ella misma).

    if serpiente.xcor() > 300 or serpiente.xcor() < -300 or serpiente.ycor() > 300 or serpiente.ycor() < -300:
        time.sleep(1)
        for i in cuerpo:
            i.hideturtle()
            i.clear()
        serpiente.home()
        serpiente.direction = 'stop'
        

        #Aquí especificamos que el marcador será 0 cuando la serpiente toque la pantalla.

        Score = 0
        retraso = 0.1
        texto.clear()
        texto.write("Score:{}\t\tHigh Score:{}".format(Score,High_Score), align = "center", font = ("verdana", 20, "normal"))


    #Le decimos al programa que cuando la serpiente toque la comida, esta aparezca en un punto random nuevamente.

    if serpiente.distance(comida) < 20:
        x = random.randint(-250, 250)
        y =random.randint(-250, 250)
        comida.goto(x,y)

        #Especificamos los atributos del cuerpo de la serpiente.

        nuevo_cuerpo = turtle.Turtle()
        nuevo_cuerpo.speed(0)
        nuevo_cuerpo.shape("circle")
        nuevo_cuerpo.color("black","green")
        nuevo_cuerpo.penup()
        cuerpo.append(nuevo_cuerpo)

        #Imprimimos por pantalla los puntaje los Marcadores de puntos y sus detalles.

        retraso -= 0.001
        Score += 10

        if Score > High_Score:
            High_Score = Score
        
        texto.clear()
        texto.write("Score:{}\t\tHigh Score:{}".format(Score,High_Score), align = "center", font = ("font", 20, "normal"))

    #Aquí especificamos el incremento de la serpiente a medida que vaya comiendo.

    total = len(cuerpo)
    for index in range(total -1,0,-1):
        x = cuerpo[index-1].xcor()
        y = cuerpo[index-1].ycor()
        cuerpo[index].goto(x,y)

    if total > 0:
        x = serpiente.xcor()
        y = serpiente.ycor()
        cuerpo[0].goto(x,y)
       
    movimiento()

    #Aquí le decimos al programa que cuando la serpiente se toque a ella misma, aparezca en el lugar de origen sin el cuerpo incrementado.

    for i in cuerpo:
        if i.distance(serpiente) < 20:
            for i in cuerpo:
                i.clear()
                i.hideturtle()
            time.sleep(1)
            serpiente.hideturtle()
            serpiente.home()
            serpiente.showturtle()
            serpiente.direction = "stop"
            cuerpo.clear()

    #Aquí le decimos al juego que cuando la serpiente se toque a ella misma el Marcador vuelva a ser 0.
         
            Score = 0
            retraso = 0.1

            texto.clear()
            texto.write("Score:{}\t\tHigh Score:{}".format(Score,High_Score), align = "center", font = ("arial", 20, "normal"))
    time.sleep(retraso)

        
turtle.done()
