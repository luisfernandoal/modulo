create database datos;

-- \c datos   -- es para llamar la base de datos

CREATE TABLE DATOSTEMPERATURA(
    id SERIAL PRIMARY KEY,
    temperetura INT
    );

--\dt -- es para sabes las tablas que tiene

INSERT INTO DATOSTEMPERATURA(temperatura) VALUES
        (36 ),
        (37),
        (38),
        (40);

        
