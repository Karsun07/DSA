import pandas as pd
from decimal import Decimal, ROUND_HALF_UP

def queries_stats(queries: pd.DataFrame) -> pd.DataFrame:
    
    df=queries.copy()
   

    df["quality"]=df["rating"]/df["position"]
    df["poor"]=0
    df.loc[df["rating"]<3,"poor"]=1
    
    df=df.groupby("query_name").agg({
        "quality":"mean",
        "poor":"sum",
        "rating":"count"
    }).reset_index()

    df["quality"]=df["quality"].apply(
        lambda x: float(Decimal(str(x)).quantize(
            Decimal("0.01"), rounding=ROUND_HALF_UP
        ))
    )
    df["poor_query_percentage"]=df["poor"]/df["rating"]
    df["poor_query_percentage"]=(df["poor_query_percentage"]*100).apply(
        lambda x: float(Decimal(str(x)).quantize(
            Decimal("0.01"), rounding=ROUND_HALF_UP
        ))
    )

    return df[["query_name","quality","poor_query_percentage"]]

