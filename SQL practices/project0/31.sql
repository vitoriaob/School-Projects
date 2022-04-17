SELECT CatchedPokemon.nickname FROM CatchedPokemon WHERE CatchedPokemon.pid IN (SELECT pid
  FROM
      (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
  WHERE
      CatchedPokemon.pid IN
          (SELECT CatchedPokemon.pid cnt FROM CatchedPokemon GROUP BY CatchedPokemon.pid    HAVING COUNT(CatchedPokemon.pid) >= 2)
      AND Trainer.hometown = 'Sangnok City' OR Trainer.hometown = 'Blue City'
  GROUP BY pid
  HAVING COUNT(DISTINCT hometown) = 2) ORDER BY nickname ASC