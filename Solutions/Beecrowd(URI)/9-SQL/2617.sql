select
    pt.name, pv.name 
from 
    providers as pv, products as pt 
where
    pt.id_providers = pv.id and pv.name = 'Ajax SA';