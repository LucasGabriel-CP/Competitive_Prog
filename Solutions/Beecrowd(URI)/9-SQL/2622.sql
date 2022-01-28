select
    ct.name
from
    customers as ct, legal_person as lp
where
    ct.id = lp.id_customers;