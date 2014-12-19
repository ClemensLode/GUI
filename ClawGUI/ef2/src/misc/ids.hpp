#ifndef _MISC_IDS_HPP
#define _MISC_IDS_HPP

#pragma warning(push, 0) 
#include <boost/uuid/uuid.hpp>
#include <misc/miscellaneous.hpp>
#pragma warning(pop)

struct IDS
{

	static const boost::uuids::uuid ENGLISH_LANGUAGE_ID;
	static const boost::uuids::uuid GERMAN_LANGUAGE_ID;

	static const boost::uuids::uuid EMPTY_TEXT_ID;

	static const boost::uuids::uuid START_INIT_SDL_TEXT_ID;
	static const boost::uuids::uuid START_SET_FULLSCREEN_MODE_TEXT_ID;
	static const boost::uuids::uuid START_SET_WINDOW_MODE_TEXT_ID;
	static const boost::uuids::uuid START_UNABLE_TO_INIT_SDL_TEXT_ID;
	static const boost::uuids::uuid START_ERROR_SETTING_VIDEO_MODE_TEXT_ID;
	static const boost::uuids::uuid START_CREATED_SURFACE_TEXT_ID;
	static const boost::uuids::uuid START_INIT_SDL_TRUETYPE_FONTS_TEXT_ID;
	static const boost::uuids::uuid START_INIT_SDL_TTF_ERROR_TEXT_ID;
	static const boost::uuids::uuid START_LOAD_CONFIGURATION_TEXT_ID;
	static const boost::uuids::uuid END_RESET_MOUSE_CURSOR_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_COLORS_BRUSHES_PENS_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_BITMAPS_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_ANIMATIONS_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_COORDINATES_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_BUTTONS_TEXT_ID;
	static const boost::uuids::uuid END_FREEING_FONTS_TEXT_ID;
	static const boost::uuids::uuid START_SDL_NO_MODES_AVAILABLE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_ALL_RESOLUTIONS_AVAILABLE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_AVAILABLE_MODES_TEXT_ID;
	static const boost::uuids::uuid START_SDL_MAX_COLOR_DEPTH_TEXT_ID;
	static const boost::uuids::uuid START_SDL_HARDWARE_SURFACES_POSSIBLE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_WINDOW_MANAGER_AVAILABLE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SOFTWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SOFTWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SOFTWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_HARDWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_HARDWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_HARDWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_COLOR_FILLS_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_TOTAL_VIDEO_MEMORY_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_STORED_IN_SYSTEM_MEMORY_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_STORED_IN_VIDEO_MEMORY_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_USES_ASYNCHRONOUS_BLITS_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_ALLOWS_ANY_PIXEL_FORMAT_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_HAS_EXCLUSIVE_PALETTE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_IS_DOUBLE_BUFFERED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_HAS_OPENGL_CONTEXT_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_SUPPORTS_OPENGL_BLITTING_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_IS_RESIZABLE_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_BLIT_USES_HARDWARE_ACCELERATION_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_USES_COLORKEY_BLITTING_TEXT_ID;
	static const boost::uuids::uuid START_SDL_COLORKEY_BLITTING_RLE_ACCELERATED_TEXT_ID;
	static const boost::uuids::uuid START_SDL_BLIT_USES_ALPHA_BLENDING_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_USES_PREALLOCATED_MEMORY_TEXT_ID;
	static const boost::uuids::uuid START_SDL_SURFACE_NEEDS_LOCKING_TEXT_ID;
	static const boost::uuids::uuid END_RELEASING_SOUND_ENGINE_TEXT_ID;
	static const boost::uuids::uuid END_CLOSING_SOUND_ENGINE_TEXT_ID;
	static const boost::uuids::uuid START_INIT_SOUND_TEXT_ID;
	static const boost::uuids::uuid START_INIT_FMOD_SYSTEM_CREATE_ERROR_TEXT_ID;
	static const boost::uuids::uuid START_INIT_FMOD_GET_VERSION_ERROR_TEXT_ID;
	static const boost::uuids::uuid START_INIT_FMOD_VERSION_ERROR_TEXT_ID;
	static const boost::uuids::uuid START_INIT_FMOD_SYSTEM_INIT_ERROR_TEXT_ID;
	static const boost::uuids::uuid START_INIT_NOSOUND_TEXT_ID;
	static const boost::uuids::uuid WELCOME_TEXT_ID;
	static const boost::uuids::uuid FPS_TEXT_ID;
	static const boost::uuids::uuid CHANGED_BIT_DEPTH_TEXT_ID;
	static const boost::uuids::uuid CHANGED_RESOLUTION_TEXT_ID;

	static const boost::uuids::uuid START_INIT_MAIN_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_HELP_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_SETTINGS_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_DATABASE_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_MAP_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_MSG_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_INTRO_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_INIT_TECHTREE_WINDOW_TEXT_ID;
	static const boost::uuids::uuid START_HIDING_WINDOWS_TEXT_ID;

	static const boost::uuids::uuid START_PREPARE_FIRST_RUN_TEXT_ID;
	static const boost::uuids::uuid START_CHOOSING_GAME_TAB_TEXT_ID;
	static const boost::uuids::uuid START_CREATING_GAME_TEXT_ID;

	static const boost::uuids::uuid MAIN_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid INTRO_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid MESSAGE_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid HELP_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid SETTINGS_WINDOW_TITLE_TEXT_ID; 
	static const boost::uuids::uuid MAP_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid DATABASE_WINDOW_TITLE_TEXT_ID;
	
	static const boost::uuids::uuid INFO_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid TECHTREE_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid DEBUG_WINDOW_TITLE_TEXT_ID;
	
