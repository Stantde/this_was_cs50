--In 12.sql, write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
--Your query should output a table with a single column for the title of each movie.
--You may assume that there is only one person in the database with the name Bradley Cooper.
--You may assume that there is only one person in the database with the name Jennifer Lawrence.
--SELECT title FROM movies WHERE id IN
--    (SELECT movie_id FROM stars WHERE person_id IN
--        (SELECT id FROM people WHERE name = "Bradley Cooper")
--        (SELECT id FROM people WHERE name = "Jennifer Lawrence"));
--Find "Bradley Cooper" and "Jennifer Lawrence" person ids.
SELECT name, id FROM people WHERE (name = "Bradley Cooper" OR "Jennifer Lawrence");

