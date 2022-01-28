select
    name, cast(extract(day from payday) as numeric) as day
from
    loan;