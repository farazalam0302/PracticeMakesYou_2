nShares = 14975
RealisedCPwithTax = 121
AvgCostonPortal = 268.25
print("CurrPricePershare,ActualInvestedAmount,VirtualInvestedAmount,CurrentPortfolioVAlue,tax,profit_loss,PAT ")
for i in range(230, 1000, 1):
    currPricePerShare = i
    ActualinvestedAmount = nShares*RealisedCPwithTax
    VirtualInvestedAmount = nShares*AvgCostonPortal
    CurrentPortfolioVAlue = nShares*currPricePerShare
    tax = 0
    if CurrentPortfolioVAlue - VirtualInvestedAmount > 0:
        tax = (CurrentPortfolioVAlue - VirtualInvestedAmount) * 20/100.0
        pass
    profit_loss = CurrentPortfolioVAlue-ActualinvestedAmount
    profit_loss_after_tax = profit_loss-tax
    # currPricePerShare = 121

    print(str(currPricePerShare)+", "+str(ActualinvestedAmount) + ", " + str(VirtualInvestedAmount) +
          ", " + str(CurrentPortfolioVAlue) + ", " + str(tax) + ", " + str(profit_loss) + ", " + str(profit_loss_after_tax))
    # print("CurrentPortfolioVAlue = ", CurrentPortfolioVAlue)
    # print("tax = ", tax)
    # print("profit_loss = ", profit_loss)
    # print("PAT = ", PAT)
