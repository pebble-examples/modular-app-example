Pebble.addEventListener('ready', function() {
  console.log('PebbleKit JS ready!');

  Pebble.sendAppMessage({ 'AppKeyJSReady': 1 });
});