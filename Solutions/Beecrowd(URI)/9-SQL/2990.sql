select ep.cpf, ep.enome, dp.dnome
from empregados ep
inner join departamentos dp on (ep.dnumero = dp.dnumero)
where not exists
    (
        select 1
        from trabalha tr
        inner join projetos pr on (pr.pnumero = tr.pnumero)
        where (tr.cpf_emp = ep.cpf)
    )
order by ep.cpf;