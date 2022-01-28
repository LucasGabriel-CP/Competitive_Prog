select distinct
    ct.id, ct.name 
from 
    customers as ct 
where not exists
    (select 1
     from 
         locations as lt 
     where
         lt.id_customers = ct.id)
order by ct.id;
        