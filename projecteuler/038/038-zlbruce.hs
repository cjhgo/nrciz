import Data.List
-- n > 1,  num < 10000
--

conProd n = genConProd "" n 1
genConProd res n t = 
    if resLen > 9
    then 0
    else if resLen == 9
    then if nubResLen == 9 then read res else 0
    else genConProd res' n t'
    where
        resLen    = length res
        nubResLen = length $ nub $ delete '0' res
        res'      = res ++ show (n * t)
        t'        = t + 1

main = print $ maximum $ map conProd [1..9999]
