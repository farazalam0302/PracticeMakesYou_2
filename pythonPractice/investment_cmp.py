moschip_nShares = 14975
moschip_currentPrice = 225
MatureCapital = moschip_currentPrice*moschip_nShares
d = {"tcsChange": 10.07, "olectraChange": 16.19,
     "dynaMaticChange": 15.92, "olaElectricChange": 36.30, "SwiggyChange": 30.52}

ll = ["tcsChange", "olectraChange", "dynaMaticChange",
      "olaElectricChange", "SwiggyChange"]


for company in ll:
    print(" In " + str(company.split('C')[0].upper()))
    mc = MatureCapital * (1+d[company]/100.0 * 0.8)
    print("    Mature capital will be " + str(mc))
    print("    P&L will be " + str(mc-moschip_nShares*121.5))
