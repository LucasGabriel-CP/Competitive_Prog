select
    products.name as "type",
    case
        when products.type = 'A' then '20.0'
        when products.type = 'B' then '70.0'
        else '530.5'
        end as "price"
from
    products
group by
    products.type, products.name, products.id
order by
    products.type asc, products.id desc, products.name desc;