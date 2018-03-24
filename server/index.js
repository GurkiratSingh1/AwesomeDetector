const http = require('http');
const localTunnel = require('localtunnel');

const app = require('./app');

const PORT = process.env.PORT || 3000;

let server = http.createServer(app);

server.listen(PORT, () => {
  console.log('Listening on Port: ',PORT);

  const tunnel = localTunnel(PORT,{ subdomain: 'nigelfrnds' }, (err,tunnel) => {
    console.log('tunnel-url: ', tunnel.url);
  });

  tunnel.on('close',() => {
    console.log('tunnel is closed');
  });
});
