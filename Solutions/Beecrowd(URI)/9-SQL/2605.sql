select 
    pd.name, pv.name 
from 
    products as pd, providers as pv, categories as ct
where
    ct.id = pd.id_categories and ct.id = 6 and pd.id_providers = pv.id;