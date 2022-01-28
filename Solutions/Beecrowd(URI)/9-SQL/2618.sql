select pt.name, pr.name, ct.name
from products as pt
inner join providers as pr on (pt.id_providers = pr.id and pr.name = 'Sansul SA')
inner join categories as ct on (pt.id_categories = ct.id and ct.name = 'Imported');