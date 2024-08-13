investedAmt = 200000
probableGainPerDay = 1/100
numberOfDaysHold = 18*30

# finalAmt = investedAmt * (1+probableGainPerDay)**numberOfDaysHold
finalAmt = investedAmt * (1+20/100)**2 * (1+10/100)**2 * (1+5/100)**5 
print("finalAmount = " + str(finalAmt))
