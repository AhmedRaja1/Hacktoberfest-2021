import pandas as pd
import numpy as np
from pandas.core.frame import DataFrame

data = pd.read_excel('/Users/sudaisalam/Downloads/KPMG_VI_New_raw_data_update_final.xlsx', 3)
print(data.head())