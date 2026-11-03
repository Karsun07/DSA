import pandas as pd

def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:
    df = pd.merge(
        left=signups[['user_id']],
        right=confirmations[['user_id', 'action']],
        how='left',
        on='user_id'
    )

    df['flag'] = 0
    df.loc[df['action'] == 'confirmed', 'flag'] = 1

    df['flag1'] = df['flag']

    df = df.groupby('user_id').agg(
        {'flag': 'count', 'flag1': 'sum'}
    ).reset_index()

    df['confirmation_rate'] = (
        df['flag1'] / df['flag']
    ).round(2)

    return df[['user_id', 'confirmation_rate']]