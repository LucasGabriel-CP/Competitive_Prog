select pt.name, pr.name, cast(pt.price as decimal(10, 2)) as price
from products as pt 
inner join providers as pr on (pt.id_providers = pr.id and pt.price > 1000)
inner join categories as ct on (pt.id_categories = ct.id and ct.name = 'Super Luxury');