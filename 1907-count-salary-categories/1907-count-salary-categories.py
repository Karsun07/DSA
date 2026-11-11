import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    df = accounts.copy()

    df["category"] = "Low Salary"
    df.loc[(df["income"] >= 20000) & (df["income"] <= 50000), "category"] = "Average Salary"
    df.loc[df["income"] > 50000, "category"] = "High Salary"

    df = df.groupby("category").size().reset_index(name="accounts_count")

    df2=pd.DataFrame({
        "category":["Low Salary","Average Salary","High Salary"]
    })
    df=df2.merge(df,on="category",how="left")
    df["accounts_count"]=df["accounts_count"].fillna(0).astype(int)
    return df
    