SELECT name from songs where artist_id IN (SELECT id FROM artists WHERE name = "Post Malone");
