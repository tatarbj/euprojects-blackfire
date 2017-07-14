/**
 * @file
 * eu_projects_theme.js
 */

(function($, Drupal, window, document, undefined) {
  Drupal.behaviors.budg_theme = {
    attach : function(context, settings) {
      /*
       * Title shortener
       */
      $("#project-content .col-lg-9 > h1").each(function(index) {
        $(this).html(Drupal.behaviors.budg_theme.wordTrim($(this).text(), 120, '(...)'));
      });

      /*
       * Search.
       */

      // Show hide search.
      // Initiate.
      Drupal.behaviors.budg_theme.budgShowHideSearch('close');

      // Set up advanced search toggle.
      Drupal.behaviors.budg_theme.budgThemeAdvancedSearch();

      // Read more function for long project descriptions.
      Drupal.behaviors.budg_theme.budgThemeReadMore(
          ".field--field-description .field__items", 600);

      // Read more function for long project results.
      Drupal.behaviors.budg_theme.budgThemeReadMore(
          ".field--field-project-achievements .field__items", 600);

      // Smooth scroll.
      $('body').on('click',  '.budget-scroll', function (event) {
        var target = $(this).attr('href');
          $('html, body').animate({
              scrollTop : $(target).offset().top
            }, 1000);
          return false;
      });
    }
  };
  // Advanced search toggle.
  Drupal.behaviors.budg_theme.budgThemeAdvancedSearch = function() {
    var searchWrapper = '.project-search';

    // Setup the triggers.
    if (!$('.page-admin').length && !$(".advanced-search-triggers").length) {
      var openingTag = '<div class="advanced-search-triggers">';
      var spanAdvanced = '<span class="trigger close">'
          + Drupal.settings.eu_projects_theme.labelBasicSearch + '</span>';
      var separator = '<span class="separator"> | </span>';
      var spanBasic = '<span class="trigger open">'
          + Drupal.settings.eu_projects_theme.labelAdvancedSearch + '</span>';
      var endTag = '</div>'
      $(searchWrapper).prepend(
          openingTag + spanAdvanced + separator + spanBasic + endTag);
    }

    // Hides the advanced search via css.
    $(searchWrapper).addClass('active');

    // Stays open when activated.
    if (Cookies.get("advanced_search")) {
      $(searchWrapper).addClass('as_open');
    }

    // Toggles on click.
    $(searchWrapper + ' .advanced-search-triggers .trigger').click(
        function() {
          var myClass = $(this).attr("class");
          var changeAction = 'close';
          if (myClass == 'trigger open') {
            $(searchWrapper).addClass('as_open');
            Cookies.set("advanced_search", 1, {
              expires : 10
            });
            changeAction = 'open';
          }
          else {
            $(searchWrapper).removeClass('as_open');
            Cookies.remove("advanced_search");
          }

          // Piwik tracker.
          _paq.push([ 'trackEvent', 'Search', 'Advance/Basic Search',
              changeAction ]);
        });
  }

  // Read more function for long project results.
  Drupal.behaviors.budg_theme.budgThemeReadMore = function(selector, limit) {
    var text = $(selector).html();
    if (text && text.length > limit) {
      var read_more = Drupal.settings.eu_projects_theme.label_read_more;
      var close = Drupal.settings.eu_projects_theme.label_close;
      var tags_closed = '<div class="trigger open" title="' + read_more
          + '"><span class="icon icon--down"></span>' + read_more
          + '</div></div>';
      var tags_open = '<div class="trigger close" title="' + close
          + '"><span class="icon icon--up"></span>' + close + '</div>';
      var text1 = text.substr(0, limit) + ' (...)';

      $(selector).html(text1).append(tags_closed);

      $(selector).on('click', '.trigger', function() {

        var cl = $(this).attr("class");

        if (cl == 'trigger open') {
          $(selector).html(text).append(tags_open);
        }
        else {
          $(selector).html(text1).append(tags_closed);
        }
      });
    }
  }

  // Show hide search.
  Drupal.behaviors.budg_theme.budgShowHideSearch = function(action) {

    var search_switcher = '#-budg-eu-projects-search-projects > div';

    // Setup the triggers.
    if (!$('.page-admin').length && !$(".display-search").length) {
      var openingTag = '<div class ="show-hide"><div class="btn btn-ctn display-search">';
      var showSearch = '<span class="trigger open">'
          + Drupal.settings.eu_projects_theme.labelShowSearch + '</span>';
      var hideSearch = '<span class="trigger close">'
          + Drupal.settings.eu_projects_theme.labelHideSearch + '</span>';
      var endTag = '</div></div>';
      $(search_switcher).append(openingTag + showSearch + hideSearch + endTag);
    }

    // Displays the search switcher.
    $(search_switcher).show();

    // Hides the search on the project page.
    if ($('body').hasClass('node-type-project') && action != 'open') {
      action = 'close';
    }

    // Default behaviour.
    if (window.matchMedia("(max-width: 768px)").matches) {
      if (typeof action == 'undefined' || action == 'close') {
        action = 'close';
      }
      $('body').addClass('small-device');
    }
    else {
      if ($('body').hasClass('search-submitted')) {
        action = 'open';
      }
    }

    // Perform the action.
    if (action == 'close') {
      $('body').removeClass("mobileNoScroll");
      $(search_switcher).addClass('closed');
    }
    else {
      $('body').addClass("mobileNoScroll");
      $(search_switcher).removeClass('closed');
    }
    // Open/close trigger.
    $('.display-search').on('click', '.trigger', function() {
      var myclass = $(this).attr("class");
      if (myclass == 'trigger close') {
        $('body').removeClass("search-submitted");
        Drupal.behaviors.budg_theme.budgShowHideSearch('close');
      }
      else {
        $('body').removeClass('search-submitted');
        Drupal.behaviors.budg_theme.budgShowHideSearch('open');
      }
      $(search_switcher + ' .btn-menu').toggleClass('is-collapsed');

      // Piwik tracker.
      _paq.push([ 'trackEvent', 'Search', 'Open/close Search', action ]);
    });
  }

  // Gets the variables from the url.
  Drupal.behaviors.budg_theme.getUrlVars = function(url) {
    if (!url) {
      var url = window.location.href;
    }

    var urlArray = url.split('?');
    var urlParams = '';
    if (typeof urlArray[1] != 'undefined') {
      urlParams = urlArray[1].split('#');
      urlParams = urlParams[0];
    }

    var params = urlParams.split("&").reduce(function(prev, curr, i, arr) {
      var p = curr.split("=");
      prev[decodeURIComponent(p[0])] = decodeURIComponent(p[1]);
      return prev;
    }, {});

    return params;
  }

  /**
   * Translates the forms values into url variables.
   *
   * @return string
   */
  Drupal.behaviors.budg_theme.getFormVars = function(target, field_type, output) {
    if (!output) {
      var output = 'string';
    }
    // Obtain the search vars.
    var $set = jQuery(target).find(field_type);
    var searchVars = '';
    if (output == 'object') {
      searchVars = {};
    }
    $set.each(function(index, element) {
      if (this.name && this.name != 'undefined' && this.name != 'op'
          && this.value != 'undefined') {
        var value = this.value;
        var field = this.name;
        if (output == 'string') {
          var separator = '?';
          if (index != 0) {
            var separator = '&';
          }
          if (field == 'keys') {
            value = encodeURIComponent(value);
          }
          searchVars = searchVars + separator + field + '=' + value;
        }
        else if (output == 'object') {
          searchVars[field] = value;
        }
      }
    });
    return searchVars;
  }

  /**
   * Gets the default search values.
   *
   * @params array default search values
   *
   * @return string
   */
  Drupal.behaviors.budg_theme.searchValues = function(params, output, exceptions) {
    if (!exceptions) {
      var exceptions = [];
    }
    if (!output) {
      var output = 'string';
    }
    if (!params) {
      var params = Drupal.behaviors.budg_theme.getUrlVars();
    }

    var cookie = Cookies.get('euprojects_default_filters');
    if (cookie) {
      var set = $.parseJSON(cookie);
    }
    else {
      var set = params;
    }

    var searchValues = '';
    if (output == 'object') {
      searchValues = {};
    }
    $.each(set,  function(field, value) {
      if ($.inArray(field, exceptions) == -1) {
        if (output == 'string') {
          if (field == 'content') {
            value = value.replace(/\s/g,"+");
          }

          if (field == 'ss_language') {
               var separator = '';
          }
          else {
            var separator = '&';
          }
            searchValues = searchValues + separator + field + '=' + value;
        }
            else if (output == 'object') {
              searchValues[field] = value;
            }
      }
    });

    return searchValues;
  }

  /**
   * Shortens stings.
   *
   * @params array default search values
   *
   * @return string
   */
  Drupal.behaviors.budg_theme.wordTrim = function(value, length, overflowSuffix) {
    if (value.length <= length) {
      return value;
    }
      var strAry = value.split(' ');
      var retLen = strAry[0].length;
    for (var i = 1; i < strAry.length; i++) {
      if (retLen == length || retLen + strAry[i].length + 1 > length) {
        break;
      }
        retLen += strAry[i].length + 1
    }
      return strAry.slice(0,i).join(' ') + (overflowSuffix || '');
  }
})(jQuery, Drupal, this, this.document);
