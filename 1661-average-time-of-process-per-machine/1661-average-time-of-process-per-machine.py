import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:

    start = activity[activity["activity_type"] == "start"]
    end = activity[activity["activity_type"] == "end"]

    df = start.merge(
        end,
        on=["machine_id", "process_id"],
        suffixes=("_start", "_end")
    )

    df["processing_time"] = df["timestamp_end"] - df["timestamp_start"]

    result = df.groupby("machine_id")["processing_time"].mean().round(3).reset_index()

    return result