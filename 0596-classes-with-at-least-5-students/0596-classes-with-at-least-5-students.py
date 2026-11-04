import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    
    df=courses
    df=df.groupby("class").agg({"student":"count"}).reset_index()
    return df.loc[df["student"]>=5,["class"]]