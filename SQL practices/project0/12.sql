SELECT Pokemon.name
FROM  (Pokemon 
INNER JOIN Evolution ON Pokemon.id = Evolution.before_id )
WHERE Evolution.before_id > Evolution.after_id
GROUP BY Pokemon.name, Evolution.before_id, Evolution.after_id
ORDER BY Pokemon.name