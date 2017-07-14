/**
 * @file
 * eu_projects_theme_map.js
 */

// Initiates the map.
L.custom = {

  init : function (obj, params) {
    // Gets the base url.
    // Customized in the map json.
    if (document.querySelector('#block-bean-map script')) {
      var jsonMap = JSON.parse(document.querySelector('#block-bean-map script').innerHTML);
      var baseUrl = jsonMap.baseurl;
    }
    // Otherwise default path.
    if (!baseUrl || baseUrl == 'undefined') {
      var baseUrl = Drupal.settings.eu_projects_theme.baseUrl;
    }

    var language = Drupal.settings.eu_projects_theme.language;

    // Obtain the search vars.
    var searchVars = Drupal.behaviors.budg_theme.getFormVars('#-budg-eu-projects-search-projects',  'input, select');

    // The url to the geojson file.
    var d = new Date();
    var month = d.getMonth() + 1;
    var rnd_str_day = d.getFullYear() + '_' + month + '_' + d.getDate();
    var urlGeojson = baseUrl + '/solr/geojson_' + language + searchVars + '&valid=' + rnd_str_day;

    // Replace eventual double slashes caused by baseUrl sometimes containign trailing slash.
    urlGeojson = urlGeojson.replace('//solr', '/solr');

    // CUSTOM.
    obj.style.minHeight = "500px";

    // INIT MAP OBJECT.
    var map = L.map(obj, {
      "center" : [20, 9],
      "zoom" : 2,
      "minZoom" : 2,
      "maxZoom" : 12
    });

    // Display the loading.
    map.fire("dataloading");

    // TILES.
    var tileLayer = L.wt.tileLayer().addTo(map);

    // MARKERS.
    var options = {
      cluster: {
        radius: 70
      }
    }
    var kml = L.wt.markers([urlGeojson], options).addTo(map);

    kml.fitBounds();

    // End loading - workaround.
    setTimeout(function () {
      map.fire("dataload");
    }, 2000);

    // IMPORTANT !!!!
    $wt._queue("next");
  }
};
