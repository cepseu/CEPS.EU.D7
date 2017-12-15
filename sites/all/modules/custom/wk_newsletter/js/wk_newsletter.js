;(function($) {
  Drupal.behaviors.newsletterSubscription = {
    attach: function (context, settings) {

      $('#mc_embed_signup .input-group .type').each(function() {

        var $this = $(this);
        var $subjects = $(this).find('li').not('.extended').find('input');
        var totalChecked = 0;

        $(this).find('.extended input').change(function() {
          if ($(this).is(':checked')) {
            $subjects.attr('disabled', 'disabled')
                     .removeAttr('checked')
                     .parent().addClass('disabled');
            totalChecked = 0;
          } else {
            $subjects.attr('disabled', '')
                     .parent().removeClass('disabled');
          }
        });

        $(this).find('li').not('.extended').find('input').change(function() {
          if ($(this).is(':checked')) {
            totalChecked += 1;
          } else {
            totalChecked -= 1;
          }
          if (totalChecked > 2) {
            $this.find('.extended input').attr('checked', 'checked');
            $subjects.attr('disabled', 'disabled')
                     .removeAttr('checked')
                     .parent().addClass('disabled');
            totalChecked = 0;
          }
        });

      });
    }
  }
})(jQuery);