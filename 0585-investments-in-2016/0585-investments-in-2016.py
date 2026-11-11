import pandas as pd

def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
    
    df=insurance.copy()
    
    condition1=df.groupby("tiv_2015")["pid"].transform("count")>1

    condition2=df.groupby(["lat","lon"])["pid"].transform("count")==1

    result= df[condition1 & condition2]

    return pd.DataFrame({
        "tiv_2016":[round(result["tiv_2016"].sum(),2)]
    })
