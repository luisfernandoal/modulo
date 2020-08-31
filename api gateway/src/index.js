//servidor
const express=require('express');
const app=express();

//proxy
//const bent = require('bent');

//midlewares
app.use(express.json());//transforma datos json a objeto
app.use(express.urlencoded({extended:false}));//transforma datos de formulario de una url a objeto
//const getJSON = bent('json');
//const obj = await getJSON('https://apex.oracle.com/pls/apex/proyectofernando/temperatura/tem/');
  
//routers
app.use(require('./routers/index'));


app.listen(8080);
console.log('server on port 8080');


