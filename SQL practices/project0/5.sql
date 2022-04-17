SELECT AVG(CatchedPokemon.level) AS Red_Catched_Av_lvl
FROM CatchedPokemon, Trainer
WHERE Trainer.name = 'Red' AND CatchedPokemon.id = Trainer.id;