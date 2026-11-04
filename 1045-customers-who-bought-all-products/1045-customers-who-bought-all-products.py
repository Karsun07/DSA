import pandas as pd

def find_customers(customer: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    df=customer
    df=df[["customer_id","product_key"]].drop_duplicates()
    df=df.groupby("customer_id").agg({"product_key":"count"}).reset_index()
    numberofProd=len(product)
    return df[df["product_key"]==numberofProd][["customer_id"]]
