select
    pd.name, ct.name
from
    products as pd, categories as ct
where
    ct.id = pd.id_categories
    and ct.id in (1,2,3,6,9) and pd.amount > 100
order by
    ct.id;