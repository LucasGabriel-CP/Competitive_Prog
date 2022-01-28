select
    pt.name 
from 
    providers as pv, products as pt 
where
    pt.id_providers = pv.id and pv.name like 'P%'
    and pt.amount between 10 and 20;