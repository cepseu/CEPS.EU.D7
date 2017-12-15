;(function($) {

  "use strict";

  $.fn.equalizeHeights = function () {

    return this.height(Math.max.apply(this, this.map(function () {
      var $this = $(this).css('height', 'auto');
      return $this.outerHeight(true);
    })));
  };

  var debounce = function(func, wait, immediate) {
    var timeout;
    return function() {
      var context = this, args = arguments;
      var later = function() {
        timeout = null;
        if (!immediate) func.apply(context, args);
      };
      var callNow = immediate && !timeout;
      clearTimeout(timeout);
      timeout = setTimeout(later, wait);
      if (callNow) func.apply(context, args);
    };
  };

  Drupal.behaviors.searchShow = {
    attach: function (context, settings) {
      $('.open-search').once('searchShow').click(function(e) {
        $(this).parents('header').toggleClass('with-search');
        e.preventDefault();
      });
    }
  };


  Drupal.behaviors.eventShow = {
    attach: function(context, settings) {
      var that = this;

var group = $(".group-sidebar-left > .group-right");
var day = group.find(".formatted-date-number").text();
var time = group.find(".formatted-date-time-from").text();
var month_year = group.find(".formatted-date-month-year").text().split(" ");
var month = month_year[0];
var year  = month_year[1];
var date  = month + " " + day + ", " + year + ' ' + time;
var event_date = new Date(date);
var curr_date  = new Date();

var xid = group.find('.field-name-field-event1-id').text();



if (curr_date <= event_date) {
   var butt = '<a class="link-button arrow" href="/civicrm/event/register?id=' + xid + '&reset=1">' + Drupal.t('Register') + '</a>';
}
else {
   var butt = '';
}

    $('.field-name-field-event1-id').children().replaceWith(butt);
    },
  };

Drupal.behaviors.equalizeHeights = {
    attach: function(context) {
      $(window).bind('resize', debounce(this.resizeHandler.bind(this), 200)).resize();
    },
    resizeHandler: function() {
      for (var i = 0, max = this.selectors.length; i<max; i++) {
        $(this.selectors[i]).addClass('equalizeHeights-processed').equalizeHeights();
      }
    },
    selectors: [
      '.view-id-frontpage_items.view-display-id-panel_pane_1 .view-mode-special > a'
    ]
  };

})(jQuery);
