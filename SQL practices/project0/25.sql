SELECT name
FROM (Pokemon 
INNER JOIN Evolution ON Pokemon.id = Evolution.after_id)
ORDER BY name;

