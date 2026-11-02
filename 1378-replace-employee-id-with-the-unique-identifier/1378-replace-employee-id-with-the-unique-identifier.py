import pandas as pd

def replace_employee_id(employees: pd.DataFrame, employee_uni: pd.DataFrame) -> pd.DataFrame:
    df1 = employees
    df2 = employee_uni

    return df1.merge(df2, on="id", how="left")[["unique_id", "name"]]