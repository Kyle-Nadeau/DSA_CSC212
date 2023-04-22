# DSA Project - Nadeau

import tkinter as tk
from tkinter import filedialog
from PIL import Image, ImageTk, ImageGrab  ##pillow library for python


class ImageGrab:
    pass


class DrawingApp:

    def __init__(self, master):
        self.master = master
        self.master.title('Nadeau - DSA')

        #color palette
        self.color_palette = tk.Frame(self.master)
        self.color_palette.pack()
        
        #choose which colors to add
        self.colors = ['#000000', '#ff0000', '#ffa500', '#ffd000', '#00ff00', '#00ffff', '#0077ff', '#ff00ff', '#ff69b4']
        self.selected_color = tk.StringVar()
        self.selected_color.set(self.colors[0])

        for color in self.colors:
            button = tk.Button(self.color_palette, bg=color, width=3, height=1, highlightthickness=0, command=lambda c=color: self.select_color(c))
            button.pack(side='left', padx=2)

        #create external canvas
        self.canvas = tk.Canvas(self.master, width=500, height=500, bg='white')
        self.canvas.pack()

        self.canvas.bind('<Button-1>', self.on_canvas_click)
        self.canvas.bind('<B1-Motion>', self.on_canvas_drag)

        #image for button
        self.upload_button = tk.Button(self.master, text='Upload Image', command=self.upload_image)
        self.upload_button.pack()
        
        self.save_button = tk.Button(self.master, text='Save', command=self.save_canvas)
        self.save_button.pack(side='right', padx=5)

        self.image = None
        self.image_tk = None

    def select_color(self, color):
        self.selected_color.set(color)

    def on_canvas_click(self, event):
        self.draw(event)

    def on_canvas_drag(self, event):
        self.draw(event)

    def draw(self, event):
        x, y = event.x, event.y
        color = self.selected_color.get()
        self.canvas.create_oval(x-2, y-2, x+2, y+2, fill=color, outline='')
    

    def upload_image(self):
        file_path = filedialog.askopenfilename(filetypes=[('PNG files', '*.png')])
        if file_path:
            image = Image.open(file_path)
            self.image = image
            self.image_tk = ImageTk.PhotoImage(image)
            self.canvas.create_image(0, 0, anchor='nw', image=self.image_tk)
            
    def save_canvas(self):
        file_path = filedialog.asksaveasfilename(defaultextension='.png')
        if file_path:
            x = self.master.winfo_rootx() + self.canvas.winfo_x()
            y = self.master.winfo_rooty() + self.canvas.winfo_y()
            x1 = x + self.canvas.winfo_width()
            y1 = y + self.canvas.winfo_height()
            ImageGrab.grab().crop((x, y, x1, y1)).save(file_path)

    def run(self):
        self.master.mainloop()

root = tk.Tk()
app = DrawingApp(root)
app.run()







