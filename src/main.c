#include <pebble.h>
#include "main.h"


static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_geo_layer;
static TextLayer *s_g_layer;


static GFont s_geo_font;
static GFont s_time_font;


static void update_time() {
  // Get a tm structure
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  // Write the current hours and minutes into a buffer
  static char s_buffer[8];
  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ?
                                          "%H:%M" : "%I:%M", tick_time);

  static char s_g_buffer[8];
  strftime(s_g_buffer,sizeof(s_g_buffer),"%M",tick_time);
  
  int i = atoi(s_g_buffer);
 // APP_LOG(APP_LOG_LEVEL_DEBUG, "s_g now %s", s_g_buffer);

 // APP_LOG(APP_LOG_LEVEL_DEBUG, "int i now %d", i);

  switch(i) {
    
    case 1 :
    case 2 :
    text_layer_set_text(s_geo_layer, "b");
    text_layer_set_text(s_g_layer, "b");
    break; 
    case 3 :
    case 4 :
    text_layer_set_text(s_geo_layer, "g");
    text_layer_set_text(s_g_layer, "ge");
    break; 
    case 5 :
    case 6 :
    text_layer_set_text(s_geo_layer, "d");
    text_layer_set_text(s_g_layer, "d");
    break; 
    case 7 :
    case 8 :
    text_layer_set_text(s_geo_layer, "e");
    text_layer_set_text(s_g_layer, "e");
    break; 
    case 9 :
    case 10 :
    text_layer_set_text(s_geo_layer, "v");
    text_layer_set_text(s_g_layer, "v");
    break; 
    case 11 :
    case 12 :
    text_layer_set_text(s_geo_layer, "z");
    text_layer_set_text(s_g_layer, "z");
    break; 
    case 13 :
    case 14 :
    text_layer_set_text(s_geo_layer, "Tt");
    text_layer_set_text(s_g_layer, "Tt");
    break; 
    case 15 :
    case 16 :
    text_layer_set_text(s_geo_layer, "i");
    text_layer_set_text(s_g_layer, "i");
    break; 
    case 17 :
    case 18 :
    text_layer_set_text(s_geo_layer, "qk");
    text_layer_set_text(s_g_layer, "qk");
    break; 
    case 19 :
    case 20 :
    text_layer_set_text(s_geo_layer, "l");
    text_layer_set_text(s_g_layer, "l");
    break; 
    case 21 :
    case 22 :
    text_layer_set_text(s_geo_layer, "m");
    text_layer_set_text(s_g_layer, "m");
    break; 
    case 23 :
    case 24 :
    text_layer_set_text(s_geo_layer, "n");
    text_layer_set_text(s_g_layer, "n");
    break; 
    case 25 :
    case 26 :
    text_layer_set_text(s_geo_layer, "o");
    text_layer_set_text(s_g_layer, "o");
    break; 
    case 27 :
    case 28 :
    text_layer_set_text(s_geo_layer, "fp");
    text_layer_set_text(s_g_layer, "fp");
    break; 
    case 29 :
    case 30 :
    text_layer_set_text(s_geo_layer, "J");
    text_layer_set_text(s_g_layer, "zh");
    break; 
    case 31 :
    case 32 :
    text_layer_set_text(s_geo_layer, "r");
    text_layer_set_text(s_g_layer, "r");
    break; 
    case 33 :
    case 34 :
    text_layer_set_text(s_geo_layer, "s");
    text_layer_set_text(s_g_layer, "s");
    break; 
    case 35 :
    case 36 :
    text_layer_set_text(s_geo_layer, "u");
    text_layer_set_text(s_g_layer, "u");
    break; 
    case 37 :
    case 38 :
    text_layer_set_text(s_geo_layer, "R");
    text_layer_set_text(s_g_layer, "gh");
    break; 
    case 39 :
    case 40 :
    text_layer_set_text(s_geo_layer, "y");
    text_layer_set_text(s_g_layer, "G'");
    break; 
    case 41 :
    case 42 :
    text_layer_set_text(s_geo_layer, "S");
    text_layer_set_text(s_g_layer, "sh");
    break; 
    case 43 :
    case 44 :
    text_layer_set_text(s_geo_layer, "C");
    text_layer_set_text(s_g_layer, "ch");
    break; 
    case 45 :
    case 46 :
    text_layer_set_text(s_geo_layer, "c");
    text_layer_set_text(s_g_layer, "ts");
    break; 
    case 47 :
    case 48 :
    text_layer_set_text(s_geo_layer, "Z");
    text_layer_set_text(s_g_layer, "dz");
    break; 
    case 49 :
    case 50 :
    text_layer_set_text(s_geo_layer, "w");
    text_layer_set_text(s_g_layer, "tz");
    break; 
    case 51 :
    case 52 :
    text_layer_set_text(s_geo_layer, "W");
    text_layer_set_text(s_g_layer, "tc");
    break; 
    case 53 :
    case 54 :
    text_layer_set_text(s_geo_layer, "x");
    text_layer_set_text(s_g_layer, "kh");
    break; 
    case 55 :
    case 56 :
    text_layer_set_text(s_geo_layer, "j");
    text_layer_set_text(s_g_layer, "j");
    break; 
    case 57 :
    case 58 :
    text_layer_set_text(s_geo_layer, "h");
    text_layer_set_text(s_g_layer, "h");
    break; 
    case 59 :
    case 0 :
    text_layer_set_text(s_geo_layer, "a");
    text_layer_set_text(s_g_layer, "a");
    break; 
  
   default : 
    text_layer_set_text(s_geo_layer, "-");
    text_layer_set_text(s_g_layer, "-");
   }
    
  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, s_buffer);
    text_layer_set_text_alignment(s_geo_layer, GTextAlignmentCenter);

    text_layer_set_text_alignment(s_g_layer, GTextAlignmentCenter);


}


