select ct.name, od.id
from customers ct
inner join orders od on (ct.id = od.id_customers)
where
    extract(month from od.orders_date) < 7;