SELECT DISTINCT P.name
FROM Pokemon AS P, Evolution as EVO
WHERE 1 = 1 AND P.id NOT IN( SELECT EVO.after_id FROM CatchedPokemon AS EVO) AND P.type = 'water'
ORDER BY P.name;