select 
    ct.name, rt.rentals_date 
from 
    customers as ct, rentals as rt 
where
    rt.id_customers = ct.id 
    and extract(year from rt.rentals_date) = '2016' 
    and extract(month from rt.rentals_date) = '09';