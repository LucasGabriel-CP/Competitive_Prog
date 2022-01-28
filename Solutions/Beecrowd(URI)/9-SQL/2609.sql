select ct.name, sum(pr.amount)
from products pr
inner join categories ct on (ct.id = pr.id_categories)
group by ct.name;