SELECT CatchedPokemon.nickname
FROM Trainer, CatchedPokemon
WHERE CatchedPokemon.owner_id = Trainer.id AND CatchedPokemon.level >= 50
ORDER BY CatchedPokemon.nickname;