import pandas as pd

def immediate_food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:

    df = delivery

    df = df.sort_values("order_date")
    df = df.drop_duplicates("customer_id")

    df["immed"] = 0
    df.loc[df["order_date"] == df["customer_pref_delivery_date"], "immed"] = 1

    ans = (df["immed"].mean() * 100).round(2)

    return pd.DataFrame([{"immediate_percentage": ans}])