	static const boost::uuids::uuid BOGRAPH_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid BODIAGRAM_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid STATISTICS_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid TIMER_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid FORCE_WINDOW_TITLE_TEXT_ID; // 10
	static const boost::uuids::uuid BOWINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid GAME_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid PLAYER_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid SCORE_WINDOW_TITLE_TEXT_ID;

	static const boost::uuids::uuid GAME_NUMBER_TEXT_ID;
	static const boost::uuids::uuid NEW_GAME_TEXT_ID;
	
// message window:
	static const boost::uuids::uuid WELCOME_MSG1_TEXT_ID;
	static const boost::uuids::uuid WELCOME_MSG2_TEXT_ID;
	static const boost::uuids::uuid PLAYERS_LOADED_TEXT_ID;
	static const boost::uuids::uuid ADDED_GOAL_TEXT_ID;
	static const boost::uuids::uuid SET_NEW_GOAL_LIST_TEXT_ID;
	static const boost::uuids::uuid SET_NEW_MAP_TEXT_ID;
	static const boost::uuids::uuid SET_RACE_TEXT_ID;
	static const boost::uuids::uuid ADDED_ONE_GOAL_TEXT_ID;
	static const boost::uuids::uuid REMOVED_ONE_GOAL_TEXT_ID;
	static const boost::uuids::uuid MOVED_NON_GOAL_TEXT_ID;
	static const boost::uuids::uuid SAVED_GOAL_TEXT_ID;
	static const boost::uuids::uuid SAVED_BUILD_ORDER_TEXT_ID;

// game window:
	static const boost::uuids::uuid COMPARE_GAME_TEXT_ID;
	static const boost::uuids::uuid REMOVE_GAME_TEXT_ID;

// help window:
	static const boost::uuids::uuid HELP_WINDOW_INDEX_TEXT_ID;
	static const boost::uuids::uuid HELP_WINDOW_BACK_TEXT_ID;
	
// edit field window:
	static const boost::uuids::uuid SAVE_BOX_OK_TEXT_ID;
	static const boost::uuids::uuid SAVE_BOX_CANCEL_TEXT_ID;

// debug window:
	static const boost::uuids::uuid DRAW_TICKS_TEXT_ID;
	static const boost::uuids::uuid GENERATION_TICKS_TEXT_ID;
	static const boost::uuids::uuid PROCESS_TICKS_TEXT_ID;
	static const boost::uuids::uuid MESSAGE_TICKS_TEXT_ID;
	static const boost::uuids::uuid SOUND_TICKS_TEXT_ID;
	static const boost::uuids::uuid IDLE_TICKS_TEXT_ID;
	static const boost::uuids::uuid FPS_TEXT_TEXT_ID;
	static const boost::uuids::uuid GPS_TEXT_TEXT_ID;

	
// force window:
	static const boost::uuids::uuid STARTING_FORCE_TEXT_ID;
	static const boost::uuids::uuid NON_GOALS_TEXT_ID;
	static const boost::uuids::uuid GOALS_TEXT_ID;
	static const boost::uuids::uuid LEGEND_TEXT_ID;
	static const boost::uuids::uuid TIME_LEGEND_TEXT_ID;
	static const boost::uuids::uuid CLICK_TO_ADD_GOAL_TEXT_ID; //30
	static const boost::uuids::uuid BACK_TEXT_ID;
	static const boost::uuids::uuid CLOSE_TEXT_ID;
	static const boost::uuids::uuid ADD_GOAL_TEXT_ID;
	static const boost::uuids::uuid GOAL_LIST_TEXT_ID;
	static const boost::uuids::uuid STARTFORCE_TEXT_ID;
	static const boost::uuids::uuid CHOOSE_RACE_TEXT_ID;
	
	static const boost::uuids::uuid CHOOSE_MAP_TEXT_ID;

	static const boost::uuids::uuid SAVE_GOAL_TEXT_ID;

	static const boost::uuids::uuid SAVE_GOALS_AS_TEXT_ID;
	static const boost::uuids::uuid GIVE_GOAL_A_NAME_TEXT_ID;

	static const boost::uuids::uuid CHOOSE_GOAL_NAME_TEXT_ID;
	
	static const boost::uuids::uuid SAVE_BUILD_ORDER_AS_TEXT_ID;
	static const boost::uuids::uuid GIVE_BO_A_NAME_TEXT_ID; //40


// bowindow
	static const boost::uuids::uuid CLICK_TO_INSERT_ORDER_TEXT_ID; //44
//	CLICK_TO_CLOSE_ORDER_TEXT_ID; schon in force definiert
//	CLICK_TO_GO_BACK_TEXT_ID;

	static const boost::uuids::uuid OPTIMIZE_EVERYTHING_TEXT_ID;
	static const boost::uuids::uuid OPTIMIZE_SELECTED_TEXT_ID;
	static const boost::uuids::uuid RESET_BUILD_ORDER_TEXT_ID;
	static const boost::uuids::uuid SAVE_BUILD_ORDER_TEXT_ID;
	static const boost::uuids::uuid LOAD_BUILD_ORDER_TEXT_ID;

	static const boost::uuids::uuid BOWINDOW_BUILD_TIME_TEXT_ID;
	static const boost::uuids::uuid BOWINDOW_EACH_TOTAL_TEXT_ID;

	static const boost::uuids::uuid PLAYER_TEXT_ID;
	static const boost::uuids::uuid SPEED_TEXT_ID;
	
// timer window
	static const boost::uuids::uuid OF_GOALS_FULFILLED_TEXT_ID; //50
	static const boost::uuids::uuid OF_TIME_FULFILLED_TEXT_ID;
	static const boost::uuids::uuid PAUSED_TEXT_ID;
	static const boost::uuids::uuid SEARCHING_TEXT_ID;
	static const boost::uuids::uuid THEORETICAL_OPTIMUM_TEXT_ID;
	static const boost::uuids::uuid OPTIMIZING_TEXT_ID;
	static const boost::uuids::uuid RES_UNITS_STRUCT_TEXT_ID;
	static const boost::uuids::uuid TOTAL_TEXT_ID;