static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  // Create the TextLayer with specific bounds
  s_time_layer = text_layer_create(
      GRect(0, PBL_IF_ROUND_ELSE(100, 100), bounds.size.w, 50));

  s_geo_layer = text_layer_create(     
      GRect(0, PBL_IF_ROUND_ELSE(0,0), bounds.size.w/2, 70));

   s_g_layer = text_layer_create(     
      GRect(65, PBL_IF_ROUND_ELSE(0,0), bounds.size.w/2, 70));

  text_layer_set_font(s_geo_layer, s_geo_font);
  text_layer_set_background_color(s_geo_layer, GColorClear);
  text_layer_set_text_color(s_geo_layer, GColorBlack);
  text_layer_set_text(s_geo_layer,"A");
  
  layer_add_child(window_layer,text_layer_get_layer(s_geo_layer));
  
  
  text_layer_set_font(s_g_layer, s_time_font);
  text_layer_set_background_color(s_g_layer, GColorClear);
  text_layer_set_text_color(s_g_layer, GColorBlack);
  text_layer_set_text(s_g_layer,"_");
  
  layer_add_child(window_layer,text_layer_get_layer(s_g_layer));
    
  
  // Improve the layout to be more like a watchface
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  text_layer_set_text(s_time_layer, "00:00");
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
}

static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void init() {
  
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  // Make sure the time is displayed from the start
update_time();
  // Register with TickTimerService
tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
 // tick_timer_service_subscribe(SECOND_UNIT, tick_handler);
  // Create GFont
s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_PERFECT_DOS_48));
s_geo_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_GEORGIAN_BOLD_SUBSET_48));

// Apply to TextLayer
text_layer_set_font(s_time_layer, s_time_font);
text_layer_set_font(s_g_layer, s_time_font);
text_layer_set_font(s_geo_layer, s_geo_font);


}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
  // Unload GFont
  fonts_unload_custom_font(s_time_font);
  fonts_unload_custom_font(s_geo_font);


}


int main(void) {
  init();
  app_event_loop();
  deinit();
}
