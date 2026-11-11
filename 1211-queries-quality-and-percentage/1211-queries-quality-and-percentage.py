import pandas as pd

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

    df["quality"]=round(df["quality"],2)
    df["poor_query_percentage"]=df["poor"]/df["rating"]
    df["poor_query_percentage"]=round(df["poor_query_percentage"]*100,2)

    return df[["query_name","quality","poor_query_percentage"]]