	static const boost::uuids::uuid ADD_PLAYER_TEXT_ID;

// Tabs
	static const boost::uuids::uuid HELP_TAB_TEXT_ID;
	static const boost::uuids::uuid SETTINGS_TAB_TEXT_ID;
	static const boost::uuids::uuid DATABASE_TAB_TEXT_ID;
	static const boost::uuids::uuid MAP_TAB_TEXT_ID; 

// tooltips
	static const boost::uuids::uuid ADD_UNIT_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid REMOVE_UNIT_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid REMOVE_GOAL_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid CHOOSE_RACE_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid ADD_GOALS_TOOLTIP_TEXT_ID; // 90
	static const boost::uuids::uuid CHOOSE_GOALS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid CHOOSE_STARTING_FORCE_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid SAVE_GOAL_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid RESET_BUILD_ORDER_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SAVE_BUILD_ORDER_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid LOAD_BUILD_ORDER_TOOLTIP_TEXT_ID;

// timer:
	static const boost::uuids::uuid CONTINUE_OPTIMIZATION_TOOLTIP_TEXT_ID; 
	static const boost::uuids::uuid PAUSE_OPTIMIZATION_TOOLTIP_TEXT_ID; 
	static const boost::uuids::uuid OF_GOALS_FULFILLED_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid OF_TIME_FULFILLED_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid HELP_TAB_TOOLTIP_TEXT_ID;	
	static const boost::uuids::uuid SETTINGS_TAB_TOOLTIP_TEXT_ID; //110
	static const boost::uuids::uuid DATABASE_TAB_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid MAP_TAB_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid FORCEENTRY_TIME_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid FORCEENTRY_ALWAYS_BUILD_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid FORCEENTRY_BUILD_MUCH_TOOLTIP_TEXT_ID;

// settings:
	static const boost::uuids::uuid SETTING_FAST_CALCULATION_TEXT_ID;
	static const boost::uuids::uuid SETTING_ALLOW_WAIT_ORDERS_TEXT_ID;
	static const boost::uuids::uuid SETTING_WAIT_ACCURACY_TEXT_ID;
	static const boost::uuids::uuid SETTING_GAME_SPEED_TEXT_ID;
	static const boost::uuids::uuid SETTING_AUTO_RUNS_TEXT_ID;
	static const boost::uuids::uuid SETTING_MAX_GENERATIONS_TEXT_ID;

	static const boost::uuids::uuid SETTING_USE_MUSIC_TEXT_ID;
	static const boost::uuids::uuid SETTING_USE_SOUND_TEXT_ID;
	static const boost::uuids::uuid SETTING_MUSIC_VOLUME_TEXT_ID;
	static const boost::uuids::uuid SETTING_SOUND_VOLUME_TEXT_ID;
	static const boost::uuids::uuid SETTING_CHANNELS_TEXT_ID;
	
	static const boost::uuids::uuid SETTING_BACKGROUND_BITMAP_TEXT_ID;
	static const boost::uuids::uuid SETTING_SMOOTH_MOVEMENT_TEXT_ID;
	static const boost::uuids::uuid SETTING_WAIT_AFTER_CHANGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_TOOLTIPS_TEXT_ID;
	static const boost::uuids::uuid SETTING_DNA_SPIRAL_TEXT_ID;
	static const boost::uuids::uuid SETTING_RACE_SPECIFIC_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_GLOWING_BUTTONS_TEXT_ID;
	static const boost::uuids::uuid SETTING_COMPACT_DISPLAY_MODE_TEXT_ID;
	static const boost::uuids::uuid SETTING_FACILITY_MODE_TEXT_ID;

	static const boost::uuids::uuid SETTING_FULLSCREEN_TEXT_ID;
	static const boost::uuids::uuid SETTING_UNLOAD_GRAPHICS_TEXT_ID;
	static const boost::uuids::uuid SETTING_SHOW_DEBUG_TEXT_ID;
	static const boost::uuids::uuid SETTING_DESIRED_FRAMERATE_TEXT_ID;
	static const boost::uuids::uuid SETTING_DESIRED_CPU_USAGE_TEXT_ID;

	static const boost::uuids::uuid SETTING_RELOAD_FROM_FILE_TEXT_ID;
	static const boost::uuids::uuid SETTING_SAVE_TO_FILE_TEXT_ID;
	static const boost::uuids::uuid SETTING_LOAD_DEFAULTS_TEXT_ID;

// tooltips	
	static const boost::uuids::uuid SETTING_FAST_CALCULATION_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_ALLOW_WAIT_ORDERS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_WAIT_ACCURACY_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_GAME_SPEED_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_AUTO_RUNS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_MAX_GENERATIONS_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid SETTING_USE_MUSIC_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_USE_SOUND_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_MUSIC_VOLUME_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_SOUND_VOLUME_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_CHANNELS_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid SETTING_BACKGROUND_BITMAP_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_SMOOTH_MOVEMENT_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_WAIT_AFTER_CHANGE_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_TOOLTIPS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_DNA_SPIRAL_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_RACE_SPECIFIC_THEME_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_GLOWING_BUTTONS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_COMPACT_DISPLAY_MODE_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_FACILITY_MODE_TOOLTIP_TEXT_ID;
	
	static const boost::uuids::uuid SETTING_FULLSCREEN_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_UNLOAD_GRAPHICS_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_SHOW_DEBUG_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_DESIRED_FRAMERATE_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid SETTING_DESIRED_CPU_USAGE_TOOLTIP_TEXT_ID;

