import pandas as pd

def find_primary_department(employee: pd.DataFrame) -> pd.DataFrame:
    df = employee

    condition1 = df[df["primary_flag"] == "Y"]

    df2 = df.groupby("employee_id").size().reset_index(name="count")
    condition2 = df2[df2["count"] == 1]

    df2 = employee.merge(condition2, on="employee_id", how="inner")

    return pd.concat([
        condition1[["employee_id", "department_id"]],
        df2[["employee_id", "department_id"]]
    ]).drop_duplicates()