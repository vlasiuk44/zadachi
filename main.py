import turtle
from tkinter import *
from tkinter import ttk


def create(iters, axiom, rules):
    start_string = axiom
    if iters == 0:
        return axiom
    end_string = ""
    for _ in range(iters):
        end_string = "".join(rules[i] if i in rules else i for i in start_string)
        start_string = end_string

    return end_string


def draw_sys(t, instructions, angle, distance):
    for cmd in instructions:
        if cmd == 'F':
            t.forward(distance)
        elif cmd == '+':
            t.right(angle)
        elif cmd == '-':
            t.left(angle)


def launch(length=4, size=2, y_offset=0,
           x_offset=0, offset_angle=0, width=1000, height=1000):
    figures = {
        "Koch's Snowflake": {
            "axiom": "F--F--F",
            "rules": {"F": "F+F--F+F"},
            "iterations": 4,
            "angle": 60
        },
        "Crystal": {
            "axiom": "F+F+F+F",
            "rules": {"F": "FF+F++F+F"},
            "iterations": 3,
            "angle": 90
        },
        "Vicek's Fractal": {
            "axiom": "F-F-F-F",
            "rules": {"F": "F-F+F+F-F"},
            "iterations": 4,
            "angle": 90,
        },
        "Sierpinski Carpet": {
            "axiom": "YF",
            "rules": {"X": "YF+XF+Y", "Y": "XF-YF-X"},
            "iterations": 6,
            "angle": 60
        },
    }

    colors = {
        "Black": "black",
        "Red": "red",
        "Green": "green",
        "Blue": "blue"
    }

    iterations = figures[figure.get()]["iterations"]
    axiom = figures[figure.get()]["axiom"]
    rules = figures[figure.get()]["rules"]
    angle = figures[figure.get()]["angle"]

    inst = create(iterations, axiom, rules)

    wn = turtle.Screen()
    wn.clear()

    t = turtle.Turtle()
    t.hideturtle()
    wn.setup(width, height)
    t.pencolor(colors[color_box.get()])
    t.up()
    t.backward(-x_offset)
    t.left(90)
    t.backward(-y_offset)
    t.left(offset_angle)
    t.down()
    t.speed(0)
    t.pensize(size)

    draw_sys(t, inst, angle, length)


window = Tk()
window.geometry("300x100")

figure_lbl = Label(window, text="Fractal: ")
figure_lbl.grid(column=0, row=0)
figure = ttk.Combobox(window)
figure["values"] = ("Koch's Snowflake", "Crystal", "Vicek's Fractal", "Sierpinski Carpet")
figure.current(0)
figure.grid(column=1, row=0)

color_lbl = Label(window, text="Color: ")
color_lbl.grid(column=0, row=1)
color_box = ttk.Combobox(window)
color_box["values"] = ("Black", "Red", "Green", "Blue")
color_box.current(0)
color_box.grid(column=1, row=1)

space_lbl = Label(window, text="")
space_lbl.grid(column=0, row=3)

btn = Button(window, text="Launch", command=launch)
btn.grid(column=1, row=4)

window.protocol("WM_DELETE_WINDOW", window.destroy)
window.mainloop()