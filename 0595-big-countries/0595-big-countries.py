import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df=world
    condition=(df["area"]>=3000000) | (df["population"]>=25000000)
    return df[condition][["name","population","area"]]
    