	static const boost::uuids::uuid SETTINGS_SAVED_TEXT_ID;

	static const boost::uuids::uuid LANGUAGE_HAS_CHANGED_TEXT_ID;
	
	static const boost::uuids::uuid SETTING_LANGUAGE_TEXT_ID; //160
	static const boost::uuids::uuid SETTING_ZERO_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_ENGLISH_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_GERMAN_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_ITALIAN_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_PORTUGESE_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_DUTCH_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_FINNISH_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_GREEK_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_FRENCH_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_SPANISH_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_POLSKI_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_KOREAN_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_CHINESE_LANGUAGE_TEXT_ID;
	static const boost::uuids::uuid SETTING_RUSSIAN_LANGUAGE_TEXT_ID; //170

	static const boost::uuids::uuid SETTING_RESOLUTION_TEXT_ID;
	static const boost::uuids::uuid SETTING_RESOLUTION_ZERO_TEXT_ID;
	static const boost::uuids::uuid SETTING_RESOLUTION_640x480_TEXT_ID;
	static const boost::uuids::uuid SETTING_RESOLUTION_800x600_TEXT_ID;
	static const boost::uuids::uuid SETTING_RESOLUTION_1024x768_TEXT_ID;
	static const boost::uuids::uuid SETTING_RESOLUTION_1280x1024_TEXT_ID;

	static const boost::uuids::uuid SETTING_BITDEPTH_TEXT_ID;
	static const boost::uuids::uuid SETTING_DEPTH_8BIT_TEXT_ID;
	static const boost::uuids::uuid SETTING_DEPTH_16BIT_TEXT_ID;
	static const boost::uuids::uuid SETTING_DEPTH_24BIT_TEXT_ID;
	static const boost::uuids::uuid SETTING_DEPTH_32BIT_TEXT_ID;
				
	static const boost::uuids::uuid SETTING_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_ZERO_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_DARK_RED_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_DARK_BLUE_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_GREEN_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_YELLOW_THEME_TEXT_ID;
	static const boost::uuids::uuid SETTING_GREY_THEME_TEXT_ID;

	static const boost::uuids::uuid SETWINDOW_CORE_SETTINGS_TEXT_ID;
	static const boost::uuids::uuid SETWINDOW_SOUND_SETTINGS_TEXT_ID;
	static const boost::uuids::uuid SETWINDOW_GUI_SETTINGS_TEXT_ID;
	static const boost::uuids::uuid SETWINDOW_GRAPHIC_SETTINGS_TEXT_ID;
	
	static const boost::uuids::uuid SETWINDOW_UI_SETTINGS_TEXT_ID;
	static const boost::uuids::uuid SETWINDOW_LOADSAVE_SETTINGS_TEXT_ID;

	static const boost::uuids::uuid DATA_ENTRY_OPEN_BUTTON_TOOLTIP_TEXT_ID;
	static const boost::uuids::uuid DATA_ENTRY_CHECK_BUTTON_TOOLTIP_TEXT_ID;

	// ------- TEXTS END --------

	// ------ BITMAPS ------
	static const boost::uuids::uuid NULL_BITMAP_ID;
	static const boost::uuids::uuid INCREASE_BITMAP_ID;
	static const boost::uuids::uuid SUB_BITMAP_ID;
	static const boost::uuids::uuid CANCEL_BITMAP_ID;
	static const boost::uuids::uuid SMALL_ARROW_LEFT_BITMAP_ID;
	static const boost::uuids::uuid SMALL_ARROW_RIGHT_BITMAP_ID;
	static const boost::uuids::uuid SMALL_ARROW_UP_BITMAP_ID;
	static const boost::uuids::uuid SMALL_ARROW_DOWN_BITMAP_ID;
	static const boost::uuids::uuid LOCATION_BUTTON_BITMAP_ID;
	static const boost::uuids::uuid TIME_BUTTON_BITMAP_ID;

	static const boost::uuids::uuid BLUE_RADIO_OFF_BITMAP_ID;
	static const boost::uuids::uuid BLUE_RADIO_ON_BITMAP_ID;
	static const boost::uuids::uuid RED_RADIO_OFF_BITMAP_ID;
	static const boost::uuids::uuid RED_RADIO_ON_BITMAP_ID;
	static const boost::uuids::uuid YELLOW_RADIO_OFF_BITMAP_ID;
	static const boost::uuids::uuid YELLOW_RADIO_ON_BITMAP_ID;
	static const boost::uuids::uuid GREY_RADIO_OFF_BITMAP_ID;
	static const boost::uuids::uuid GREYRADIO_ON_BITMAP_ID;

	static const boost::uuids::uuid BACKGROUND_SC_BITMAP_ID;
	static const boost::uuids::uuid BACKGROUND1_SC2_BITMAP_ID;
	static const boost::uuids::uuid BACKGROUND2_SC2_BITMAP_ID;

	static const boost::uuids::uuid BAR_BITMAP_ID;
	static const boost::uuids::uuid KEY_BITMAP_ID;

	static const boost::uuids::uuid CLAWSOFTWARE_BITMAP_ID;
	static const boost::uuids::uuid CLAWSOFTWARE_MONO_BITMAP_ID;

	static const boost::uuids::uuid NEW_BITMAP_ID;
	static const boost::uuids::uuid LOAD_BITMAP_ID; 
	static const boost::uuids::uuid SAVE_BITMAP_ID; 
	static const boost::uuids::uuid REFRESH_BITMAP_ID; 

	static const boost::uuids::uuid BACK_BITMAP_ID;
	static const boost::uuids::uuid FORWARD_BITMAP_ID; 
	static const boost::uuids::uuid ADD_BITMAP_ID; 
	static const boost::uuids::uuid DELETE_BITMAP_ID; 

