import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:
    df_start = activity[activity["activity_type"] == "start"]
    df_end = activity[activity["activity_type"] == "end"]

    df = df_end.merge(
        df_start,
        on=["machine_id", "process_id"],
        how="inner"
    )

    df["exectime"] = df["timestamp_x"] - df["timestamp_y"]

    df2 = (
    df.groupby("machine_id")["exectime"]
    .mean()
    .round(3)
    .reset_index(name="processing_time")
)

    return df2