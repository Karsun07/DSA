import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:
    df = weather.sort_values(by="recordDate")

    df["prevdaytemp"] = df["temperature"].shift(1)
    df["prevdate"] = df["recordDate"].shift(1)

    condition = (
        (df["temperature"] > df["prevdaytemp"]) &
        ((df["recordDate"] - df["prevdate"]).dt.days == 1)
    )

    return df.loc[condition, ["id"]]