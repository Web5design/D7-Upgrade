Drupal.behaviors.Issues = function () {
  // Expand/close child issues
  $('#issues a.open').click(function() {
    $children = $(this).parent().next();
    if ($children.css('display') == 'none') {
      $('#issues ul.children').hide();
      $('#issues div.expanded').removeClass('expanded');
      $(this).parent().addClass('expanded');
      $children.show();
    }
    else {
      $(this).parent().removeClass('expanded');
      $('#issues ul.children').hide();
    }
    return false;
  });
}
