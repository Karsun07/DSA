import pandas as pd

def find_customers(visits: pd.DataFrame, transactions: pd.DataFrame) -> pd.DataFrame:
    df1 = visits
    df2 = transactions

    df3 = df1.merge(df2, on="visit_id", how="left")
    df3 = df3[df3["transaction_id"].isna()]

    df3 = df3.groupby("customer_id").size().reset_index(name="count_no_trans")

    return df3