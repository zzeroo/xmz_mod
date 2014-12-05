Package.describe({
  name: 'zzeroo:owlcarousel',
  summary: ' /* Fill me in! */ ',
  version: '1.0.0',
  git: ' /* Fill me in! */ '
});

Package.onUse(function(api) {
  api.versionsFrom('1.0');
  api.addFiles('zzeroo:owlcarousel.js');
});

Package.onTest(function(api) {
  api.use('tinytest');
  api.use('zzeroo:owlcarousel');
  api.addFiles('zzeroo:owlcarousel-tests.js');
});
