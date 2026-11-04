import pandas as pd

def monthly_transactions(transactions: pd.DataFrame) -> pd.DataFrame:

    df = transactions

    df["month"] = pd.to_datetime(df["trans_date"]).dt.strftime("%Y-%m")

    df["trans_count"] = 1
    df["approved_count"] = 0

    df.loc[df["state"] == "approved", "approved_count"] = 1

    df["trans_total_amount"] = df["amount"]
    df["approved_total_amount"] = 0

    df.loc[df["state"] == "approved", "approved_total_amount"] = df["amount"]

    df = df.groupby(
        ["month", "country"],
        dropna=False
    ).agg({
        "trans_count": "sum",
        "approved_count": "sum",
        "trans_total_amount": "sum",
        "approved_total_amount": "sum"
    }).reset_index()

    return df