	static const boost::uuids::uuid HELP_BITMAP_ID; 
	static const boost::uuids::uuid MAP_BITMAP_ID;
	static const boost::uuids::uuid SETTING_BITMAP_ID; 

	static const boost::uuids::uuid BLUE_BULLET_BITMAP_ID; 
	static const boost::uuids::uuid RED_BULLET_BITMAP_ID; 
	static const boost::uuids::uuid YELLOW_BULLET_BITMAP_ID; 

	static const boost::uuids::uuid ARROW_LEFT_BITMAP_ID;
	static const boost::uuids::uuid ARROW_RIGHT_BITMAP_ID;
	static const boost::uuids::uuid ARROW_UP_BITMAP_ID;
	static const boost::uuids::uuid ARROW_DOWN_BITMAP_ID;

	static const boost::uuids::uuid CLICKED_SMALL_ARROW_LEFT_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_SMALL_ARROW_RIGHT_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_ARROW_LEFT_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_ARROW_RIGHT_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_SMALL_ARROW_UP_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_SMALL_ARROW_DOWN_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_ARROW_UP_BITMAP_ID;
	static const boost::uuids::uuid CLICKED_ARROW_DOWN_BITMAP_ID;


	static const boost::uuids::uuid INTRO_SDL_BITMAP_ID;
	static const boost::uuids::uuid INTRO_SDL_TTF_BITMAP_ID;
	static const boost::uuids::uuid INTRO_SDL_IMAGE_BITMAP_ID;
	static const boost::uuids::uuid INTRO_GUI_BITMAP_ID;
	static const boost::uuids::uuid INTRO_SMPEG_BITMAP_ID;
	static const boost::uuids::uuid INTRO_FMOD_BITMAP_ID;
	static const boost::uuids::uuid INTRO_SDL_MIXER_BITMAP_ID;

	static const boost::uuids::uuid CURSOR_ARROW_BITMAP_ID;
	static const boost::uuids::uuid CURSOR_HAND_BITMAP_ID;
	static const boost::uuids::uuid CURSOR_CLOCK1_BITMAP_ID;
	static const boost::uuids::uuid CURSOR_CLOCK2_BITMAP_ID;





	/*
	static const boost::uuids::uuid WINDOWCLOSE_BITMAP_ID;
	static const boost::uuids::uuid WINDOWCLOSE_DISABLED_BITMAP_ID;
	static const boost::uuids::uuid WINDOWCLOSE_PRESSED_BITMAP_ID;
	static const boost::uuids::uuid WINDOWCLOSE_HIGHLIGHT_BITMAP_ID;*/

	static const boost::uuids::uuid DEFAULT_GUI_CONFIGURATION_ID;
	static const boost::uuids::uuid DEFAULT_GUI_ID;
	static const boost::uuids::uuid DEFAULT_MAIN_CONFIGURATION_ID;

	// ----- COLORS -----
	static const boost::uuids::uuid NULL_COLOR_ID;
	static const boost::uuids::uuid TEXT_COLOR_ID;
	static const boost::uuids::uuid WINDOW_TEXT_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_TEXT_COLOR_ID;
	static const boost::uuids::uuid TITLE_COLOR_ID;
	static const boost::uuids::uuid IMPORTANT_COLOR_ID;

	// forcewindow
	static const boost::uuids::uuid NOT_FULFILLED_TEXT_COLOR_ID;
	static const boost::uuids::uuid FULFILLED_TEXT_COLOR_ID;

	static const boost::uuids::uuid FORCE_ADD_GOAL_TEXT_COLOR_ID;

	static const boost::uuids::uuid FORCE_TEXT_COLOR_ID; //~~

	static const boost::uuids::uuid BIG_BUTTONS_TEXT_COLOR_ID;

	// bodiagram
	static const boost::uuids::uuid BRIGHT_MINERALS_TEXT_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_GAS_TEXT_COLOR_ID;
	static const boost::uuids::uuid SUPPLY_TEXT_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_SUPPLY_TEXT_COLOR_ID;

	/*	static const boost::uuids::uuid MINERALS_COLOR_ID;
	static const boost::uuids::uuid GAS_COLOR_ID;
	static const boost::uuids::uuid SUPPLY_COLOR_ID;*/

	// bograph time steps font color
	static const boost::uuids::uuid TIMESTEPS_TEXT_COLOR_ID;	

	// statistics window
	static const boost::uuids::uuid MINERALS_TEXT_COLOR_ID;
	static const boost::uuids::uuid GAS_TEXT_COLOR_ID;
	static const boost::uuids::uuid TIME_TEXT_COLOR_ID;
	static const boost::uuids::uuid STATISTICS_FORCE_TEXT_COLOR_ID;
	static const boost::uuids::uuid BOLENGTH_TEXT_COLOR_ID;
	static const boost::uuids::uuid FITNESS_AVERAGE_TEXT_COLOR_ID;
	static const boost::uuids::uuid FITNESS_VARIANCE_TEXT_COLOR_ID;	
	static const boost::uuids::uuid GENERATIONS_LEFT_TEXT_COLOR_ID;

	static const boost::uuids::uuid FPS_TEXT_COLOR_ID;
	static const boost::uuids::uuid FITNESS_TEXT_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_FITNESS_TEXT_COLOR_ID;

	static const boost::uuids::uuid DISABLED_TEXT_COLOR_ID;
	static const boost::uuids::uuid DARK_IMPORTANT_COLOR_ID;



	static const boost::uuids::uuid NULL_PEN_COLOR_ID;
	static const boost::uuids::uuid BORDER_PEN_COLOR_ID;
	static const boost::uuids::uuid OUTER_BORDER_PEN_COLOR_ID;
	static const boost::uuids::uuid INNER_BORDER_PEN_COLOR_ID;
	static const boost::uuids::uuid INNER_BORDER_HIGHLIGHT_PEN_COLOR_ID;

