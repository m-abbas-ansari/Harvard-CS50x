SELECT title, rating FROM
ratings JOIN movies ON movies.id = ratings.movie_id --Joining using primary key
WHERE year = 2010 ORDER BY rating DESC, title;