import pandas as pd

def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:

    find_per = lambda x: (x.count() / users.user_id.size * 100).round(2)

    return (register.groupby('contest_id', as_index = False)['user_id']
                    .agg(percentage = find_per)
                    .sort_values(['percentage','contest_id'], ascending = [0,1]))