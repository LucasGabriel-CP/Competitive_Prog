select 
    mv.id, mv.name 
from 
    genres as gr, movies as mv 
where
    mv.id_genres = gr.id and gr.description = 'Action';