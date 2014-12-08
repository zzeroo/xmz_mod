

Template.sensorView.helpers({
  'sensors': function() {
    return Sensors.find().fetch();
  },
});

Template.sensorList.helpers({
  'sensors': function() {
    return Sensors.find().fetch();
  },
});

Template.sensorView.events({
});

/** Render the owlCarousel */
Template.sensor.rendered = function() {
  $('.owl-carousel').owlCarousel({
    items: 2,
    loop: true,
    dots: true
  });

  // The var owl stored the owl instance used for custom nav events and so on
  var owl = $('.owl-carousel').data('owlCarousel');

   // Custom Navigation Events
  $(".next").click(function(){
    owl.next();
  })
  $(".prev").click(function(){
    owl.prev();
  })
};


Template.sensorList.events({
  'click .remove': function() {
    Sensors.remove(this._id);
  },
});

Template.sensorForm.events({
  'submit form': function(event) {
    event.preventDefault();
    var sensorName = event.target.sensorName.value;
    var sensorDescription = event.target.sensorDescription.value;
    var sensorValue = 0;
    var sensorSi = event.target.sensorSi.value;
    Sensors.insert({
      name: sensorName,
      description: sensorDescription,
      value: parseInt(sensorValue),
      si: sensorSi
    });
    Router.go('/');
  }
})
