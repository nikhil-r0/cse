import matplotlib.pyplot as plt

x = [1.5,2.5,5.6,3.4,3.6,4.4,4.5,4.6,2,3.5,4,5.5]
y = ["Nikhil","Hello","Nice","To","Meet"]
b = [1,2,3,4,5]
plt.plot(x,marker = "x",linewidth = "2", linestyle = '-',label = "Random Shit")
plt.xlabel("X-Axis")
plt.ylabel("Y-Axis")
plt.title("Lab Demo")
plt.legend()
plt.show()