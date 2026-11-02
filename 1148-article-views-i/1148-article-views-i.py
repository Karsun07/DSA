import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df = views
    condition = df["author_id"] == df["viewer_id"]

    return df[condition][["author_id"]].drop_duplicates().rename(
        columns={"author_id": "id"}
    ).sort_values("id")