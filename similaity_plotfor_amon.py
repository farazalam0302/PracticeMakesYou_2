import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import matplotlib as mpl

# [MS and ST,CA,DS,MAM,MM,RS,SNMF,SS,SCV,WDL(SAB)],
sim_matrix = [
    [1.00, 0.00, 0.20, 0.27, 0.13, 0.00, 0.13, 0.53, 0.20, 0.00],
    [0.00, 1.00, 0.56, 0.39, 0.11, 0.14, 0.00, 0.22, 0.06, 0.00],
    [0.20, 0.56, 1.00, 0.26, 0.19, 0.29, 0.06, 0.52, 0.49, 0.00],
    [0.27, 0.39, 0.26, 1.00, 0.32, 0.29, 0.19, 0.42, 0.51, 0.43],
    [0.13, 0.11, 0.19, 0.32, 1.00, 0.07, 0.06, 0.32, 0.03, 0.00],
    [0.00, 0.14, 0.29, 0.29, 0.07, 1.00, 0.00, 0.50, 0.14, 0.14],
    [0.13, 0.00, 0.06, 0.19, 0.06, 0.00, 1.00, 0.19, 0.06, 0.00],
    [0.53, 0.22, 0.52, 0.42, 0.32, 0.50, 0.19, 1.00, 0.77, 0.29],
    [0.20, 0.06, 0.49, 0.51, 0.03, 0.14, 0.06, 0.77, 1.00, 0.14],
    [0.00, 0.00, 0.00, 0.43, 0.00, 0.14, 0.00, 0.29, 0.14, 1.00],
]

# plt.imshow(sim_matrix)
# plt.colorbar()
# plt.show()


vegTypesX = ["MS and ST", "CA", "DS", "MAM",
             "MM", "RS", "SNMF", "SS", "SCV", "WDL"]

vegTypesY = ["Meadow steppe & short turfs", "Cultivated area", "Desert steppe", "Mixed herbaceous",
             "Marsh meadow", "Riverine scrub", "Sub-nival mix-formations", "Scrub steppe", "Scree vegetation", "Woodland"]

# harvest = np.array([[0.8, 2.4, 2.5, 3.9, 0.0, 4.0, 0.0],
#                    [2.4, 0.0, 4.0, 1.0, 2.7, 0.0, 0.0],
#                    [1.1, 2.4, 0.8, 4.3, 1.9, 4.4, 0.0],
#                    [0.6, 0.0, 0.3, 0.0, 3.1, 0.0, 0.0],
#                    [0.7, 1.7, 0.6, 2.6, 2.2, 6.2, 0.0],
#                    [1.3, 1.2, 0.0, 0.0, 0.0, 3.2, 5.1],
#                    [0.1, 2.0, 0.0, 1.4, 0.0, 1.9, 6.3]])

harvest = np.array(sim_matrix)
fig, ax = plt.subplots()
im = ax.imshow(harvest)
plt.colorbar(im)
# Show all ticks and label them with the respective list entries
ax.set_xticks(np.arange(len(vegTypesX)), labels=vegTypesX)
ax.set_yticks(np.arange(len(vegTypesY)), labels=vegTypesY)

# Rotate the tick labels and set their alignment.
plt.setp(ax.get_xticklabels(), rotation=45, ha="right",
         rotation_mode="anchor")

# Loop over data dimensions and create text annotations.
for i in range(len(vegTypesX)):
    for j in range(len(vegTypesY)):
        text = ax.text(j, i, harvest[i, j],
                       ha="center", va="center", color="w")

ax.set_title("Pairwise Similarity")
fig.tight_layout()
plt.show()
