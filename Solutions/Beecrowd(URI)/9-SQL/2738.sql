select
    cd.name, 
    cast(((sc.math*2 + specific*3 + project_plan*5)/10.0) as decimal(4,2)) as avg
from
    candidate as cd, score sc
where
    cd.id = sc.candidate_id
order by
    avg desc;