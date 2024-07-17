--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
--Your query should output a table with a single column for the name of each person.
--There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--Kevin Bacon himself should not be included in the resulting list.
--SELECT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN(SELECT movie_id FROM stars WHERE person_id IN(
--    SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958
--            )
--        )
--    AND NOT = (
--        SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = 1958)
--);
--Find "Kevin Bacon"
--SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958"; --yields id = 102.
--Find movies where Kevin Bacon starred.
--SELECT movie_id FROM stars WHERE person_id IN
--    (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958");--yields 60 movies.
--Find stars in these 60 movies.
--SELECT DISTINCT(person_id) from stars WHERE movie_id IN
--   (SELECT movie_id FROM stars WHERE person_id IN
--        (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958")); --yields 183 people
--What are their names?
--SELECT name FROM people WHERE id IN
--    (SELECT DISTINCT(person_id) from stars WHERE movie_id IN
--        (SELECT movie_id FROM stars WHERE person_id IN
--            (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958")));
--Remove "Kevin Bacon"
SELECT name FROM people WHERE id IN
    (SELECT DISTINCT(person_id) from stars WHERE movie_id IN
        (SELECT movie_id FROM stars WHERE person_id IN
            (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958"))) AND NOT id = (SELECT id FROM people WHERE name = "Kevin Bacon" AND birth = "1958");
