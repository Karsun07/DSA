import pandas as pd

def find_customer_referee(customer: pd.DataFrame) -> pd.DataFrame:
    df=customer
    cnd=(df["referee_id"]!=2) | (df["referee_id"].isna())
    return df[cnd][["name"]]
    