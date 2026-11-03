import pandas as pd

def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:

    df = signups[["user_id"]].merge(
        confirmations[["user_id", "action"]],
        on="user_id",
        how="left"
    )

    df["flag"] = 0
    df.loc[df["action"] == "confirmed", "flag"] = 1

    df["flag1"] = df["flag"]

    df = df.groupby("user_id").agg({
        "flag1": "count",
        "flag": "sum"
    }).reset_index()

    df["confirmation_rate"] = (
        df["flag"] / df["flag1"]
    ).round(2)

    return df[["user_id", "confirmation_rate"]]