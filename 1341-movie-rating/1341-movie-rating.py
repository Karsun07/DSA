import pandas as pd

def movie_rating(
    movies: pd.DataFrame,
    users: pd.DataFrame,
    movie_rating: pd.DataFrame
) -> pd.DataFrame:

    # 1. User who rated the most movies
    user_df = movie_rating.merge(users, on="user_id")

    user_df = user_df.groupby(["user_id", "name"]).size().reset_index(name="count")

    user_df = user_df.sort_values(
        ["count", "name"], ascending=[False, True]
    )

    user_result = user_df.iloc[[0]][["name"]].rename(
        columns={"name": "results"}
    )

    # 2. Movie with highest average rating in February 2020
    movie_df = movie_rating[
        (movie_rating["created_at"] >= "2020-02-01") &
        (movie_rating["created_at"] < "2020-03-01")
    ]

    movie_df = movie_df.merge(movies, on="movie_id")

    movie_df = movie_df.groupby(["movie_id", "title"])["rating"].mean().reset_index()

    movie_df = movie_df.sort_values(
        ["rating", "title"], ascending=[False, True]
    )

    movie_result = movie_df.iloc[[0]][["title"]].rename(
        columns={"title": "results"}
    )

    # UNION ALL equivalent
    return pd.concat([user_result, movie_result], ignore_index=True)