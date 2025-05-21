import seaborn as sns
import matplotlib.pyplot as plt

tips = sns.load_dataset("tips")
sns.set_style("whitegrid")
sns.scatterplot(x="total_bill",y="tip",data=tips)
sns.despine()
plt.show()