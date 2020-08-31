const {Pool}= require('pg');
const bent = require('bent');
const { get } = require('../routers');
const { response } = require('express');
const getJSON = bent('json');

const pool= new Pool({
    host: 'localhost',
    user: 'postgres',
    password: 'respuesta',
    database: 'datos',
    port: '5433'
});

const getusers= async (req,res)=>{
 const respuesta = await pool.query('SELECT * FROM DATOSTEMPERATURA');
   console.log(respuesta.rows);
   res.status(200).json(respuesta.rows);
};

const createUser= async (req,res) =>{
     
     const {temperatura}=req.body;
     const respuesta = await pool.query('INSERT INTO DATOSTEMPERATURA(temperatura) VALUES ($1);',
     [temperatura]);
     console.log(respuesta.rows);
     res.send('temp created');
};

const restapi= async (req,res)=>{
   
    const respuesta = await getJSON('https://apex.oracle.com/pls/apex/proyectofernando/temperatura/tem/');
      console.log(respuesta);
      res.send(respuesta);
   };
  
  const restpost= async (req,res) =>{
     
    const post = bent('https://apex.oracle.com', 'POST', 'json', 200);
var numero;
numero =60;
    post('/pls/apex/proyectofernando/temperatura/tem/', {"temperatura": numero });
    res.send('enviado');
   // const {temperatura}=req.body;
    //const respuesta = await pool.query('INSERT INTO DATOSTEMPERATURA(temperatura) VALUES ($1);',[temperatura]);
    //console.log(respuesta.rows);
    //res.send('temp created');
};  

//exporto getusers
module.exports={
    getusers,
    createUser,
    restapi,
    restpost
};
