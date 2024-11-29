corpus = 3500000
years = 15

monthlyWithdraw = 0
growthRate = 20/100.0
print("year,Corpus")
for i in range(1, years, 1):
    corpus = (corpus-monthlyWithdraw*12)*(1+growthRate)

    print(str(i), str(corpus))
