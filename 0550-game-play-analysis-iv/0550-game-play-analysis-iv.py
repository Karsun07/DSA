import pandas as pd

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:

    df = activity

    # Find first login date of each player
    df = df.groupby("player_id").agg({
        "event_date": "min"
    }).reset_index()

    # Find players who logged in the next day
    df2 = activity.merge(df, on="player_id", suffixes=("", "_first"))

    condition = (
        df2["event_date"] ==
        df2["event_date_first"] + pd.Timedelta(days=1)
    )

    df2 = df2[condition]

    # Fraction of players
    ans = round(df2["player_id"].nunique() / activity["player_id"].nunique(), 2)

    return pd.DataFrame({"fraction": [ans]})