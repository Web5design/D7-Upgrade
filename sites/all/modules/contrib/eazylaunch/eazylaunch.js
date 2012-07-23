// $Id: eazylaunch.js,v 1.1.2.3 2010/08/16 19:23:47 tdway Exp $
(function ($) {

Drupal.behaviors.eazylaunch = {
  attach: function (context, settings) {
	if ($('#eazylaunch-div').length > 0) return true; //don't load eazylaunch if it's already on the page
	
	$.getJSON(Drupal.settings.basePath + "eazylaunch/js", function (data){
		//init eazylaunch html
		var content = '<input id="eazylaunch-input"/><div id="eazylaunch-desc"><span id="el-details"></span> <a id="el-more-link" href="#">more help...</a><div id="el-more"></div></div>';
		$('body #el-wrap').remove();
		$('body').append('<div id="el-wrap"><div id="eazylaunch-div"><div id="el-block"><h2>EazyLaunch</h2>'+content+'</div></div></div>');
		
		$('#el-details').html(data.eazylaunch.details);
		$('#el-more-link').click(function() { 
			$('#el-more').html(data.eazylaunch.moreDetails); 
			$('#eazylaunch-input').focus().select();
		});
		
		//handle keydown events
		$(document).keydown(function (e) {
		  if (!e) e = window.event;
		  var ctrlZ = e.keyCode == "Z".charCodeAt(0) && e.ctrlKey;
		  var esc = e.keyCode == 27; //esc key
		  if (!ctrlZ && !esc) return true;
		  var el = $('#eazylaunch-div');
		   
		  if (ctrlZ && $(el).is(':hidden')) {
			$(el).show();
			$('#eazylaunch-input').focus().select();
		    return false;
		  } else if (ctrlZ || esc) $(el).hide(); 
		  else return true;
		});
		
		//init eazylaunch autocomplete
		$("#eazylaunch-input").ezautocomplete(data.eazylaunch.links, {
			formatItem : function(item) {
				return item.title;
			},
			formatMatch : function(item) {
				var title = item.title;
				if (item.root) return '? '+title;
				else return title;
			},
			scrollHeight : 550,
			matchContains : 1,
			minChars : 0,
			max : 25
		}).result(function(event, item) {
			$('#eazylaunch-div').hide();
			if (item.href.indexOf("eazylaunch/action") >= 0) { //add destination to eazylaunch actions
				item.href += "?destination="+location.pathname.substr(Drupal.settings.basePath.length);
			}
			if (Drupal.settings.eazylaunch.disable_overlay != 1 && !$('body').hasClass('page-admin')){
				location.href = '#overlay=' + item.href;
			}
			else {
				location.href = Drupal.settings.basePath + item.href;
			}
		});
	});
  }
}
	
}(jQuery));