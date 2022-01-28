select 
    pd.id, pd.name 
from 
    products as pd, categories as ct 
where
    ct.id = pd.id_categories and ct.name like 'super%';