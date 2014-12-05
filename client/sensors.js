Template.sensorView.helpers({
  'sensors': function() {
    return Sensors.find().fetch();
  },
});

Template.sensorView.events({
});

Template.sensor.events({
  'click .remove': function() {
    Sensors.remove(this._id);
  }
});

Template.sensorForm.events({
  'submit form': function(event) {
    event.preventDefault();
    var sensorName = event.target.name.value;
    var sensorDescription = event.target.description.value;
    var sensorValue = 0;
    var sensorSi = event.target.si.value;
    Sensors.insert({
      name: sensorName,
      description: sensorDescription,
      value: parseInt(sensorValue),
      si: sensorSi
    });
  }
})
