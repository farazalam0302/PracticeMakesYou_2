import pandas as pd
import numpy as nm

s1 = pd.Series(["Faraz", "Amar", "Manto"], index=[3, 4, 5])
s2 = pd.Series(["IP", "EVS", "Maths"], index=[3, 4, 5])
s3 = pd.Series([100, 88, 90], index=[3, 4, 5])

xiiA = {"Name": s1, "Subjects": s2, "Marks": s3}
df = pd.DataFrame(xiiA)
print(df)
