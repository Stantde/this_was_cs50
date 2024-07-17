SELECT AVG(energy) from songs where artist_id IN (SELECT id FROM artists WHERE name = "Drake");
