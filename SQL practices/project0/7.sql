SELECT CatchedPokemon.nickname
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE CatchedPokemon.level =
(SELECT MAX(CatchedPokemon.level) FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id) 
 WHERE Trainer.hometown = 'Blue City')

UNION

SELECT CatchedPokemon.nickname
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE CatchedPokemon.level =
(SELECT MAX(CatchedPokemon.level) FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id) 
 WHERE Trainer.hometown = 'Brown City')
 
 UNION
 
 SELECT CatchedPokemon.nickname
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE CatchedPokemon.level =
(SELECT MAX(CatchedPokemon.level) FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id) 
 WHERE Trainer.hometown = 'Sangnok City')
 
 UNION
 
 SELECT CatchedPokemon.nickname
FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id)
WHERE CatchedPokemon.level =
(SELECT MAX(CatchedPokemon.level) FROM (CatchedPokemon INNER JOIN Trainer ON CatchedPokemon.owner_id = Trainer.id) 
 WHERE Trainer.hometown = 'Rainbow City')