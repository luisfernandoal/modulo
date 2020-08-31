//llamo framework router
const {Router}=require('express');
const router= Router();


const {getusers, createUser,restapi,restpost}=require('../controller/index.controller');//llamo  de la carpeta controlador
router.get('/users', getusers)//creo la ruta
router.post('/users',createUser);

//rest api
router.get('/rest',restapi);
router.get('/post',restpost);


module.exports=router;//exporto router