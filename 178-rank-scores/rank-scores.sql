with hs AS   (
    SELECT score,
    DENSE_RANK() OVER ( ORDER BY score DESC) 
    AS `rank`
    FROM Scores
)

SELECT score, `rank`  /* sql mai conflict ho jata hai rank name likhne par so backticks ke andar alias likh diya */
FROM hs
ORDER BY `rank` ;