	static const boost::uuids::uuid BIG_BUTTONS_PEN_COLOR_ID;
	static const boost::uuids::uuid RECTANGLE_PEN_COLOR_ID;
	static const boost::uuids::uuid BITMAP_MARKED_PEN_COLOR_ID;

	// bodiagram
	static const boost::uuids::uuid BODIAGRAM_DASHED_MINERALS_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_GAS_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_SUPPLY_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_MARKER_PEN_COLOR_ID;
	// bowindow
	static const boost::uuids::uuid SELECT_PEN_COLOR_ID;
	// transparent
	static const boost::uuids::uuid DARK_BACKGROUND_PEN_COLOR_ID;
	// buttons
	static const boost::uuids::uuid MARKED_BITMAP_GREEN_PEN_COLOR_ID;
	static const boost::uuids::uuid MARKED_BITMAP_YELLOW_PEN_COLOR_ID;
	static const boost::uuids::uuid MARKED_BITMAP_RED_PEN_COLOR_ID;
	static const boost::uuids::uuid MARKED_BITMAP_BASIC_PEN_COLOR_ID;
	// bodiagram
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_MINERALS_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_GAS_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_MINERALS_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_GAS_BOLD_PEN_COLOR_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_PEN_COLOR_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_BOLD_PEN_COLOR_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_PEN_COLOR_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_BOLD_PEN_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_BOLD_PEN_COLOR_ID;


	static const boost::uuids::uuid GREEN_TIMESTEPS_PEN_COLOR_ID;

	static const boost::uuids::uuid BODIAGRAM_FITNESS_PEN_COLOR_ID;

	static const boost::uuids::uuid DISABLED_PEN_COLOR_ID;


// ------ BRUSH COLORS ------
	static const boost::uuids::uuid NULL_BRUSH_COLOR_ID;
	static const boost::uuids::uuid TRANSPARENT_BRUSH_COLOR_ID;
	static const boost::uuids::uuid WINDOW_FOREGROUND_BRUSH_COLOR_ID;
	static const boost::uuids::uuid WINDOW_BACKGROUND_BRUSH_COLOR_ID;

	static const boost::uuids::uuid BO_DARK_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BO_BRIGHT_BRUSH_COLOR_ID;

	static const boost::uuids::uuid FORCE_LIST_BRUSH_COLOR_ID;
	static const boost::uuids::uuid FORCE_LIST_BUTTON_BRUSH_COLOR_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_BRUSH_COLOR_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_BRUSH_COLOR_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_BRUSH_COLOR_ID;
	static const boost::uuids::uuid VERY_BRIGHT_UNIT_TYPE_BRUSH_COLOR_ID;

	static const boost::uuids::uuid CONTINUE_BUTTON_BRUSH_COLOR_ID;
	static const boost::uuids::uuid DARK_CONTINUE_BUTTON_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BRIGHT_CONTINUE_BUTTON_BRUSH_COLOR_ID;

	static const boost::uuids::uuid BODIAGRAM_BACK1_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_BACK2_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_BAR_BRUSH_COLOR_ID;
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_BRUSH_COLOR_ID;

	// statistics window
	static const boost::uuids::uuid GENERATIONS_LEFT_BRUSH_COLOR_ID;	

	static const boost::uuids::uuid TOOLTIP_BRUSH_COLOR_ID;

	static const boost::uuids::uuid DISABLED_BRUSH_COLOR_ID;
	// ------ BRUSH COLORS END -------

	// ----- COLORS END -----

	// ----- FONTS -----

	static const boost::uuids::uuid SMALL_FONT_ID;
	static const boost::uuids::uuid SMALL_BOLD_FONT_ID;
	static const boost::uuids::uuid SMALL_SHADOW_FONT_ID;
	static const boost::uuids::uuid SMALL_SHADOW_BOLD_FONT_ID;
	static const boost::uuids::uuid SMALL_UNDERLINED_FONT_ID;
	static const boost::uuids::uuid SMALL_UNDERLINED_BOLD_FONT_ID;

	static const boost::uuids::uuid MIDDLE_FONT_ID;
	static const boost::uuids::uuid MIDDLE_BOLD_FONT_ID;
	static const boost::uuids::uuid MIDDLE_SHADOW_FONT_ID;
	static const boost::uuids::uuid MIDDLE_SHADOW_BOLD_FONT_ID;
	static const boost::uuids::uuid MIDDLE_UNDERLINED_FONT_ID;
	static const boost::uuids::uuid MIDDLE_UNDERLINED_BOLD_FONT_ID;

	static const boost::uuids::uuid LARGE_FONT_ID;
	static const boost::uuids::uuid LARGE_BOLD_FONT_ID;
	static const boost::uuids::uuid LARGE_SHADOW_FONT_ID;
	static const boost::uuids::uuid LARGE_SHADOW_BOLD_FONT_ID;
	static const boost::uuids::uuid LARGE_UNDERLINED_FONT_ID;
	static const boost::uuids::uuid LARGE_UNDERLINED_BOLD_FONT_ID;

	static const boost::uuids::uuid VERY_LARGE_FONT_ID;
	static const boost::uuids::uuid VERY_LARGE_BOLD_FONT_ID;
	static const boost::uuids::uuid VERY_LARGE_SHADOW_FONT_ID;
	static const boost::uuids::uuid VERY_LARGE_SHADOW_BOLD_FONT_ID;
	static const boost::uuids::uuid VERY_LARGE_UNDERLINED_FONT_ID;
	static const boost::uuids::uuid VERY_LARGE_UNDERLINED_BOLD_FONT_ID;

