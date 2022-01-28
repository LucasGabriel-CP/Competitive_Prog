select
    ry.name, round(ry.omega * 1.618, 3) as "Fator N"
from
    dimensions as ds, life_registry as ry
where
    ds.id = ry.dimensions_id and
    ds.name in ('C774', 'C875') and
    ry.name like 'Richard %'
order by
    ry.omega;