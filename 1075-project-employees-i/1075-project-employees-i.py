import pandas as pd

def project_employees_i(project: pd.DataFrame, employee: pd.DataFrame) -> pd.DataFrame:
    df = project.merge(employee, on="employee_id", how="left")

    df["average_years"] = df["experience_years"]

  
    df=df.groupby("project_id").agg({"average_years": "mean"}).reset_index()
   

    df["average_years"] = df["average_years"].round(2)

    return df[["project_id","average_years"]]