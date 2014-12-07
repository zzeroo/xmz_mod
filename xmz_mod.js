
Sensors     = new Mongo.Collection("sensors");

Router.route('/', function () {
  this.render('sensorView');
});

Router.route('/sensors', function() {
  this.render('sensorList');
});

Router.route('/newSensor', function() {
  this.render('sensorForm');
});