	static const boost::uuids::uuid HUGE_FONT_ID; //TODO
	static const boost::uuids::uuid HUGE_BOLD_FONT_ID; //TODO
	static const boost::uuids::uuid HUGE_SHADOW_FONT_ID;
	static const boost::uuids::uuid HUGE_SHADOW_BOLD_FONT_ID;
	static const boost::uuids::uuid HUGE_UNDERLINED_FONT_ID;
	static const boost::uuids::uuid HUGE_UNDERLINED_BOLD_FONT_ID;
	// ----- FONTS END -----


	// ----- PENS ------
	static const boost::uuids::uuid NULL_PEN_ID;
	static const boost::uuids::uuid BORDER_PEN_ID;
	static const boost::uuids::uuid OUTER_BORDER_PEN_ID;
	static const boost::uuids::uuid INNER_BORDER_PEN_ID;
	static const boost::uuids::uuid INNER_BORDER_HIGHLIGHT_PEN_ID;

	static const boost::uuids::uuid BIG_BUTTONS_PEN_ID;
	static const boost::uuids::uuid RECTANGLE_PEN_ID;
	static const boost::uuids::uuid BITMAP_MARKED_PEN_ID;

	// bodiagram
	static const boost::uuids::uuid BODIAGRAM_DASHED_MINERALS_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_GAS_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_SUPPLY_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_DASHED_MARKER_PEN_ID;
	// bowindow
	static const boost::uuids::uuid SELECT_PEN_ID;
	// transparent
	static const boost::uuids::uuid DARK_BACKGROUND_PEN_ID;
	// buttons
	static const boost::uuids::uuid MARKED_BITMAP_GREEN_PEN_ID;
	static const boost::uuids::uuid MARKED_BITMAP_YELLOW_PEN_ID;
	static const boost::uuids::uuid MARKED_BITMAP_RED_PEN_ID;
	static const boost::uuids::uuid MARKED_BITMAP_BASIC_PEN_ID;
	// bodiagram
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_MINERALS_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_GAS_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_BOLD_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_MINERALS_BOLD_PEN_ID;
	static const boost::uuids::uuid BODIAGRAM_GAS_BOLD_PEN_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_PEN_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_BOLD_PEN_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_BOLD_PEN_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_PEN_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_BOLD_PEN_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_BOLD_PEN_ID;


	static const boost::uuids::uuid GREEN_TIMESTEPS_PEN_ID;

	static const boost::uuids::uuid BODIAGRAM_FITNESS_PEN_ID;

	static const boost::uuids::uuid DISABLED_PEN_ID;
	// ----- PENS END ------


	// ------ BRUSHES ------
	static const boost::uuids::uuid NULL_BRUSH_ID;
	static const boost::uuids::uuid TRANSPARENT_BRUSH_ID;
	static const boost::uuids::uuid WINDOW_FOREGROUND_BRUSH_ID;
	static const boost::uuids::uuid WINDOW_BACKGROUND_BRUSH_ID;

	static const boost::uuids::uuid BO_DARK_BRUSH_ID;
	static const boost::uuids::uuid BO_BRIGHT_BRUSH_ID;

	static const boost::uuids::uuid FORCE_LIST_BRUSH_ID;
	static const boost::uuids::uuid FORCE_LIST_BUTTON_BRUSH_ID;

	static const boost::uuids::uuid UNIT_TYPE_0_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_BRUSH_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_BRUSH_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_BRUSH_ID;
	static const boost::uuids::uuid VERY_BRIGHT_UNIT_TYPE_BRUSH_ID;

	static const boost::uuids::uuid CONTINUE_BUTTON_BRUSH_ID;
	static const boost::uuids::uuid DARK_CONTINUE_BUTTON_BRUSH_ID;
	static const boost::uuids::uuid BRIGHT_CONTINUE_BUTTON_BRUSH_ID;

	static const boost::uuids::uuid BODIAGRAM_BACK1_BRUSH_ID;
	static const boost::uuids::uuid BODIAGRAM_BACK2_BRUSH_ID;
	static const boost::uuids::uuid BODIAGRAM_BAR_BRUSH_ID;
	static const boost::uuids::uuid BODIAGRAM_SUPPLY_BRUSH_ID;

	// statistics window
	static const boost::uuids::uuid GENERATIONS_LEFT_BRUSH_ID;	

	static const boost::uuids::uuid TOOLTIP_BRUSH_ID;

	static const boost::uuids::uuid DISABLED_BRUSH_ID;
	// ------ BRUSHES END -------


	// ------ ANIMATIONS --------
	static const boost::uuids::uuid NULL_ANIMATION_ID;

	static const boost::uuids::uuid INTRO_MAIN_ANIMATION_ID;
	static const boost::uuids::uuid INTRO_SDL_ANIMATION_ID;
	static const boost::uuids::uuid INTRO_SDL_TTF_ANIMATION_ID;
	static const boost::uuids::uuid INTRO_SDL_IMAGE_ANIMATION_ID;
	static const boost::uuids::uuid INTRO_GUI_ANIMATION_ID;
	static const boost::uuids::uuid INTRO_SMPEG_ANIMATION_ID;
#ifdef _FMOD_SOUND
	static const boost::uuids::uuid INTRO_FMOD_ANIMATION_ID;
#elif _SDL_MIXER_SOUND
	static const boost::uuids::uuid INTRO_MIXER_ANIMATION_ID;
#endif
	// ------ END ANIMATIONS --------


	// ------- BUTTON COLORS --------
	/*	static const boost::uuids::uuid UMS_BUTTON_ID;
	static const boost::uuids::uuid TERRA_BUTTON_ID;
	static const boost::uuids::uuid PROTOSS_BUTTON_ID;
	static const boost::uuids::uuid ZERG_BUTTON_ID;*/

