from bokeh.plotting import figure, output_file, show
from bokeh.models import Label

output_file("output.html")
fig = figure(title="Demo",x_axis_label= "X", y_axis_label = "y")
x = [1,2,3,4,5]
y = [1,2,3,4,5]
fig.wedge(x,y,radius = 0.5,color="black", start_angle = 0.4, end_angle = 4.8)
annotation = Label(text = "impt", x =1, y =3)
fig.add_layout(annotation)
show(fig)
