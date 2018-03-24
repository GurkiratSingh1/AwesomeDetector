const express = require('express');
const morgan = require('morgan');
const bodyParser = require('body-parser');

const app = express();

app.use(morgan('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));

app.get('/',(req,res) => {
  res.status(200).send({ message: 'Welcome to the AwesomeDetector API' });
});

app.post('/api',(req,res) => {
  console.log(req.body);
  res.send({ message: 'hoob' });
});

module.exports = app;
