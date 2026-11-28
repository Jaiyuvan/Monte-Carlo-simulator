import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv("data/csv_export.csv",header=None)

for _,path in data.iterrows():
    plt.plot(path)

plt.xlabel("Trading Day")
plt.ylabel("Stock Price")
plt.title("Monte Carlo Simulated Price Paths")
plt.grid(True)

plt.show()