import numpy as np
import matplotlib.pyplot as plt


# creating the dataset
#data = {'Dance':300, 'Music':400, 'Painting':100,
#		'Playing Sports':500}
hobbies = ['Dance', 'Music', 'Painting',
		'Playing Sports']
values = [300, 400, 100, 500]

fig = plt.figure(figsize = (10, 5))

# creating the bar plot
#plt.bar(hobbies, values, color ='black',
#		width = 0.4)
plt.plot(hobbies,values)
plt.xlabel("Hobbies")
plt.ylabel("Number of People")
plt.title("Favourite Hobby")
plt.savefig('hobbies_chart.jpg')

plt.show()
