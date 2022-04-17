SELECT P.name
FROM Pokemon as P
LEFT JOIN Evolution AS EVO2 ON EVO2.after_id = P.id
WHERE 1 = 1 AND EVO2.before_id in( SELECT  EVO1.after_id
        FROM Evolution AS EVO1
        WHERE 1 = 1 AND EVO1.before_id in (SELECT P.id
                FROM Pokemon AS P
                WHERE 1 = 1
                    AND P.name = 'Charmander' ))
LIMIT 1;