	static const boost::uuids::uuid UNIT_TYPE_0_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_1_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_2_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_3_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_4_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_5_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_6_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_7_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_8_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_9_BUTTON_ID;
	static const boost::uuids::uuid UNIT_TYPE_10_BUTTON_ID;

	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_0_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_1_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_2_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_3_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_4_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_5_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_6_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_7_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_8_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_9_BUTTON_ID;
	static const boost::uuids::uuid BRIGHT_UNIT_TYPE_10_BUTTON_ID;

	static const boost::uuids::uuid VERY_BRIGHT_UNIT_TYPE_BUTTON_ID;

	static const boost::uuids::uuid STANDARD_BUTTON_ID;
	static const boost::uuids::uuid FORCE_ENTRY_BUTTON_ID;
	static const boost::uuids::uuid MODIFY_BUTTON_ID;
	static const boost::uuids::uuid TAB_BUTTON_ID;
	static const boost::uuids::uuid MENU_ENTRY_BUTTON_ID;
	static const boost::uuids::uuid EDIT_FIELD_BUTTON_ID;
	static const boost::uuids::uuid ARROW_BUTTON_ID;
	static const boost::uuids::uuid GOAL_LOCATION_BUTTON_ID;
	static const boost::uuids::uuid GOAL_TIME_BUTTON_ID;
	static const boost::uuids::uuid CHECK_BUTTON_ID;
	static const boost::uuids::uuid OPEN_TREE_BUTTON_ID;
	static const boost::uuids::uuid NON_GOAL_ENTRY_BUTTON_ID;
	static const boost::uuids::uuid TEXT_BUTTON_ID;
	static const boost::uuids::uuid VISITED_TEXT_BUTTON_ID;
	static const boost::uuids::uuid MENU_BUTTON_ID;
	static const boost::uuids::uuid HELP_BUTTON_ID;

	static const boost::uuids::uuid CLOSE_BUTTON_ID;

	//	COMPARE_GAME_BUTTON TODO
	//	REMOVE_GAME_BUTTON_ID;

	// ------- END BUTTON COLORS -------

	// ------- BUILD CONFIGURATION IDS -------

	static const boost::uuids::uuid DEFAULT_BUILD_CONFIGURATION_ID;
	// ------- END BUILD CONFIGURATION IDS -------


	// ------ SOUND -------
	static const boost::uuids::uuid NULL_SOUND_ID;
	static const boost::uuids::uuid MOUSEOVER_SOUND_ID;
	static const boost::uuids::uuid SWISHIN_SOUND_ID;
	static const boost::uuids::uuid SWISHOUT_SOUND_ID;
	static const boost::uuids::uuid SWISHLOCK_SOUND_ID;
	static const boost::uuids::uuid CLICKED_SOUND_ID;
	static const boost::uuids::uuid CLICK_SOUND_ID;
	static const boost::uuids::uuid COMPLETE_SOUND_ID;
	static const boost::uuids::uuid ERROR_SOUND_ID;
	static const boost::uuids::uuid RING_SOUND_ID;
	static const boost::uuids::uuid INTRO_SOUND_ID;
	// ------- END SOUND -------

	// ------- MUSIC --------
	static const boost::uuids::uuid NULL_MUSIC_ID;
	static const boost::uuids::uuid GENETIC_MUSIC_ID;
	static const boost::uuids::uuid DIABLO_MUSIC_ID;
	// ------- END MUSIC --------

	// ------ SOUND CONFIGURATION ------
	static const boost::uuids::uuid DEFAULT_SOUND_CONFIGURATION_ID;
	// ------ END SOUND CONFIGURATION ------


	// ------- WINDOW LAYOUTS --------

	static const boost::uuids::uuid GAME_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid GAMECONFIGURATION_WINDOW_TITLE_TEXT_ID;
	static const boost::uuids::uuid SCORE_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid PLAYER_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid FORCE_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid BUILDORDER_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid BUILDORDERDIAGRAM_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid BUILDORDERGRAPH_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid MAIN_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid INTRO_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid MESSAGE_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid HELP_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid SETTINGS_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid DATABASE_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid DATALIST_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid MAP_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid INFO_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid TECHTREE_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid SAVEBOX_WINDOWLAYOUT_ID;
	static const boost::uuids::uuid DEBUG_WINDOWLAYOUT_ID;
	// ------- END WINDOW LAYOUTS --------

	// ------- WINDOW COLORS -------
	static const boost::uuids::uuid STANDARD_WINDOWCOLORS_ID;
	static const boost::uuids::uuid TRANSPARENT_WINDOWCOLORS_ID; // transparent main window

	// ------- END WINDOW COLORS --------

	// ------- RESOLUTIONS ---------
	static const boost::uuids::uuid RESOLUTION_640x480_ID;
	static const boost::uuids::uuid RESOLUTION_800x600_ID;
	static const boost::uuids::uuid RESOLUTION_1024x768_ID;
	static const boost::uuids::uuid RESOLUTION_1920x1080_ID;
	// ------- END RESOLUTIONS ---------

	// -------- OBJECT SIZES --------
	static const boost::uuids::uuid STANDARD_OBJECTSIZE_ID;
	static const boost::uuids::uuid CHILD_OBJECTSIZE_ID;
	// -------- END OBJECT SIZES ----------

	// ------- THEMES ---------
	static const boost::uuids::uuid BLUE_THEME_ID;
	static const boost::uuids::uuid GREY_THEME_ID;
	// ------- END THEMES ---------

	// ------- OBJECT SIZES ---------
	//static const boost::uuids::
	// TODO
	// ------- END OBJECT SIZES ----------
};

#endif // _MISC_IDS_HPP
