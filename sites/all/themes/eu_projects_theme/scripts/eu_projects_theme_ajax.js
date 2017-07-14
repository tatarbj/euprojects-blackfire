/**
 * @file
 */

(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.budg_ajax = {
    attach : function(context, settings) {
      var xhr;
      var baseUrl = Drupal.settings.eu_projects_theme.baseUrl;

      /*
       * Project Search form.
       */

      // Change on field reloads search form.
      $('#block-budg-eu-projects-project-search').off('change',
          '#-budg-eu-projects-search-projects select').on(
          'change',
          '#-budg-eu-projects-search-projects select',
          function() {
            var url = baseUrl
                + '/block/get/ajax/budg_eu_projects|project_search';
            var selector = '#-budg-eu-projects-search-projects';
            var data = $('form#-budg-eu-projects-search-projects').find(
                'input, select, button#edit-submit');
            var options = {
              history : false,
              adaptAdvancedSearch : true,
              adaptShowHideSearch : 'open',
              ajaxLoadSelector : '.project-search .fields'
            }
            xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                options);
            return false;
          });

          // Submit form.
          $(document).off('submit', '#-budg-eu-projects-search-projects').on(
          'submit',
          '#-budg-eu-projects-search-projects',
          function(submit) {
            if (xhr  && xhr.readyState != 4) {
              xhr.abort();
            }
            var data = Drupal.behaviors.budg_theme.getFormVars('#-budg-eu-projects-search-projects',  'input, select', 'object');
            var action = $(this).attr('action');
            var publicUrl = action
                + Drupal.behaviors.budg_theme.getFormVars(
                    '#-budg-eu-projects-search-projects', 'input, select');
            var url = baseUrl
                + '/block/get/ajax/budg_eu_projects|view_switcher_results';
            var selector = '#block-budg-eu-projects-view-switcher-results';

            var toFront = false;
            var fromFront = false;
            if (document.getElementById('block-bean-map')) {
              var displayView = 'map';
            }
            else {
              var displayView = 'no-map';
            }
            if ($('body').hasClass('search-page')) {
              fromFront = true;
            }
            else {
              toFront = true;
            }
            var options = {
              adaptAdvancedSearch : true,
              toFront : toFront,
              fromFront : fromFront,
              publicUrl : publicUrl,
              searchSubmit : true,
              ajaxLoadSelector : 'body',
              adaptPagination : (displayView === "no-map"),
              regenerateWebTools : (displayView === "map"),
              keyword : data['content']['value']
            };
            var values = '';
            var separator = '?';
            var button = $(document.activeElement).attr('name');
            var updateForm = false;
            var adaptShowHideSearch = 'open';
            if (button == 'clear') {
              Cookies.remove('euprojects_default_filters');
              var updateForm = true;

              $.each(data, function(index, value) {
                if (index != 'content' && index != 'view') {
                  data[index] = 'All';
                }
                else if (index != 'view') {
                  data[index] = '';
                }
              });
              data['clear'] = 'Ajax';
              var url = url;
              options['publicUrl'] = action;
            }
            else {
              $.extend(options, {
                scroll : '#block-budg-eu-projects-view-switcher-results'
              });
              if (data['content'] || $('body').hasClass('small-device')) {
                var updateForm = true;
                // Close panel on small devices.
                if ($('body').hasClass('small-device')) {
                    adaptShowHideSearch = 'close';
                }
              }
            }

            xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                options);

            if (updateForm) {
                var url = baseUrl
                  + '/block/get/ajax/budg_eu_projects|project_search';
              var selector = '#-budg-eu-projects-search-projects';
              if (button != 'clear') {
                  var data = $('form#-budg-eu-projects-search-projects').find(
                      'input, select');
              }

              var options = {
                history : false,
                adaptAdvancedSearch : true,
                adaptShowHideSearch : adaptShowHideSearch
              }
              xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                  options);
            }

            submit.preventDefault();

            return false;
          });

          /*
           * Opens a project detail.
           */

          // Previous next buttons.
          $('body')
            .off('click', '.project-navigation a.budg-ajax')
            .on(
              'click',
              '.project-navigation a.budg-ajax',
              function() {
                var publicUrl = $(this).attr('href');
                var params = Drupal.behaviors.budg_theme.getUrlVars(publicUrl);
                var nid = $(this).attr('data-nid');
                var url = baseUrl + '/node/get/ajax/' + nid;
                var data = {
                  nid : nid
                };

                $.extend(data, params);
                var selector = '#project-content'
                var options = {
                  displayProject : true,
                  publicUrl : publicUrl,
                  regenerateWebTools : true
                }
                xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                    options);

                // Update Breadcrumbs.
                url = baseUrl
                    + '/block/get/ajax/easy_breadcrumb|easy_breadcrumb';
                selector = '#block-easy-breadcrumb-easy-breadcrumb';
                var data = {
                  nid : nid
                };
                var options = {
                  history : false
                }
                xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                    options);

                // If page change updates the results.
                if (typeof params['page'] != 'undefined') {
                  var page = params['page'];
                  url = baseUrl
                      + '/block/get/ajax/budg_eu_projects|view_switcher_view_display';
                  selector = '#block-budg-eu-projects-view-switcher-view-display';
                  data = {
                    nid : nid,
                    page : page,
                    search_display : 'ok'
                  };

                  var options = {
                    history : false,
                    adaptPagination : true
                  }
                  xhr = Drupal.behaviors.budg_ajax.callback(url, selector,
                      data, options);
                }
                return false;
              });

          // Click on result link.
          // Map panel.
          $(document).off('click', '.leaflet-infopanel a').on('click',
          '.leaflet-infopanel a:not(#leaflet-close)', function(project) {
            var nid = $(this).attr('data-nid');
            var options = {
              scroll : '#main-content',
              fromFront : true,
              displayProject : true,
              ajaxLoadSelector : 'body',
              publicUrl : $(this).attr('href'),
              adaptShowHideSearch : 'close',
              regenerateWebTools : true,
              WTregenerateTimeOut : 1000
            }
            loadPage(nid, options);
            project.preventDefault();
            return false;
          });

          // Click on Grid or list link.
          $('body').off('click',
          '#search-results-display .views-field-title-field-et a').on('click',
          '#search-results-display .views-field-title-field-et a',
          function(project) {
            var nid = $(this).attr('data-nid');
            var options = {
              scroll : '#main-content',
              fromFront : true,
              displayProject : true,
              ajaxLoadSelector : 'body',
              publicUrl : $(this).attr('href'),
              adaptShowHideSearch : 'close',
              regenerateWebTools : true,
              WTregenerateTimeOut : 1000
            }
            loadPage(nid, options)
            project.preventDefault();
            return false;
          });

          function loadPage(nid, options) {
            var url = baseUrl + '/node/get/ajax/' + nid;
            var params = {};
            if (Cookies.get('euprojects_display')) {
              var resultDisplay = $.parseJSON(Cookies.get('euprojects_display'));
              var displayView = resultDisplay['view'];
              var page = resultDisplay['page'][displayView];
              params = {
                page : page,
                search_display : 'ok'
              }
            }

            var selector = '#project-content'
            var front = '';
            if ($('body.search-page').length) {
              var front = true;
            }
            var data = {
              nid : nid
            };
            $.extend(data, params);

            if (!options) {
              options = {
                scroll : '#main-content',
                fromFront : true,
                displayProject : true,
                ajaxLoadSelector : 'body',
                publicUrl : $(this).attr('href'),
                adaptShowHideSearch : 'close',
                regenerateWebTools : true
              }
            }
            xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data, options);
          }

          /*
           * Loads Blocks
           */

          // Pagination of search results.
          $('body')
            .off('click',
              '#block-budg-eu-projects-view-switcher-view-display .pager__wrapper a')
            .on(
              'click',
              '#block-budg-eu-projects-view-switcher-view-display .pager__wrapper a',
              function(project) {
                var publicUrl = $(this).attr('href');
                var params = Drupal.behaviors.budg_theme.getUrlVars(publicUrl);
                var nid = $(this).attr('data-nid');
                var page = params['page'];
                var url = baseUrl
                    + '/block/get/ajax/budg_eu_projects|view_switcher_view_display|'
                    + nid;
                var selector = '#block-budg-eu-projects-view-switcher-view-display';
                var data = {
                  page : page,
                  search_display : 'ok'
                };

                var options = {
                  history : false,
                  adaptPagination : true,
                  scroll : selector
                }
                xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                    options);
                // Update Previous.
                url = baseUrl
                    + '/block/get/ajax/budg_eu_projects|previous_next_button';
                selector = '#block-budg-eu-projects-previous-next-button';
                data = {
                  page : page,
                  search_display : 'ok',
                  nid : nid
                };

                var options = {
                  history : false
                }
                xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                    options);

                project.preventDefault();

                // Piwik tracker.
                _paq.push([ 'trackEvent', 'Project', 'Pagination', page ]);
                return false;
              });

          // Changes the view.
          $(document).off('click',
          '#block-budg-eu-projects-view-switcher .budg-ajax').on(
          'click',
          '#block-budg-eu-projects-view-switcher .budg-ajax',
          function(project) {
            var publicUrl = $(this).attr('href');
            var params = Drupal.behaviors.budg_theme.getUrlVars(publicUrl);
            var filters = Drupal.behaviors.budg_theme.getFormVars('#-budg-eu-projects-search-projects','input, select', 'object');
            var data = $.extend(filters, params);
            var displayView = params['view'];
            var nid = $(this).attr('data-nid');
            var url = baseUrl
                + '/block/get/ajax/budg_eu_projects|view_switcher_results|'
                + nid;
            var selector = '#block-budg-eu-projects-view-switcher-results';

            var options = {
              history : false,
              scroll : selector,
              regenerateWebTools : (displayView === "map"),
              adaptPagination : (displayView != "map")
            }

            if (displayView != 'map') {
              if ($('body').hasClass('map')) {
                var script = document.createElement('script');
                var pathEuropaTheme = Drupal.settings.eu_projects_theme.baseUrl
                    + '/' + Drupal.settings.eu_projects_theme.pathEuropaTheme;
                script.src = pathEuropaTheme + '/js/components/pager.js';
                script.type = 'text/javascript';
                document.getElementsByTagName('head')[0].appendChild(script);
              }
              $('body').removeClass('map').addClass('no-map');
            }
            xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                options);
            $("input[name='view']").attr('value', displayView);

            // Update Previous.
            url = baseUrl
                + '/block/get/ajax/budg_eu_projects|previous_next_button';
            selector = '#block-budg-eu-projects-previous-next-button';
            data = {
              page : data['page'],
              search_display : 'ok',
              nid : nid,
              view : displayView
            };

            var options = {
              history : false
            }
            xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                options);

            project.preventDefault();

            // Piwik tracker.
            _paq.push([ 'trackEvent', 'Search', 'Change View', displayView ]);
            return false;
          });

          // Changes the sort order.
          $('body')
            .off('change', '#-budg-eu-projects-search-projects-sort select')
            .on(
              'change',
              '#-budg-eu-projects-search-projects-sort select',
              function() {
                var url = baseUrl
                    + '/block/get/ajax/budg_eu_projects|view_switcher_view_display';
                var publicUrl = $('form#-budg-eu-projects-search-projects-sort')
                    .attr('action');
                var selector = '#block-budg-eu-projects-view-switcher-view-display';
                var data = Drupal.behaviors.budg_theme.getFormVars(
                    'form#-budg-eu-projects-search-projects-sort',
                    'input, select', 'object');

                var options = {
                  adaptPagination : true,
                  history : false
                }
                xhr = Drupal.behaviors.budg_ajax.callback(url, selector, data,
                    options);
                return false;
              });
    }
  };
  /**
   * Procedes the ajax call.
   *
   * @param url string
   * @param selector string
   * @param data object
   * @param options object dataType : the datatype used for the ajax callback.
   *          default thml ajaxLoadSelector : specifies the selector where the
   *          ajax-loader should be placed, by default takes the value of the
   *          variable selector. fromFront: event triggered from front page.
   *          toFront: action to be taken place on front page
   *          regenerateWebTools: regenerates the webtools. WTregenerateTimeOut:
   *          specifies the time before a ebtool regeneration (avoids js error)
   *          scroll: selector where to scroll searchSubmit: indicates the
   *          calback occurs after a search submit history: if true updates the
   *          title and the url after the content is loaded. adaptPagination:
   *          calls the function Drupal.behaviors.europa_pager.attach().
   *          adaptAdvancedSearch: calls the function adaptAdvancedSearch().
   *          adaptShowHideSearch: calls the function adaptShowHideSearch().
   *          displayProject : shows the detail of a project.
   */
  Drupal.behaviors.budg_ajax.callback = function(url, selector, data, options) {

    if (!data['language']) {
      var language = {
        language : $('html').attr('lang')
      };
    }
    $.extend(data, language);
    var dataType = 'html';
    if (options && options['dataType']) {
      dataType = options['dataType'];
    }

    var ajaxLoadSelector = selector;
    if (options && options['ajaxLoadSelector']) {
      var ajaxLoadSelector = options['ajaxLoadSelector'];
    }

    var fromFront = false;

    // From front.
    if (options && options['fromFront']) {
      fromFront = true
    }
    var toFront = false;
    // To Front.
    if (options && options['toFront']) {
      toFront = true;
    }

    // Timeout when regenerating the webTools.
    var WTregenerateTimeOut = 500;
    if (options && options['WTregenerateTimeOut']) {
      WTregenerateTimeOut = options['WTregenerateTimeOut'];
    }

    var xhr = $
        .ajax({
          url : url,
          dataType : dataType,
          data : data,
          async : true,
          beforeSend : function() {
            if (ajaxLoadSelector != 'none') {
              $(ajaxLoadSelector).addClass('ajax-load');
            }

            // From front.
            if (fromFront) {
              $('body').addClass('node-type-project')
                  .removeClass('search-page');
              $('.page-content div.container-fluid.page-header__hero-title')
                  .replaceWith('<div id="project-content"> </div>');
            }

            // To Front.
            if (toFront) {
              $('body').removeClass('node-type-project')
                  .addClass('search-page');
              $('#project-content')
                  .replaceWith(
                      '<div class="container-fluid page-header__hero-title"> </div>');
            }

          },
          success : function(result) {
            var publicUrl = url;
            var title = '';

            // Scroll.
            if (options && options['scroll']) {
              $('html, body').animate({
                scrollTop : $(options['scroll']).offset().top
              }, 1000);
            }

            // Search submit.
            if (options && options['searchSubmit']) {
              $('body').removeClass('mobileNoScroll').addClass(
                  'search-submitted');
            }

            // Main content.
            if (dataType == 'html') {
              $(selector).replaceWith($(result));
            }
            else {
              if (result[1] !== undefined) {
                var viewHtml = result[1].data;
                $(selector).html(viewHtml);
              }
            }

            // Updates url and title.
            var history = true;

            if (options && typeof options['history'] != 'undefined') {
              history = options['history'];
            }

            if (history) {
              if (options && options['publicUrl']) {
                publicUrl = options['publicUrl'];
              }
              Drupal.behaviors.budg_ajax.history(result, publicUrl, title,
                  options);
            }
          },
          complete : function() {
            if (ajaxLoadSelector != 'none') {
              $(ajaxLoadSelector).removeClass('ajax-load');
            }

            // Readapts pager to the coprorate template layout.
            if (options && options['adaptPagination']) {
              Drupal.behaviors.europa_pager.attach();
            }

            // Initiates the Basic/Advanced search.
            if (options && options['adaptAdvancedSearch']) {
              Drupal.behaviors.budg_theme.budgThemeAdvancedSearch();
            }

            // Initiates the Show/Hide search.
            if (options && options['adaptShowHideSearch']) {
              Drupal.behaviors.budg_theme
                  .budgShowHideSearch(options['adaptShowHideSearch']);
            }

            // Shows the details of a project.
            if (options && options['displayProject']) {
              $('body').removeClass('search-submitted');
              Drupal.behaviors.budg_theme.budgShowHideSearch();
              // Read more function for long project results.
              Drupal.behaviors.budg_theme.budgThemeReadMore(
                  ".field--field-project-achievements .field__items", 600);
            }

            // Load webtools.
            if (options && options['regenerateWebTools']) {
              setTimeout(function() {
                $('.wtWidgets').remove();
                $wt.regenerate();
              }, WTregenerateTimeOut);
            }
          }
        });
        return xhr
  }
  // Updates url and title.
  Drupal.behaviors.budg_ajax.history = function(result, url, title, options) {
    if (window.history.replaceState) {
      // Get title of loaded content.
      if (result && !title) {

        var matches = result.match("<title>(.*?)</title>");
        if (matches) {
          // Decode any HTML entities.
          var title = $('<div/>').html(matches[1]).text();
        }
        else {
          var title = $('#project-content .page-header__hero-title h1').html();
          if (!title) {
            title = $('.page-header__hero-title h1').html();
          }
        }

        // Since title is not changing with
        // window.history.pushState(),
        // manually change title. Possible bug with browsers.
        document.title = title;
      }
      // Store current url.
      window.history.replaceState({
        page : 0
      }, document.title, window.location.href);

      // Change url.
      window.history.pushState({
        page : 1
      }, title, url);
    }

    // Tracks the loaded page in piwik.
    if (options['searchSubmit'] && typeof _paq !== 'undefined') {
      var results = $('#number-results').attr('data-results');
      _paq
          .push([ 'trackSiteSearch', options['keyword'], 'no category', results ]);
    }
    else if (typeof _paq !== 'undefined') {
      _paq.push([ 'setDocumentTitle', document.title ]);
      _paq.push([ 'trackPageView' ]);
    }
  }
})(jQuery, Drupal, this, this.document);
