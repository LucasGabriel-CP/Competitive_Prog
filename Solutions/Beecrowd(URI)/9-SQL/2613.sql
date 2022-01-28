select 
    mv.id, mv.name 
from 
    prices as ps, movies as mv 
where
    mv.id_prices = ps.id and ps.value < 2.00;