#include "ids.hpp"
#include "miscellaneous.hpp"

// ---- STRINGS ----


const boost::uuids::uuid IDS::EMPTY_TEXT_ID = Misc::uuid("c55c1d2b-34e8-49b4-b516-26ef404ec13f");

// ---- GUI ----
const boost::uuids::uuid IDS::START_INIT_SDL_TEXT_ID = Misc::uuid("e438cdf0-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SET_FULLSCREEN_MODE_TEXT_ID = Misc::uuid("e81f08d0-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SET_WINDOW_MODE_TEXT_ID = Misc::uuid("eaf4be10-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_UNABLE_TO_INIT_SDL_TEXT_ID = Misc::uuid("ed5ee040-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_ERROR_SETTING_VIDEO_MODE_TEXT_ID = Misc::uuid("f4d74290-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_CREATED_SURFACE_TEXT_ID = Misc::uuid("f82227d0-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_SDL_TRUETYPE_FONTS_TEXT_ID = Misc::uuid("fe0e1dc0-4b5b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_SDL_TTF_ERROR_TEXT_ID = Misc::uuid("00eb4d10-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_LOAD_CONFIGURATION_TEXT_ID = Misc::uuid("036bb660-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_RESET_MOUSE_CURSOR_TEXT_ID = Misc::uuid("05d4a010-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_COLORS_BRUSHES_PENS_TEXT_ID = Misc::uuid("080ba450-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_BITMAPS_TEXT_ID = Misc::uuid("0a8c82d0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_ANIMATIONS_TEXT_ID = Misc::uuid("0ddf3040-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_COORDINATES_TEXT_ID = Misc::uuid("10600ec0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_BUTTONS_TEXT_ID = Misc::uuid("138e6b50-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_FREEING_FONTS_TEXT_ID = Misc::uuid("16265440-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_NO_MODES_AVAILABLE_TEXT_ID = Misc::uuid("18ecee50-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_ALL_RESOLUTIONS_AVAILABLE_TEXT_ID = Misc::uuid("1b3cf8d0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_AVAILABLE_MODES_TEXT_ID = Misc::uuid("1d8d5170-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_MAX_COLOR_DEPTH_TEXT_ID = Misc::uuid("1fbbf140-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_HARDWARE_SURFACES_POSSIBLE_TEXT_ID = Misc::uuid("222ec600-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_WINDOW_MANAGER_AVAILABLE_TEXT_ID = Misc::uuid("24a2d340-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SOFTWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("26f74a90-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SOFTWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("29525190-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SOFTWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("2bd971a0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_HARDWARE_TO_HARDWARE_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("2e3a6c10-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_HARDWARE_TO_HARDWARE_COLORKEY_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("30923ec0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_HARDWARE_TO_HARDWARE_ALPHA_BLITS_ACCELERATED_TEXT_ID = Misc::uuid("32d81010-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_COLOR_FILLS_ACCELERATED_TEXT_ID = Misc::uuid("35024310-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_TOTAL_VIDEO_MEMORY_TEXT_ID = Misc::uuid("38e0dcd0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_STORED_IN_SYSTEM_MEMORY_TEXT_ID = Misc::uuid("3b90ba90-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_STORED_IN_VIDEO_MEMORY_TEXT_ID = Misc::uuid("3dbfcf90-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_USES_ASYNCHRONOUS_BLITS_TEXT_ID = Misc::uuid("42b5f3d0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_ALLOWS_ANY_PIXEL_FORMAT_TEXT_ID = Misc::uuid("452bd5d0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_HAS_EXCLUSIVE_PALETTE_TEXT_ID = Misc::uuid("47718010-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_IS_DOUBLE_BUFFERED_TEXT_ID = Misc::uuid("49a43e90-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_HAS_OPENGL_CONTEXT_TEXT_ID = Misc::uuid("4bb914d0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_SUPPORTS_OPENGL_BLITTING_TEXT_ID = Misc::uuid("4e671dd0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_IS_RESIZABLE_TEXT_ID = Misc::uuid("50817250-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_BLIT_USES_HARDWARE_ACCELERATION_TEXT_ID = Misc::uuid("5350bef0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_USES_COLORKEY_BLITTING_TEXT_ID = Misc::uuid("56552550-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_COLORKEY_BLITTING_RLE_ACCELERATED_TEXT_ID = Misc::uuid("58db8210-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_BLIT_USES_ALPHA_BLENDING_TEXT_ID = Misc::uuid("5b80ff90-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_USES_PREALLOCATED_MEMORY_TEXT_ID = Misc::uuid("5dcdfcd0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_SDL_SURFACE_NEEDS_LOCKING_TEXT_ID = Misc::uuid("600cf050-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_RELEASING_SOUND_ENGINE_TEXT_ID = Misc::uuid("62a6d510-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::END_CLOSING_SOUND_ENGINE_TEXT_ID = Misc::uuid("64d06bd0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_SOUND_TEXT_ID = Misc::uuid("66fac5e0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_FMOD_SYSTEM_CREATE_ERROR_TEXT_ID = Misc::uuid("6966e3e0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_FMOD_GET_VERSION_ERROR_TEXT_ID = Misc::uuid("6ba9f610-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_FMOD_VERSION_ERROR_TEXT_ID = Misc::uuid("6de2cf10-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_FMOD_SYSTEM_INIT_ERROR_TEXT_ID = Misc::uuid("70b4b3c0-4b5c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::START_INIT_NOSOUND_TEXT_ID = Misc::uuid("73009f90-4b5c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::WELCOME_TEXT_ID = Misc::uuid("e3f57230-50d3-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FPS_TEXT_ID = Misc::uuid("d414bcd0-5c9b-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::CHANGED_BIT_DEPTH_TEXT_ID = Misc::uuid("46067f20-5d07-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::CHANGED_RESOLUTION_TEXT_ID = Misc::uuid("12771462-a732-4ef1-8aac-1e3c2b72e932");

const boost::uuids::uuid IDS::MAIN_WINDOW_TITLE_TEXT_ID = Misc::uuid("0febc8f0-7c0b-11e0-819a-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_WINDOW_TITLE_TEXT_ID = Misc::uuid("91bba64e-8034-4eef-b578-72d2dbfe59ac");
const boost::uuids::uuid IDS::MESSAGE_WINDOW_TITLE_TEXT_ID = Misc::uuid("1e1f43b1-3ab1-4790-b4d6-11edc0c96728");
const boost::uuids::uuid IDS::HELP_WINDOW_TITLE_TEXT_ID = Misc::uuid("1d4cc7b0-9963-4f90-aceb-784bdd758603");
const boost::uuids::uuid IDS::SETTINGS_WINDOW_TITLE_TEXT_ID = Misc::uuid("6f77d979-a1dc-4005-89ae-9338604dc6e9"); 
const boost::uuids::uuid IDS::MAP_WINDOW_TITLE_TEXT_ID = Misc::uuid("70998ea2-2958-46e9-9899-df14db247c33");
const boost::uuids::uuid IDS::DATABASE_WINDOW_TITLE_TEXT_ID = Misc::uuid("26d0069f-5907-414c-94fb-db4264bb35b5");

const boost::uuids::uuid IDS::INFO_WINDOW_TITLE_TEXT_ID = Misc::uuid("b85c1931-e388-4e9a-940b-a1474ba402bf");
const boost::uuids::uuid IDS::TECHTREE_WINDOW_TITLE_TEXT_ID = Misc::uuid("e469553f-18f1-44e4-bb25-0e4def6ebdc5");
const boost::uuids::uuid IDS::DEBUG_WINDOW_TITLE_TEXT_ID = Misc::uuid("1484d40c-fd23-49e3-9f1d-c02ee22aadcb");

const boost::uuids::uuid IDS::BOGRAPH_WINDOW_TITLE_TEXT_ID = Misc::uuid("a0d526b4-596e-4026-9503-503875fcbc2f");
const boost::uuids::uuid IDS::BODIAGRAM_WINDOW_TITLE_TEXT_ID = Misc::uuid("b3ca1d2d-e930-479c-b027-5b2db7bec8c2");
const boost::uuids::uuid IDS::STATISTICS_WINDOW_TITLE_TEXT_ID = Misc::uuid("68a31d20-22c6-4ada-a987-2cfd449d3613");
const boost::uuids::uuid IDS::TIMER_WINDOW_TITLE_TEXT_ID = Misc::uuid("d2cff9ae-de2a-4092-9f04-c157feffde20");
const boost::uuids::uuid IDS::FORCE_WINDOW_TITLE_TEXT_ID = Misc::uuid("60d3ee8d-2fd9-4625-ac06-5679899bf60c"); // 10
const boost::uuids::uuid IDS::BOWINDOW_TITLE_TEXT_ID = Misc::uuid("4dc607be-2ab3-43c7-b285-26e27e071a4f");
const boost::uuids::uuid IDS::GAME_WINDOW_TITLE_TEXT_ID = Misc::uuid("ebec4e6e-cc7c-4e78-aac2-79626b0019a9");
const boost::uuids::uuid IDS::GAMECONFIGURATION_WINDOW_TITLE_TEXT_ID = Misc::uuid("99510c2a-24db-4e56-bb71-31394c2194e0");
const boost::uuids::uuid IDS::PLAYER_WINDOW_TITLE_TEXT_ID = Misc::uuid("b55ef4a8-61de-4b34-8362-d99caf106b76");
const boost::uuids::uuid IDS::SCORE_WINDOW_TITLE_TEXT_ID = Misc::uuid("1fbaa9c3-be7c-46b7-9bff-66983e5365d7");

const boost::uuids::uuid IDS::GAME_NUMBER_TEXT_ID = Misc::uuid("0341c8fe-62f7-4497-9ad5-a3e04ee5da25");
const boost::uuids::uuid IDS::NEW_GAME_TEXT_ID = Misc::uuid("6344a032-4e4c-4b83-a6ec-ca5260cf7338");

// message window:
const boost::uuids::uuid IDS::WELCOME_MSG1_TEXT_ID = Misc::uuid("faca141e-7636-4a98-9dc1-ff587d48c0b4");
const boost::uuids::uuid IDS::WELCOME_MSG2_TEXT_ID = Misc::uuid("78d21fd1-e13c-4353-9d9b-c0d45596c680");
const boost::uuids::uuid IDS::PLAYERS_LOADED_TEXT_ID = Misc::uuid("84b9ee5e-4afb-4539-974f-a91230bae297");
const boost::uuids::uuid IDS::ADDED_GOAL_TEXT_ID = Misc::uuid("5db28e5b-9bee-4b23-ac86-f5440a17de06");
const boost::uuids::uuid IDS::SET_NEW_GOAL_LIST_TEXT_ID = Misc::uuid("b02664f0-dc3e-411f-a015-87f23175493c");
const boost::uuids::uuid IDS::SET_NEW_MAP_TEXT_ID = Misc::uuid("5980d27c-9cff-45ca-9066-cd330a5ca596");
const boost::uuids::uuid IDS::SET_RACE_TEXT_ID = Misc::uuid("9468f798-a463-4a3e-a411-c4250c6af705");
const boost::uuids::uuid IDS::ADDED_ONE_GOAL_TEXT_ID = Misc::uuid("de4b558b-0e7e-4ba5-92dd-e86e191384b0");
const boost::uuids::uuid IDS::REMOVED_ONE_GOAL_TEXT_ID = Misc::uuid("657edac7-3aeb-468a-a988-d877f0179f26");
const boost::uuids::uuid IDS::MOVED_NON_GOAL_TEXT_ID = Misc::uuid("68aa84a9-e380-496b-8ef1-ee113dfc07ed");
const boost::uuids::uuid IDS::SAVED_GOAL_TEXT_ID = Misc::uuid("3185831a-7c8b-43d2-ab63-beee67f8a6b1");
const boost::uuids::uuid IDS::SAVED_BUILD_ORDER_TEXT_ID = Misc::uuid("db8077fe-6f37-462c-99a7-b87adcf2ef87");

// game window:
const boost::uuids::uuid IDS::COMPARE_GAME_TEXT_ID = Misc::uuid("4ae36aae-3871-434d-a936-4330f940958b");
const boost::uuids::uuid IDS::REMOVE_GAME_TEXT_ID = Misc::uuid("4f1712c6-28a9-4720-8934-fc996faf2bf8");

// help window:
const boost::uuids::uuid IDS::HELP_WINDOW_INDEX_TEXT_ID = Misc::uuid("1d133c8f-ceae-4c64-88ac-27e1bbf69899");
const boost::uuids::uuid IDS::HELP_WINDOW_BACK_TEXT_ID = Misc::uuid("d0a23f5a-9ef5-4f56-9aee-ffa87a4a0ddb");

// edit field window:
const boost::uuids::uuid IDS::SAVE_BOX_OK_TEXT_ID = Misc::uuid("f2174a3c-2f3b-4d56-8612-06f7dfc34a54");
const boost::uuids::uuid IDS::SAVE_BOX_CANCEL_TEXT_ID = Misc::uuid("60985f0c-244f-4175-8e4f-c2fd2c41eb74");

// debug window:
const boost::uuids::uuid IDS::DRAW_TICKS_TEXT_ID = Misc::uuid("8397be85-d3b7-4054-96be-ea85c5756d04");
const boost::uuids::uuid IDS::GENERATION_TICKS_TEXT_ID = Misc::uuid("df8f966c-8190-4c71-ad63-0ccdec1f420b");
const boost::uuids::uuid IDS::PROCESS_TICKS_TEXT_ID = Misc::uuid("67c21834-207a-4741-9286-b21eedf3b77b");
const boost::uuids::uuid IDS::MESSAGE_TICKS_TEXT_ID = Misc::uuid("2f2ed070-9da1-40ff-9ce2-58025318507b");
const boost::uuids::uuid IDS::SOUND_TICKS_TEXT_ID = Misc::uuid("0bc9e039-8ff2-485b-8d02-1f2fbb726d45");
const boost::uuids::uuid IDS::IDLE_TICKS_TEXT_ID = Misc::uuid("3daca267-f88d-4323-809e-b1dd460f8b4a");
const boost::uuids::uuid IDS::FPS_TEXT_TEXT_ID = Misc::uuid("e263bf45-a968-42ef-a600-c8a18a53ef88");
const boost::uuids::uuid IDS::GPS_TEXT_TEXT_ID = Misc::uuid("5070c46f-43b8-4eac-baf5-65a777ec78c7");


// force window:
const boost::uuids::uuid IDS::STARTING_FORCE_TEXT_ID = Misc::uuid("677d26b4-3975-47b8-9874-1c4ab197c016");
const boost::uuids::uuid IDS::NON_GOALS_TEXT_ID = Misc::uuid("bbe2ffe6-585e-4846-b59e-40fb13b91c67");
const boost::uuids::uuid IDS::GOALS_TEXT_ID = Misc::uuid("55d2f3f1-40d3-4199-b28a-5890684957a9");
const boost::uuids::uuid IDS::LEGEND_TEXT_ID = Misc::uuid("b73d187e-93b4-4ec1-bfc1-c7a8a88dd79e");
const boost::uuids::uuid IDS::TIME_LEGEND_TEXT_ID = Misc::uuid("8b23e05d-1ec2-4f6c-888b-58737b761d1a");
const boost::uuids::uuid IDS::CLICK_TO_ADD_GOAL_TEXT_ID = Misc::uuid("66dac50f-b1b7-4859-8ad0-269da3dc3afd"); //30
const boost::uuids::uuid IDS::BACK_TEXT_ID = Misc::uuid("d7ff377e-f554-4ce9-a3ec-3ecb0432f0d9");
const boost::uuids::uuid IDS::CLOSE_TEXT_ID = Misc::uuid("39cd3881-4c5d-4fa5-8e11-2549d9ba1143");
const boost::uuids::uuid IDS::ADD_GOAL_TEXT_ID = Misc::uuid("e8050e0a-3278-4989-b027-43cf0d5d5c90");
const boost::uuids::uuid IDS::GOAL_LIST_TEXT_ID = Misc::uuid("6e35b758-a121-4faa-abae-6909a86902de");
const boost::uuids::uuid IDS::STARTFORCE_TEXT_ID = Misc::uuid("d22594a3-7901-46e8-936c-8a18159a3cdc");
const boost::uuids::uuid IDS::CHOOSE_RACE_TEXT_ID = Misc::uuid("18fe559e-7761-4de2-be26-03f4737b7f05");

const boost::uuids::uuid IDS::CHOOSE_MAP_TEXT_ID = Misc::uuid("0823cc4f-b2e9-40aa-9da3-2ffc1f69ff3c");

const boost::uuids::uuid IDS::SAVE_GOAL_TEXT_ID = Misc::uuid("e8e02bc2-6965-47d9-b831-78d2b6fcfdc0");

const boost::uuids::uuid IDS::SAVE_GOALS_AS_TEXT_ID = Misc::uuid("7b376c92-0d87-40b0-8152-0c1535078802");
const boost::uuids::uuid IDS::GIVE_GOAL_A_NAME_TEXT_ID = Misc::uuid("10dc0536-0f50-4ea0-b7c6-d57d0462a782");

const boost::uuids::uuid IDS::CHOOSE_GOAL_NAME_TEXT_ID = Misc::uuid("358809b5-679e-44eb-ae75-a289feeb177d");

const boost::uuids::uuid IDS::SAVE_BUILD_ORDER_AS_TEXT_ID = Misc::uuid("e7e25bcd-b5b7-496c-82ef-1fd04840cbee");
const boost::uuids::uuid IDS::GIVE_BO_A_NAME_TEXT_ID = Misc::uuid("a2b07af6-abd1-4052-9dbf-aca856cdbe11"); //40


// bowindow
const boost::uuids::uuid IDS::CLICK_TO_INSERT_ORDER_TEXT_ID = Misc::uuid("9184e734-1ef6-4670-acc6-ce3d68e05e1f"); //44
//	CLICK_TO_CLOSE_ORDER_TEXT_ID = Misc::uuid(""); schon in force definiert
//	CLICK_TO_GO_BACK_TEXT_ID = Misc::uuid("");

const boost::uuids::uuid IDS::OPTIMIZE_EVERYTHING_TEXT_ID = Misc::uuid("3112235d-a205-4c55-9268-e038ace0b5ba");
const boost::uuids::uuid IDS::OPTIMIZE_SELECTED_TEXT_ID = Misc::uuid("447407ac-1223-4242-9c57-5fc1aaefcdb2");
const boost::uuids::uuid IDS::RESET_BUILD_ORDER_TEXT_ID = Misc::uuid("40e61cea-dc6f-420c-9058-5ee08b1eb8e2");
const boost::uuids::uuid IDS::SAVE_BUILD_ORDER_TEXT_ID = Misc::uuid("696b9681-b4da-41cb-b448-a84da102ff11");
const boost::uuids::uuid IDS::LOAD_BUILD_ORDER_TEXT_ID = Misc::uuid("00fe74b7-7c9d-4fa5-8b39-cecbc2e8e733");

const boost::uuids::uuid IDS::BOWINDOW_BUILD_TIME_TEXT_ID = Misc::uuid("474c2b19-fa6e-40b4-8fc2-e76f5cd56fdb");
const boost::uuids::uuid IDS::BOWINDOW_EACH_TOTAL_TEXT_ID = Misc::uuid("4826e938-f8f1-4457-86dd-c9ede953e69d");

const boost::uuids::uuid IDS::PLAYER_TEXT_ID = Misc::uuid("7de07eef-d7ef-43d4-a01b-f78c8eaa7237");
const boost::uuids::uuid IDS::SPEED_TEXT_ID = Misc::uuid("2cdf0181-7adc-49d1-b5a4-9fd5a93bea47");

// timer window
const boost::uuids::uuid IDS::OF_GOALS_FULFILLED_TEXT_ID = Misc::uuid("0e391f58-ed4b-43c1-a1f1-76dfe8046d5f"); //50
const boost::uuids::uuid IDS::OF_TIME_FULFILLED_TEXT_ID = Misc::uuid("7fabb146-b868-4a35-b4ed-fe6ffad11e6a");
const boost::uuids::uuid IDS::PAUSED_TEXT_ID = Misc::uuid("37755ca2-9001-4046-a97d-bc8e5af3141a");
const boost::uuids::uuid IDS::SEARCHING_TEXT_ID = Misc::uuid("5229c115-1a82-44ae-ae92-698200dd5591");
const boost::uuids::uuid IDS::THEORETICAL_OPTIMUM_TEXT_ID = Misc::uuid("5c520595-8733-4efb-b3d3-df10861bf05d");
const boost::uuids::uuid IDS::OPTIMIZING_TEXT_ID = Misc::uuid("6cfc4a7d-bf33-41cb-825e-166ec65a71ca");
const boost::uuids::uuid IDS::RES_UNITS_STRUCT_TEXT_ID = Misc::uuid("4e4c6505-9825-4deb-bd1c-4cb93de1cd0f");
const boost::uuids::uuid IDS::TOTAL_TEXT_ID = Misc::uuid("c673727e-1d4b-4d56-8578-4f1718c21a07");

const boost::uuids::uuid IDS::ADD_PLAYER_TEXT_ID = Misc::uuid("6e6549b0-7abf-4a03-ba6e-6ce062393cdf");

// Tabs
const boost::uuids::uuid IDS::HELP_TAB_TEXT_ID = Misc::uuid("8e083361-b5ec-4bd4-a870-316c08ce87eb");
const boost::uuids::uuid IDS::SETTINGS_TAB_TEXT_ID = Misc::uuid("0a3d04b1-b127-481a-84eb-1ed2463b2b70");
const boost::uuids::uuid IDS::DATABASE_TAB_TEXT_ID = Misc::uuid("0e08e951-4b98-4e7a-b6a7-f043755a3826");
const boost::uuids::uuid IDS::MAP_TAB_TEXT_ID = Misc::uuid("c1045a3d-0d9e-44e3-8e99-010d4b745d9c"); 

// tooltips
const boost::uuids::uuid IDS::ADD_UNIT_TOOLTIP_TEXT_ID = Misc::uuid("100d9ba6-a8a0-4e97-97fa-f3dae4d925b4");
const boost::uuids::uuid IDS::REMOVE_UNIT_TOOLTIP_TEXT_ID = Misc::uuid("a02c4ac6-a97a-43d1-9660-a53e850f1a63");
const boost::uuids::uuid IDS::REMOVE_GOAL_TOOLTIP_TEXT_ID = Misc::uuid("3fa0dc73-c43a-442d-aeae-c96f976c865b");

const boost::uuids::uuid IDS::CHOOSE_RACE_TOOLTIP_TEXT_ID = Misc::uuid("b8ced2fb-680c-4233-b60c-39e2ac59576a");
const boost::uuids::uuid IDS::ADD_GOALS_TOOLTIP_TEXT_ID = Misc::uuid("cce542ed-dbdb-45b6-b0e2-fb8d5adef601"); // 90
const boost::uuids::uuid IDS::CHOOSE_GOALS_TOOLTIP_TEXT_ID = Misc::uuid("287ab0b6-4b15-4ce0-b372-bf71b9159649");
const boost::uuids::uuid IDS::CHOOSE_STARTING_FORCE_TOOLTIP_TEXT_ID = Misc::uuid("f5a9f967-c6b2-4bae-9682-8ffe59d691f2");

const boost::uuids::uuid IDS::SAVE_GOAL_TOOLTIP_TEXT_ID = Misc::uuid("d723988a-2384-4fa8-973a-04f2a798549d");

const boost::uuids::uuid IDS::RESET_BUILD_ORDER_TOOLTIP_TEXT_ID = Misc::uuid("aa30598e-e690-4efc-a435-40102bf3c878");
const boost::uuids::uuid IDS::SAVE_BUILD_ORDER_TOOLTIP_TEXT_ID = Misc::uuid("db3cee15-4a92-4b44-9081-9e831aa28e3c");
const boost::uuids::uuid IDS::LOAD_BUILD_ORDER_TOOLTIP_TEXT_ID = Misc::uuid("7a637f9d-a9e6-41c1-a392-600584397f64");

// timer:
const boost::uuids::uuid IDS::CONTINUE_OPTIMIZATION_TOOLTIP_TEXT_ID = Misc::uuid("c1b3792c-8ed7-44bb-b4e6-c71f7a9f2b71"); 
const boost::uuids::uuid IDS::PAUSE_OPTIMIZATION_TOOLTIP_TEXT_ID = Misc::uuid("e57de7b7-ce75-454b-8a5d-ccc57da1a119"); 
const boost::uuids::uuid IDS::OF_GOALS_FULFILLED_TOOLTIP_TEXT_ID = Misc::uuid("963ccf6f-851c-409c-872c-82b14a1602f5");
const boost::uuids::uuid IDS::OF_TIME_FULFILLED_TOOLTIP_TEXT_ID = Misc::uuid("1f8a9d13-9c98-4154-8be7-c57fab6fef39");

const boost::uuids::uuid IDS::HELP_TAB_TOOLTIP_TEXT_ID = Misc::uuid("cee25688-4344-4baf-94df-34c93b1e671c");	
const boost::uuids::uuid IDS::SETTINGS_TAB_TOOLTIP_TEXT_ID = Misc::uuid("f355c9cd-cf2c-4d0f-a999-9da01aa61629"); //110
const boost::uuids::uuid IDS::DATABASE_TAB_TOOLTIP_TEXT_ID = Misc::uuid("bf700b1d-c690-4d41-93c9-830f84a2ff6d");
const boost::uuids::uuid IDS::MAP_TAB_TOOLTIP_TEXT_ID = Misc::uuid("035648a5-d411-4c51-9e74-ce73170aa3c7");

const boost::uuids::uuid IDS::FORCEENTRY_TIME_TOOLTIP_TEXT_ID = Misc::uuid("97ecb50b-7a95-40db-9c7c-358a950b2ecf");
const boost::uuids::uuid IDS::FORCEENTRY_ALWAYS_BUILD_TOOLTIP_TEXT_ID = Misc::uuid("4bac19db-5263-4877-8fa4-eb6081f13f99");
const boost::uuids::uuid IDS::FORCEENTRY_BUILD_MUCH_TOOLTIP_TEXT_ID = Misc::uuid("112b702b-2a2c-4cfb-aa76-0fd164801137");

// settings:
const boost::uuids::uuid IDS::SETTING_FAST_CALCULATION_TEXT_ID = Misc::uuid("529e6a1d-f8cf-443a-9712-ce5241b0dbfc");
const boost::uuids::uuid IDS::SETTING_ALLOW_WAIT_ORDERS_TEXT_ID = Misc::uuid("773ac440-43e3-42cf-9f89-6fb660df647e");
const boost::uuids::uuid IDS::SETTING_WAIT_ACCURACY_TEXT_ID = Misc::uuid("c944b72f-7973-4dc0-9bcc-93557d895791");
const boost::uuids::uuid IDS::SETTING_GAME_SPEED_TEXT_ID = Misc::uuid("93b0d3a9-27dd-4c43-827a-510d88e0cd70");
const boost::uuids::uuid IDS::SETTING_AUTO_RUNS_TEXT_ID = Misc::uuid("e24bcc96-ccbc-4f4a-a2e8-401fd4b369b0");
const boost::uuids::uuid IDS::SETTING_MAX_GENERATIONS_TEXT_ID = Misc::uuid("e4bbb949-d564-4cba-9f41-4cc027742ff5");

const boost::uuids::uuid IDS::SETTING_USE_MUSIC_TEXT_ID = Misc::uuid("17c28bcc-e20f-49b2-bca9-8968061b935d");
const boost::uuids::uuid IDS::SETTING_USE_SOUND_TEXT_ID = Misc::uuid("8524bc14-7008-4a30-baa6-40fde2141331");
const boost::uuids::uuid IDS::SETTING_MUSIC_VOLUME_TEXT_ID = Misc::uuid("bcd49ca9-93e0-4efb-a5a8-8977001bbbc9");
const boost::uuids::uuid IDS::SETTING_SOUND_VOLUME_TEXT_ID = Misc::uuid("7afbda4a-a2d0-459e-9111-31a407620246");
const boost::uuids::uuid IDS::SETTING_CHANNELS_TEXT_ID = Misc::uuid("feaf1426-8ee5-46bf-93c0-7e966200ad57");

const boost::uuids::uuid IDS::SETTING_BACKGROUND_BITMAP_TEXT_ID = Misc::uuid("1b3695e9-b51f-4d84-9b3c-9ca0d7b64106");
const boost::uuids::uuid IDS::SETTING_SMOOTH_MOVEMENT_TEXT_ID = Misc::uuid("64ccd27d-8137-4d80-8020-4f1145d885ee");
const boost::uuids::uuid IDS::SETTING_WAIT_AFTER_CHANGE_TEXT_ID = Misc::uuid("8c084528-797c-42fe-bf9d-77340f258ba0");
const boost::uuids::uuid IDS::SETTING_TOOLTIPS_TEXT_ID = Misc::uuid("f1bf07be-51dd-464f-aad2-d35a24247146");
const boost::uuids::uuid IDS::SETTING_DNA_SPIRAL_TEXT_ID = Misc::uuid("b7884a23-a340-4ad6-a526-ba43811ff23a");
const boost::uuids::uuid IDS::SETTING_RACE_SPECIFIC_THEME_TEXT_ID = Misc::uuid("9b4d26c9-2a6d-4aa4-8a61-e3644364a917");
const boost::uuids::uuid IDS::SETTING_GLOWING_BUTTONS_TEXT_ID = Misc::uuid("67929f23-4efd-468f-b268-9cad04f12d90");
const boost::uuids::uuid IDS::SETTING_COMPACT_DISPLAY_MODE_TEXT_ID = Misc::uuid("f9af4981-aaa9-4894-a9b2-42b040b10994");
const boost::uuids::uuid IDS::SETTING_FACILITY_MODE_TEXT_ID = Misc::uuid("2af32b96-562a-423f-993d-8b45f403fd27");

const boost::uuids::uuid IDS::SETTING_FULLSCREEN_TEXT_ID = Misc::uuid("acab0cb2-6ae1-462f-9cb7-8d07687366df");
const boost::uuids::uuid IDS::SETTING_UNLOAD_GRAPHICS_TEXT_ID = Misc::uuid("10066eee-69ba-4a14-a5fe-50c4f36467b4");
const boost::uuids::uuid IDS::SETTING_SHOW_DEBUG_TEXT_ID = Misc::uuid("1e94f9d8-5e51-4dc2-abd0-1ca8a6b0d611");
const boost::uuids::uuid IDS::SETTING_DESIRED_FRAMERATE_TEXT_ID = Misc::uuid("55e583c3-5644-4361-bb9c-640c0b32a739");
const boost::uuids::uuid IDS::SETTING_DESIRED_CPU_USAGE_TEXT_ID = Misc::uuid("a7521673-0fc8-4636-9783-430fc9a9ca5d");

const boost::uuids::uuid IDS::SETTING_RELOAD_FROM_FILE_TEXT_ID = Misc::uuid("8adb5ac3-f8ef-43c7-b34f-08cc230f5662");
const boost::uuids::uuid IDS::SETTING_SAVE_TO_FILE_TEXT_ID = Misc::uuid("dd8d553d-4029-4261-bf89-e8b4a6e1764b");
const boost::uuids::uuid IDS::SETTING_LOAD_DEFAULTS_TEXT_ID = Misc::uuid("c6b13f2d-c033-44ab-baeb-8ee530f3c021");

// tooltips	
const boost::uuids::uuid IDS::SETTING_FAST_CALCULATION_TOOLTIP_TEXT_ID = Misc::uuid("161dac84-b668-48d2-8c1f-17e369413b68");
const boost::uuids::uuid IDS::SETTING_ALLOW_WAIT_ORDERS_TOOLTIP_TEXT_ID = Misc::uuid("90eefe3e-153a-44e8-9c93-6e06ae9937ea");
const boost::uuids::uuid IDS::SETTING_WAIT_ACCURACY_TOOLTIP_TEXT_ID = Misc::uuid("9e947b7a-5a2b-495b-b62f-36c6c7701b71");
const boost::uuids::uuid IDS::SETTING_GAME_SPEED_TOOLTIP_TEXT_ID = Misc::uuid("69c2f235-62f0-42b3-addc-85e4f4650ae1");
const boost::uuids::uuid IDS::SETTING_AUTO_RUNS_TOOLTIP_TEXT_ID = Misc::uuid("8016fd97-8067-4af2-9aa3-a79fca7faf32");
const boost::uuids::uuid IDS::SETTING_MAX_GENERATIONS_TOOLTIP_TEXT_ID = Misc::uuid("877b7788-85cc-453f-9f3a-610d4ff0a4a1");

const boost::uuids::uuid IDS::SETTING_USE_MUSIC_TOOLTIP_TEXT_ID = Misc::uuid("77574c3a-9ef9-4ae0-8fc6-adc4dde9d639");
const boost::uuids::uuid IDS::SETTING_USE_SOUND_TOOLTIP_TEXT_ID = Misc::uuid("528a2709-f1fb-4037-b87b-0b451ad793c9");
const boost::uuids::uuid IDS::SETTING_MUSIC_VOLUME_TOOLTIP_TEXT_ID = Misc::uuid("46d58954-80da-4ee0-8f41-a8728f7e9af0");
const boost::uuids::uuid IDS::SETTING_SOUND_VOLUME_TOOLTIP_TEXT_ID = Misc::uuid("d1291cfe-e230-4963-a4fb-72b0bd48b1d4");
const boost::uuids::uuid IDS::SETTING_CHANNELS_TOOLTIP_TEXT_ID = Misc::uuid("51fa2f01-6dbe-433a-a140-6d4d5d60eadb");

const boost::uuids::uuid IDS::SETTING_BACKGROUND_BITMAP_TOOLTIP_TEXT_ID = Misc::uuid("053ac2ee-8851-4dfb-a8e0-23291064974e");
const boost::uuids::uuid IDS::SETTING_SMOOTH_MOVEMENT_TOOLTIP_TEXT_ID = Misc::uuid("9722b5de-efe2-4a84-be2d-2f3694318b3f");
const boost::uuids::uuid IDS::SETTING_WAIT_AFTER_CHANGE_TOOLTIP_TEXT_ID = Misc::uuid("1390c669-be67-42bb-8db0-b8ada5a6bb87");
const boost::uuids::uuid IDS::SETTING_TOOLTIPS_TOOLTIP_TEXT_ID = Misc::uuid("e4dfa8f1-211f-4e8a-9aa1-7a850bc657e9");
const boost::uuids::uuid IDS::SETTING_DNA_SPIRAL_TOOLTIP_TEXT_ID = Misc::uuid("835c0a52-c07f-4c3a-9681-b1c8c18a42f3");
const boost::uuids::uuid IDS::SETTING_RACE_SPECIFIC_THEME_TOOLTIP_TEXT_ID = Misc::uuid("3501a1a0-6ebb-4eba-87dc-e57aeb1ccda2");
const boost::uuids::uuid IDS::SETTING_GLOWING_BUTTONS_TOOLTIP_TEXT_ID = Misc::uuid("14ad0f70-6675-4c2f-af4a-aa52dfb867bf");
const boost::uuids::uuid IDS::SETTING_COMPACT_DISPLAY_MODE_TOOLTIP_TEXT_ID = Misc::uuid("fbcb7ac1-ffdc-42d6-9209-9018a51b832b");
const boost::uuids::uuid IDS::SETTING_FACILITY_MODE_TOOLTIP_TEXT_ID = Misc::uuid("5cab7575-21c7-433f-ad70-35a83f3b5ccd");

const boost::uuids::uuid IDS::SETTING_FULLSCREEN_TOOLTIP_TEXT_ID = Misc::uuid("8e924a61-aae0-45a0-bb1a-eddca1e5d8fd");
const boost::uuids::uuid IDS::SETTING_UNLOAD_GRAPHICS_TOOLTIP_TEXT_ID = Misc::uuid("4f59c47b-7040-4ae4-b295-f7d3d9d83105");
const boost::uuids::uuid IDS::SETTING_SHOW_DEBUG_TOOLTIP_TEXT_ID = Misc::uuid("34397a65-a253-4444-ba5e-375b528ca4e6");
const boost::uuids::uuid IDS::SETTING_DESIRED_FRAMERATE_TOOLTIP_TEXT_ID = Misc::uuid("54d4f1fa-5286-4d26-9e2d-7db87026fb0b");
const boost::uuids::uuid IDS::SETTING_DESIRED_CPU_USAGE_TOOLTIP_TEXT_ID = Misc::uuid("fb5b46c0-7177-49b1-8ae0-c0262def7ed2");

const boost::uuids::uuid IDS::SETTINGS_SAVED_TEXT_ID = Misc::uuid("07ea9b5f-7487-4001-a108-3ef2c1c6f678");

const boost::uuids::uuid IDS::LANGUAGE_HAS_CHANGED_TEXT_ID = Misc::uuid("be3aeffa-e8c4-426a-a47b-b1fde7d700e1");

const boost::uuids::uuid IDS::SETTING_LANGUAGE_TEXT_ID = Misc::uuid("86816a7d-ec6a-4919-a7ba-df903adf3bae"); //160
const boost::uuids::uuid IDS::SETTING_ZERO_LANGUAGE_TEXT_ID = Misc::uuid("09006842-cf4a-4d0a-9ff8-3c0c23399d3b");
const boost::uuids::uuid IDS::SETTING_ENGLISH_LANGUAGE_TEXT_ID = Misc::uuid("2384025a-2d10-487f-8d7b-44262199b482");
const boost::uuids::uuid IDS::SETTING_GERMAN_LANGUAGE_TEXT_ID = Misc::uuid("114e4f21-6797-4d38-a235-6307b28194e2");
const boost::uuids::uuid IDS::SETTING_ITALIAN_LANGUAGE_TEXT_ID = Misc::uuid("fea1db94-7ac6-4cbe-b1e9-4a30dadfff8c");
const boost::uuids::uuid IDS::SETTING_PORTUGESE_LANGUAGE_TEXT_ID = Misc::uuid("28e6e237-62e6-46a7-8ec8-c0bd8cf7368b");
const boost::uuids::uuid IDS::SETTING_DUTCH_LANGUAGE_TEXT_ID = Misc::uuid("0e6edd2a-b1a2-4cb6-8c8f-8c43de8d7d32");
const boost::uuids::uuid IDS::SETTING_FINNISH_LANGUAGE_TEXT_ID = Misc::uuid("7be97f63-2b72-49d8-ab3c-9ee142d8477f");
const boost::uuids::uuid IDS::SETTING_GREEK_LANGUAGE_TEXT_ID = Misc::uuid("fab0a8e1-ffb6-47f2-85c3-922666a15e06");
const boost::uuids::uuid IDS::SETTING_FRENCH_LANGUAGE_TEXT_ID = Misc::uuid("74fff3c4-04a8-45a8-bb65-1318be553fc1");
const boost::uuids::uuid IDS::SETTING_SPANISH_LANGUAGE_TEXT_ID = Misc::uuid("19becac2-2dc2-41f4-8f84-2d7dc1f0266f");
const boost::uuids::uuid IDS::SETTING_POLSKI_LANGUAGE_TEXT_ID = Misc::uuid("28adcd26-be76-487b-899b-4e305eab258a");
const boost::uuids::uuid IDS::SETTING_KOREAN_LANGUAGE_TEXT_ID = Misc::uuid("bc1fbbbb-4d0b-46a0-acd2-38d42b55cd66");
const boost::uuids::uuid IDS::SETTING_CHINESE_LANGUAGE_TEXT_ID = Misc::uuid("fded55c9-adb7-4e6e-b3f6-269db5259631");
const boost::uuids::uuid IDS::SETTING_RUSSIAN_LANGUAGE_TEXT_ID = Misc::uuid("ce218cf7-a0ff-45f4-a82a-3e38a362b3d2"); //170

const boost::uuids::uuid IDS::SETTING_RESOLUTION_TEXT_ID = Misc::uuid("84b1549d-c35d-4e66-9d90-760aaccca420");
const boost::uuids::uuid IDS::SETTING_RESOLUTION_ZERO_TEXT_ID = Misc::uuid("a5c3bcb3-f89e-4518-95d6-7069461969d7");
const boost::uuids::uuid IDS::SETTING_RESOLUTION_640x480_TEXT_ID = Misc::uuid("eef82335-1d77-487e-b03d-f95cedd602c7");
const boost::uuids::uuid IDS::SETTING_RESOLUTION_800x600_TEXT_ID = Misc::uuid("750267a6-2234-4ee3-b41b-f3b241e5ae9e");
const boost::uuids::uuid IDS::SETTING_RESOLUTION_1024x768_TEXT_ID = Misc::uuid("ecaa7fb8-e79f-42bc-ad7d-8b1488a20b9b");
const boost::uuids::uuid IDS::SETTING_RESOLUTION_1280x1024_TEXT_ID = Misc::uuid("6639e5f6-552c-42cf-b3eb-175d25243de1");

const boost::uuids::uuid IDS::SETTING_BITDEPTH_TEXT_ID = Misc::uuid("ac9e84a3-28f4-4703-a8e7-6f862a62ed1e");
const boost::uuids::uuid IDS::SETTING_DEPTH_8BIT_TEXT_ID = Misc::uuid("f6e7e6be-2678-4ea3-a8ac-d063f02aadc9");
const boost::uuids::uuid IDS::SETTING_DEPTH_16BIT_TEXT_ID = Misc::uuid("c40099d3-6df9-4447-96a7-356798a6028a");
const boost::uuids::uuid IDS::SETTING_DEPTH_24BIT_TEXT_ID = Misc::uuid("f62cc0e0-438a-4100-a68b-99be1d6a5fd5");
const boost::uuids::uuid IDS::SETTING_DEPTH_32BIT_TEXT_ID = Misc::uuid("af5221f3-a9d3-4f92-b798-5f35d4c9b2ad");

const boost::uuids::uuid IDS::SETTING_THEME_TEXT_ID = Misc::uuid("4087b163-d90f-45aa-ac4c-a1671496aeb2");
const boost::uuids::uuid IDS::SETTING_ZERO_THEME_TEXT_ID = Misc::uuid("a2d0d8a3-d087-488d-bd96-3440632ea94d");
const boost::uuids::uuid IDS::SETTING_DARK_RED_THEME_TEXT_ID = Misc::uuid("831c3f85-9243-4b51-8abb-0187c05e2e30");
const boost::uuids::uuid IDS::SETTING_DARK_BLUE_THEME_TEXT_ID = Misc::uuid("525f4d07-6460-4faa-bc7a-cf66a5842224");
const boost::uuids::uuid IDS::SETTING_GREEN_THEME_TEXT_ID = Misc::uuid("82019da9-4472-4194-bbf9-e850842bc870");
const boost::uuids::uuid IDS::SETTING_YELLOW_THEME_TEXT_ID = Misc::uuid("01112e00-4123-41e4-838a-fd251d295dd1");
const boost::uuids::uuid IDS::SETTING_GREY_THEME_TEXT_ID = Misc::uuid("cc5309f8-dbad-4af7-8cdb-c732376a6473");

const boost::uuids::uuid IDS::SETWINDOW_CORE_SETTINGS_TEXT_ID = Misc::uuid("5f272059-36fc-4c56-b26b-ef04f5d5c651");
const boost::uuids::uuid IDS::SETWINDOW_SOUND_SETTINGS_TEXT_ID = Misc::uuid("f6784c9b-77c6-44e1-9793-a27a4dc7e898");
const boost::uuids::uuid IDS::SETWINDOW_GUI_SETTINGS_TEXT_ID = Misc::uuid("145eb739-ce9b-4d34-a5f7-481ae99eea3b");
const boost::uuids::uuid IDS::SETWINDOW_GRAPHIC_SETTINGS_TEXT_ID = Misc::uuid("daeeb2a4-ec85-47cf-abff-2fe3917eef5a");

const boost::uuids::uuid IDS::SETWINDOW_UI_SETTINGS_TEXT_ID = Misc::uuid("6a3cff3d-20ed-40f1-9200-da044c49cf77");
const boost::uuids::uuid IDS::SETWINDOW_LOADSAVE_SETTINGS_TEXT_ID = Misc::uuid("d85d46d4-be3b-4a5d-a2e1-a513528f9b9d");

const boost::uuids::uuid IDS::DATA_ENTRY_OPEN_BUTTON_TOOLTIP_TEXT_ID = Misc::uuid("e124329d-cc2f-415d-aa74-a36be9d59f99");
const boost::uuids::uuid IDS::DATA_ENTRY_CHECK_BUTTON_TOOLTIP_TEXT_ID = Misc::uuid("ed64c241-131b-4a91-9518-985e1f361b43");

const boost::uuids::uuid IDS::START_INIT_MAIN_WINDOW_TEXT_ID = Misc::uuid("6776506c-6a5a-44b1-9dcf-6c896a722a2e");
const boost::uuids::uuid IDS::START_INIT_HELP_WINDOW_TEXT_ID = Misc::uuid("591539d5-3105-49ed-b815-85019b2d07d6");
const boost::uuids::uuid IDS::START_INIT_SETTINGS_WINDOW_TEXT_ID = Misc::uuid("899519ac-7fcb-47e1-8640-e357a2820b2d");
const boost::uuids::uuid IDS::START_INIT_DATABASE_WINDOW_TEXT_ID = Misc::uuid("24a6d774-00ea-432b-b2b2-837b65a87aa2");
const boost::uuids::uuid IDS::START_INIT_MAP_WINDOW_TEXT_ID = Misc::uuid("92fe6acf-e7e4-46ef-9fdf-c4bc698340f5");
const boost::uuids::uuid IDS::START_INIT_MSG_WINDOW_TEXT_ID = Misc::uuid("8940f1bb-c85b-47f8-b404-10987239ebed");
const boost::uuids::uuid IDS::START_INIT_TECHTREE_WINDOW_TEXT_ID = Misc::uuid("5148a14d-e831-46be-8da3-34e9aa81cad9");
const boost::uuids::uuid IDS::START_INIT_INTRO_WINDOW_TEXT_ID = Misc::uuid("2b9421d7-15dd-40eb-b943-804d11d5befc");
const boost::uuids::uuid IDS::START_HIDING_WINDOWS_TEXT_ID = Misc::uuid("92bd4b49-fc9e-4b63-8eee-a27e2d424b30");

const boost::uuids::uuid IDS::START_PREPARE_FIRST_RUN_TEXT_ID = Misc::uuid("1617a1bd-53a4-4b55-a67a-291b0f721639");
const boost::uuids::uuid IDS::START_CHOOSING_GAME_TAB_TEXT_ID = Misc::uuid("04e6fbd9-b383-4760-aac1-6f11d4d40055");
const boost::uuids::uuid IDS::START_CREATING_GAME_TEXT_ID = Misc::uuid("1c050b29-8674-43ce-a533-a6c313d953d2");

// ------ BITMAPS ------
const boost::uuids::uuid IDS::NULL_BITMAP_ID = Misc::uuid("b428fec0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INCREASE_BITMAP_ID =  Misc::uuid("ba7a6d40-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SUB_BITMAP_ID = Misc::uuid("bd68daa0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CANCEL_BITMAP_ID = Misc::uuid("bfad7370-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_ARROW_LEFT_BITMAP_ID = Misc::uuid("c2311110-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_ARROW_RIGHT_BITMAP_ID = Misc::uuid("c47b7640-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_ARROW_UP_BITMAP_ID = Misc::uuid("c6892090-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_ARROW_DOWN_BITMAP_ID = Misc::uuid("c8ac9cd0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LOCATION_BUTTON_BITMAP_ID = Misc::uuid("cac23660-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TIME_BUTTON_BITMAP_ID = Misc::uuid("cd968c10-4dc0-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BLUE_RADIO_OFF_BITMAP_ID = Misc::uuid("017e6cb0-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BLUE_RADIO_ON_BITMAP_ID = Misc::uuid("042cc3d0-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::RED_RADIO_OFF_BITMAP_ID = Misc::uuid("06f8b510-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::RED_RADIO_ON_BITMAP_ID = Misc::uuid("09d5bd50-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::YELLOW_RADIO_OFF_BITMAP_ID = Misc::uuid("0cfffb30-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::YELLOW_RADIO_ON_BITMAP_ID = Misc::uuid("10877440-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::GREY_RADIO_OFF_BITMAP_ID = Misc::uuid("13e60890-4dca-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::GREYRADIO_ON_BITMAP_ID = Misc::uuid("173078a0-4dca-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BACKGROUND_SC_BITMAP_ID = Misc::uuid("d5d572b0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BACKGROUND1_SC2_BITMAP_ID = Misc::uuid("bd02a340-5d6d-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::BACKGROUND2_SC2_BITMAP_ID = Misc::uuid("c090d310-5d6d-11e0-80e3-0800200c9a66");

const boost::uuids::uuid IDS::BAR_BITMAP_ID = Misc::uuid("e7b281d0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::KEY_BITMAP_ID = Misc::uuid("ea0fabb0-4dc0-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::CLAWSOFTWARE_BITMAP_ID = Misc::uuid("eca809d0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLAWSOFTWARE_MONO_BITMAP_ID = Misc::uuid("ef00c6e0-4dc0-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::NEW_BITMAP_ID = Misc::uuid("f14dc420-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LOAD_BITMAP_ID = Misc::uuid("f41f0c90-4dc0-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::SAVE_BITMAP_ID = Misc::uuid("f6526750-4dc0-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::REFRESH_BITMAP_ID = Misc::uuid("f8e1ebd0-4dc0-11e0-b8af-0800200c9a66"); 

const boost::uuids::uuid IDS::BACK_BITMAP_ID = Misc::uuid("fb55aaf0-4dc0-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FORWARD_BITMAP_ID = Misc::uuid("fd655110-4dc0-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::ADD_BITMAP_ID = Misc::uuid("ffa703b0-4dc0-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::DELETE_BITMAP_ID = Misc::uuid("01f894d0-4dc1-11e0-b8af-0800200c9a66"); 

const boost::uuids::uuid IDS::HELP_BITMAP_ID = Misc::uuid("042e3980-4dc1-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::MAP_BITMAP_ID = Misc::uuid("065eae10-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SETTING_BITMAP_ID = Misc::uuid("08c3a020-4dc1-11e0-b8af-0800200c9a66"); 

const boost::uuids::uuid IDS::BLUE_BULLET_BITMAP_ID = Misc::uuid("0ceeac30-4dc1-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::RED_BULLET_BITMAP_ID = Misc::uuid("cd5a3040-4dc9-11e0-b8af-0800200c9a66"); 
const boost::uuids::uuid IDS::YELLOW_BULLET_BITMAP_ID = Misc::uuid("d31467d0-4dc9-11e0-b8af-0800200c9a66"); 

const boost::uuids::uuid IDS::ARROW_LEFT_BITMAP_ID = Misc::uuid("152c5a50-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::ARROW_RIGHT_BITMAP_ID = Misc::uuid("19685650-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::ARROW_UP_BITMAP_ID = Misc::uuid("1d9b2a90-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::ARROW_DOWN_BITMAP_ID = Misc::uuid("21fc13b0-4dc1-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::CLICKED_SMALL_ARROW_LEFT_BITMAP_ID = Misc::uuid("26bcd010-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_SMALL_ARROW_RIGHT_BITMAP_ID = Misc::uuid("28e3f5d0-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_ARROW_LEFT_BITMAP_ID = Misc::uuid("4c8c60d0-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_ARROW_RIGHT_BITMAP_ID = Misc::uuid("4e7dd090-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_SMALL_ARROW_UP_BITMAP_ID = Misc::uuid("509d0710-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_SMALL_ARROW_DOWN_BITMAP_ID = Misc::uuid("534a73d0-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_ARROW_UP_BITMAP_ID = Misc::uuid("5593c790-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_ARROW_DOWN_BITMAP_ID = Misc::uuid("57ab0ed0-4dc1-11e0-b8af-0800200c9a66");


const boost::uuids::uuid IDS::INTRO_SDL_BITMAP_ID = Misc::uuid("5be36150-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_TTF_BITMAP_ID = Misc::uuid("5ed2b910-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_IMAGE_BITMAP_ID = Misc::uuid("60d42e60-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_GUI_BITMAP_ID = Misc::uuid("62fc3e80-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SMPEG_BITMAP_ID = Misc::uuid("6542ac10-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_FMOD_BITMAP_ID = Misc::uuid("6774ce50-4dc1-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_MIXER_BITMAP_ID = Misc::uuid("697ad780-4dc1-11e0-b8af-0800200c9a66");


const boost::uuids::uuid IDS::DEFAULT_GUI_CONFIGURATION_ID = Misc::uuid("0d3c67b0-4e69-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::DEFAULT_GUI_ID = Misc::uuid("3d73caf0-4f58-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::DEFAULT_MAIN_CONFIGURATION_ID = Misc::uuid("ed97ad00-4e9c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::ENGLISH_LANGUAGE_ID = Misc::uuid("e0962fd0-3201-11e0-bc8e-0800200c9a66");
const boost::uuids::uuid IDS::GERMAN_LANGUAGE_ID = Misc::uuid("e3b06820-3201-11e0-bc8e-0800200c9a66");


const boost::uuids::uuid IDS::CURSOR_ARROW_BITMAP_ID = Misc::uuid("8739f277-e74f-422b-87b1-743bd44ee8ff");
const boost::uuids::uuid IDS::CURSOR_HAND_BITMAP_ID = Misc::uuid("2455b69d-dfa4-4850-8aee-4eacbc716748");
const boost::uuids::uuid IDS::CURSOR_CLOCK1_BITMAP_ID = Misc::uuid("39ac1d39-5315-4cf5-9992-ec990bf9dc57");
const boost::uuids::uuid IDS::CURSOR_CLOCK2_BITMAP_ID = Misc::uuid("2a402340-6871-4616-a988-7a86fed4f127");

// ----- BITMAP END -----

// ----- FONTS -----

const boost::uuids::uuid IDS::SMALL_FONT_ID = Misc::uuid("632050f0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_BOLD_FONT_ID = Misc::uuid("6dbb7710-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_SHADOW_FONT_ID = Misc::uuid("705a3dd0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_SHADOW_BOLD_FONT_ID = Misc::uuid("727073a0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_UNDERLINED_FONT_ID = Misc::uuid("74f7e1d0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SMALL_UNDERLINED_BOLD_FONT_ID = Misc::uuid("77a2dd90-50e5-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::MIDDLE_FONT_ID = Misc::uuid("7a4b6850-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MIDDLE_BOLD_FONT_ID = Misc::uuid("7d1ed3a0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MIDDLE_SHADOW_FONT_ID = Misc::uuid("7fd986d0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MIDDLE_SHADOW_BOLD_FONT_ID = Misc::uuid("82527610-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MIDDLE_UNDERLINED_FONT_ID = Misc::uuid("84953a20-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MIDDLE_UNDERLINED_BOLD_FONT_ID = Misc::uuid("86c86dd0-50e5-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::LARGE_FONT_ID = Misc::uuid("898a9b10-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LARGE_BOLD_FONT_ID = Misc::uuid("8b63c7e0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LARGE_SHADOW_FONT_ID = Misc::uuid("8d4cac20-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LARGE_SHADOW_BOLD_FONT_ID = Misc::uuid("8f44ab90-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LARGE_UNDERLINED_FONT_ID = Misc::uuid("914a66a0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::LARGE_UNDERLINED_BOLD_FONT_ID = Misc::uuid("93bee910-50e5-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::VERY_LARGE_FONT_ID = Misc::uuid("97ad3a40-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_LARGE_BOLD_FONT_ID = Misc::uuid("9a149d50-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_LARGE_SHADOW_FONT_ID = Misc::uuid("9c1b69d0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_LARGE_SHADOW_BOLD_FONT_ID = Misc::uuid("9e1a2000-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_LARGE_UNDERLINED_FONT_ID = Misc::uuid("a018fd40-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_LARGE_UNDERLINED_BOLD_FONT_ID = Misc::uuid("a24f3e30-50e5-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::HUGE_FONT_ID = Misc::uuid("c09c8190-50e5-11e0-b8af-0800200c9a66"); //TODO
const boost::uuids::uuid IDS::HUGE_BOLD_FONT_ID = Misc::uuid("c309b100-50e5-11e0-b8af-0800200c9a66"); //TODO
const boost::uuids::uuid IDS::HUGE_SHADOW_FONT_ID = Misc::uuid("c51119c0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::HUGE_SHADOW_BOLD_FONT_ID = Misc::uuid("c73b4cc0-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::HUGE_UNDERLINED_FONT_ID = Misc::uuid("c9339a50-50e5-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::HUGE_UNDERLINED_BOLD_FONT_ID = Misc::uuid("cb41b9d0-50e5-11e0-b8af-0800200c9a66");
// ----- FONTS END -----


// ----- COLORS -----
const boost::uuids::uuid IDS::NULL_COLOR_ID = Misc::uuid("06b06ac0-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TEXT_COLOR_ID = Misc::uuid("08f02190-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::WINDOW_TEXT_COLOR_ID = Misc::uuid("0bbb4f80-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_TEXT_COLOR_ID = Misc::uuid("0de7cc70-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TITLE_COLOR_ID = Misc::uuid("1068f910-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::IMPORTANT_COLOR_ID = Misc::uuid("12e96260-50e6-11e0-b8af-0800200c9a66");

// forcewindow
const boost::uuids::uuid IDS::NOT_FULFILLED_TEXT_COLOR_ID = Misc::uuid("14e5a790-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FULFILLED_TEXT_COLOR_ID = Misc::uuid("16bcd890-50e6-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::FORCE_ADD_GOAL_TEXT_COLOR_ID = Misc::uuid("18819300-50e6-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::FORCE_TEXT_COLOR_ID = Misc::uuid("1ac170e0-50e6-11e0-b8af-0800200c9a66"); //~~

const boost::uuids::uuid IDS::BIG_BUTTONS_TEXT_COLOR_ID = Misc::uuid("1dc5fe50-50e6-11e0-b8af-0800200c9a66");

// bodiagram
const boost::uuids::uuid IDS::BRIGHT_MINERALS_TEXT_COLOR_ID = Misc::uuid("1fd29730-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_GAS_TEXT_COLOR_ID = Misc::uuid("22155b40-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SUPPLY_TEXT_COLOR_ID = Misc::uuid("2429bc50-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_SUPPLY_TEXT_COLOR_ID = Misc::uuid("26c88310-50e6-11e0-b8af-0800200c9a66");

/*	const boost::uuids::uuid IDS::MINERALS_COLOR_ID = Misc::uuid("295e2210-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::GAS_COLOR_ID = Misc::uuid("2c2d95c0-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::SUPPLY_COLOR_ID = Misc::uuid("3024c090-50e6-11e0-b8af-0800200c9a66");*/

// bograph time steps font color
const boost::uuids::uuid IDS::TIMESTEPS_TEXT_COLOR_ID = Misc::uuid("32361460-50e6-11e0-b8af-0800200c9a66");	

// statistics window
const boost::uuids::uuid IDS::MINERALS_TEXT_COLOR_ID = Misc::uuid("3490f450-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::GAS_TEXT_COLOR_ID = Misc::uuid("36860d90-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TIME_TEXT_COLOR_ID = Misc::uuid("38e61da0-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::STATISTICS_FORCE_TEXT_COLOR_ID = Misc::uuid("3cb85b50-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BOLENGTH_TEXT_COLOR_ID = Misc::uuid("3edf32f0-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FITNESS_AVERAGE_TEXT_COLOR_ID = Misc::uuid("410fce90-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FITNESS_VARIANCE_TEXT_COLOR_ID = Misc::uuid("43401c10-50e6-11e0-b8af-0800200c9a66");	
const boost::uuids::uuid IDS::GENERATIONS_LEFT_TEXT_COLOR_ID = Misc::uuid("4533aeb0-50e6-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::FPS_TEXT_COLOR_ID = Misc::uuid("470f7390-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FITNESS_TEXT_COLOR_ID = Misc::uuid("497ace40-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_FITNESS_TEXT_COLOR_ID = Misc::uuid("4b505190-50e6-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DISABLED_TEXT_COLOR_ID = Misc::uuid("4d32f440-50e6-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::DARK_IMPORTANT_COLOR_ID = Misc::uuid("4f64ef70-50e6-11e0-b8af-0800200c9a66");





const boost::uuids::uuid IDS::NULL_PEN_COLOR_ID = Misc::uuid("d97d7940-5238-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BORDER_PEN_COLOR_ID = Misc::uuid("ddb1ad10-5238-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::OUTER_BORDER_PEN_COLOR_ID = Misc::uuid("652573a0-5241-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INNER_BORDER_PEN_COLOR_ID = Misc::uuid("78a55d50-5241-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INNER_BORDER_HIGHLIGHT_PEN_COLOR_ID = Misc::uuid("7b219930-5247-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BIG_BUTTONS_PEN_COLOR_ID = Misc::uuid("7f042a90-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::RECTANGLE_PEN_COLOR_ID = Misc::uuid("824fd320-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BITMAP_MARKED_PEN_COLOR_ID = Misc::uuid("854ee250-5247-11e0-b8af-0800200c9a66");

// bodiagram
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_MINERALS_PEN_COLOR_ID = Misc::uuid("88c0fea0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_GAS_PEN_COLOR_ID = Misc::uuid("8bf7bfa0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_SUPPLY_PEN_COLOR_ID = Misc::uuid("8f302e50-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_MARKER_PEN_COLOR_ID = Misc::uuid("92ddf410-5247-11e0-b8af-0800200c9a66");
// bowindow
const boost::uuids::uuid IDS::SELECT_PEN_COLOR_ID = Misc::uuid("96acaf50-5247-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DARK_BACKGROUND_PEN_COLOR_ID = Misc::uuid("99930660-5247-11e0-b8af-0800200c9a66");
// buttons
const boost::uuids::uuid IDS::MARKED_BITMAP_GREEN_PEN_COLOR_ID = Misc::uuid("9d07bac0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_YELLOW_PEN_COLOR_ID = Misc::uuid("9fee11d0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_RED_PEN_COLOR_ID = Misc::uuid("a2e7c9d0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_BASIC_PEN_COLOR_ID = Misc::uuid("a62cbba0-5247-11e0-b8af-0800200c9a66");
// bodiagram
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_PEN_COLOR_ID = Misc::uuid("a9c599d0-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_MINERALS_PEN_COLOR_ID = Misc::uuid("ad0f4690-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_GAS_PEN_COLOR_ID = Misc::uuid("affec560-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_BOLD_PEN_COLOR_ID = Misc::uuid("b2e56a90-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_MINERALS_BOLD_PEN_COLOR_ID = Misc::uuid("b77a8310-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_GAS_BOLD_PEN_COLOR_ID = Misc::uuid("bb26c230-5247-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_PEN_COLOR_ID = Misc::uuid("be149350-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_PEN_COLOR_ID = Misc::uuid("c229cd70-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_PEN_COLOR_ID = Misc::uuid("ca3a5110-5247-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_PEN_COLOR_ID = Misc::uuid("24d77da0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_PEN_COLOR_ID = Misc::uuid("27dd6aa0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_PEN_COLOR_ID = Misc::uuid("2b65f520-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_PEN_COLOR_ID = Misc::uuid("2ffabf80-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_PEN_COLOR_ID = Misc::uuid("32b5c0d0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_PEN_COLOR_ID = Misc::uuid("350492d0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_PEN_COLOR_ID = Misc::uuid("376f7850-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_PEN_COLOR_ID = Misc::uuid("39d8d730-5248-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_BOLD_PEN_COLOR_ID = Misc::uuid("3e3f1780-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_BOLD_PEN_COLOR_ID = Misc::uuid("40aae760-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_BOLD_PEN_COLOR_ID = Misc::uuid("4385f3d0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_BOLD_PEN_COLOR_ID = Misc::uuid("467fabd0-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_BOLD_PEN_COLOR_ID = Misc::uuid("48e03110-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_BOLD_PEN_COLOR_ID = Misc::uuid("4b548c70-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_BOLD_PEN_COLOR_ID = Misc::uuid("4ea34240-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_BOLD_PEN_COLOR_ID = Misc::uuid("50b9c630-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_BOLD_PEN_COLOR_ID = Misc::uuid("532dd370-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_BOLD_PEN_COLOR_ID = Misc::uuid("55bede90-5248-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_BOLD_PEN_COLOR_ID = Misc::uuid("58e37720-5248-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_PEN_COLOR_ID = Misc::uuid("80216f80-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_PEN_COLOR_ID = Misc::uuid("832539a0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_PEN_COLOR_ID = Misc::uuid("86ccbdd0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_PEN_COLOR_ID = Misc::uuid("89828f00-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_PEN_COLOR_ID = Misc::uuid("8c87dfc0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_PEN_COLOR_ID = Misc::uuid("8f4f3d20-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_PEN_COLOR_ID = Misc::uuid("927f2050-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_PEN_COLOR_ID = Misc::uuid("966b2790-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_PEN_COLOR_ID = Misc::uuid("9945e5e0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_PEN_COLOR_ID = Misc::uuid("9c205610-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_PEN_COLOR_ID = Misc::uuid("9f6bd790-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_BOLD_PEN_COLOR_ID = Misc::uuid("a2c0a7e0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_BOLD_PEN_COLOR_ID = Misc::uuid("a9ac5a90-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_BOLD_PEN_COLOR_ID = Misc::uuid("ad117e90-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_BOLD_PEN_COLOR_ID = Misc::uuid("b18aaaa0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_BOLD_PEN_COLOR_ID = Misc::uuid("b4647e90-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_BOLD_PEN_COLOR_ID = Misc::uuid("b8b7d320-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_BOLD_PEN_COLOR_ID = Misc::uuid("bb86aa90-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_BOLD_PEN_COLOR_ID = Misc::uuid("bfb53910-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_BOLD_PEN_COLOR_ID = Misc::uuid("c3065fe0-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_BOLD_PEN_COLOR_ID = Misc::uuid("c6229400-5249-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_BOLD_PEN_COLOR_ID = Misc::uuid("c8b35100-5249-11e0-b8af-0800200c9a66");


const boost::uuids::uuid IDS::GREEN_TIMESTEPS_PEN_COLOR_ID = Misc::uuid("ca9382b0-5249-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BODIAGRAM_FITNESS_PEN_COLOR_ID = Misc::uuid("cd935530-5249-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DISABLED_PEN_COLOR_ID = Misc::uuid("d1e34e60-5249-11e0-b8af-0800200c9a66");



// ------ BRUSH COLORS ------
const boost::uuids::uuid IDS::NULL_BRUSH_COLOR_ID = Misc::uuid("a2577130-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TRANSPARENT_BRUSH_COLOR_ID = Misc::uuid("a6b12e60-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::WINDOW_FOREGROUND_BRUSH_COLOR_ID = Misc::uuid("a9c1c9c0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::WINDOW_BACKGROUND_BRUSH_COLOR_ID = Misc::uuid("ad156190-55eb-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BO_DARK_BRUSH_COLOR_ID = Misc::uuid("b098e300-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BO_BRIGHT_BRUSH_COLOR_ID = Misc::uuid("b377c000-55eb-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::FORCE_LIST_BRUSH_COLOR_ID = Misc::uuid("b63e8120-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FORCE_LIST_BUTTON_BRUSH_COLOR_ID = Misc::uuid("b9ab1f30-55eb-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_BRUSH_COLOR_ID = Misc::uuid("bdd9fbd0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_BRUSH_COLOR_ID = Misc::uuid("c14e3b00-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_BRUSH_COLOR_ID = Misc::uuid("c4b35f00-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_BRUSH_COLOR_ID = Misc::uuid("c7b9e840-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_BRUSH_COLOR_ID = Misc::uuid("cc21d640-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_BRUSH_COLOR_ID = Misc::uuid("cf09db00-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_BRUSH_COLOR_ID = Misc::uuid("d243a940-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_BRUSH_COLOR_ID = Misc::uuid("d50895a0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_BRUSH_COLOR_ID = Misc::uuid("d8c7e790-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_BRUSH_COLOR_ID = Misc::uuid("dd2c0500-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_BRUSH_COLOR_ID = Misc::uuid("e02a29d0-55eb-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_BRUSH_COLOR_ID = Misc::uuid("e44bc000-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_BRUSH_COLOR_ID = Misc::uuid("e77dc610-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_BRUSH_COLOR_ID = Misc::uuid("eae24dd0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_BRUSH_COLOR_ID = Misc::uuid("ee380880-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_BRUSH_COLOR_ID = Misc::uuid("f182c6b0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_BRUSH_COLOR_ID = Misc::uuid("f5480c10-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_BRUSH_COLOR_ID = Misc::uuid("f8a1be60-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_BRUSH_COLOR_ID = Misc::uuid("fc28c240-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_BRUSH_COLOR_ID = Misc::uuid("fef54fc0-55eb-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_BRUSH_COLOR_ID = Misc::uuid("024c6a00-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_BRUSH_COLOR_ID = Misc::uuid("04ab8fb0-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_BRIGHT_UNIT_TYPE_BRUSH_COLOR_ID = Misc::uuid("07d1fd00-55ec-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::CONTINUE_BUTTON_BRUSH_COLOR_ID = Misc::uuid("1976be10-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::DARK_CONTINUE_BUTTON_BRUSH_COLOR_ID = Misc::uuid("1cfde900-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_CONTINUE_BUTTON_BRUSH_COLOR_ID = Misc::uuid("1fcc4b40-55ec-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BODIAGRAM_BACK1_BRUSH_COLOR_ID = Misc::uuid("22aed1c0-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_BACK2_BRUSH_COLOR_ID = Misc::uuid("269d4a00-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_BAR_BRUSH_COLOR_ID = Misc::uuid("2961e840-55ec-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_BRUSH_COLOR_ID = Misc::uuid("2cb7ca00-55ec-11e0-b8af-0800200c9a66");

// statistics window
const boost::uuids::uuid IDS::GENERATIONS_LEFT_BRUSH_COLOR_ID = Misc::uuid("2fe87080-55ec-11e0-b8af-0800200c9a66");	

const boost::uuids::uuid IDS::TOOLTIP_BRUSH_COLOR_ID = Misc::uuid("32c88600-55ec-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DISABLED_BRUSH_COLOR_ID = Misc::uuid("360142d0-55ec-11e0-b8af-0800200c9a66");
// ------ BRUSHES END -------

// ----- COLORS END -----



// ----- PENS ------
const boost::uuids::uuid IDS::NULL_PEN_ID = Misc::uuid("718af390-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BORDER_PEN_ID = Misc::uuid("7e82a750-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::OUTER_BORDER_PEN_ID = Misc::uuid("811c16e0-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INNER_BORDER_PEN_ID = Misc::uuid("83edad70-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INNER_BORDER_HIGHLIGHT_PEN_ID = Misc::uuid("87608d10-51bf-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BIG_BUTTONS_PEN_ID = Misc::uuid("8a3509d0-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::RECTANGLE_PEN_ID = Misc::uuid("8c9eb6d0-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BITMAP_MARKED_PEN_ID = Misc::uuid("8f4fcd10-51bf-11e0-b8af-0800200c9a66");

// bodiagram
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_MINERALS_PEN_ID = Misc::uuid("92032d40-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_GAS_PEN_ID = Misc::uuid("94570850-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_SUPPLY_PEN_ID = Misc::uuid("96809f10-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_DASHED_MARKER_PEN_ID = Misc::uuid("98ca8f10-51bf-11e0-b8af-0800200c9a66");
// bowindow
const boost::uuids::uuid IDS::SELECT_PEN_ID = Misc::uuid("9b727d90-51bf-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DARK_BACKGROUND_PEN_ID = Misc::uuid("9ffc9990-51bf-11e0-b8af-0800200c9a66");
// buttons
const boost::uuids::uuid IDS::MARKED_BITMAP_GREEN_PEN_ID = Misc::uuid("a2b8ac50-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_YELLOW_PEN_ID = Misc::uuid("a5142880-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_RED_PEN_ID = Misc::uuid("a735f710-51bf-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::MARKED_BITMAP_BASIC_PEN_ID = Misc::uuid("f875b400-51c7-11e0-b8af-0800200c9a66");
// bodiagram
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_PEN_ID = Misc::uuid("fc198eb0-51c7-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_MINERALS_PEN_ID = Misc::uuid("fea51b90-51c7-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_GAS_PEN_ID = Misc::uuid("00d1bf90-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_BOLD_PEN_ID = Misc::uuid("03a30800-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_MINERALS_BOLD_PEN_ID = Misc::uuid("061c1e50-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_GAS_BOLD_PEN_ID = Misc::uuid("0829a190-51c8-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_PEN_ID = Misc::uuid("0ab1d310-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_PEN_ID = Misc::uuid("0d33ea10-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_PEN_ID = Misc::uuid("0f3dc3d0-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_PEN_ID = Misc::uuid("126876e0-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_PEN_ID = Misc::uuid("14f90cd0-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_PEN_ID = Misc::uuid("16e9e050-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_PEN_ID = Misc::uuid("18ed5170-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_PEN_ID = Misc::uuid("1ae96f90-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_PEN_ID = Misc::uuid("1ce51880-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_PEN_ID = Misc::uuid("1eef1950-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_PEN_ID = Misc::uuid("20c70da0-51c8-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_BOLD_PEN_ID = Misc::uuid("22abac20-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_BOLD_PEN_ID = Misc::uuid("2462f910-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_BOLD_PEN_ID = Misc::uuid("2757cf10-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_BOLD_PEN_ID = Misc::uuid("29dbbad0-51c8-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_BOLD_PEN_ID = Misc::uuid("21fefbf0-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_BOLD_PEN_ID = Misc::uuid("27183890-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_BOLD_PEN_ID = Misc::uuid("29568fd0-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_BOLD_PEN_ID = Misc::uuid("2c789050-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_BOLD_PEN_ID = Misc::uuid("2ea77e40-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_BOLD_PEN_ID = Misc::uuid("30e53940-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_BOLD_PEN_ID = Misc::uuid("330cfb40-51c9-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_PEN_ID = Misc::uuid("34f23600-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_PEN_ID = Misc::uuid("37073350-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_PEN_ID = Misc::uuid("3921fd00-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_PEN_ID = Misc::uuid("3b474e00-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_PEN_ID = Misc::uuid("3d8d1f50-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_PEN_ID = Misc::uuid("4073eb90-51c9-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_PEN_ID = Misc::uuid("832acdd0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_PEN_ID = Misc::uuid("8808af20-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_PEN_ID = Misc::uuid("8b81d050-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_PEN_ID = Misc::uuid("8fce6e20-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_PEN_ID = Misc::uuid("934da9d0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_BOLD_PEN_ID = Misc::uuid("968702e0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_BOLD_PEN_ID = Misc::uuid("9af4e450-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_BOLD_PEN_ID = Misc::uuid("9e269c40-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_BOLD_PEN_ID = Misc::uuid("a140fba0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_BOLD_PEN_ID = Misc::uuid("a4cabea0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_BOLD_PEN_ID = Misc::uuid("a93321d0-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_BOLD_PEN_ID = Misc::uuid("ac680e10-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_BOLD_PEN_ID = Misc::uuid("af933650-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_BOLD_PEN_ID = Misc::uuid("b2b5fa20-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_BOLD_PEN_ID = Misc::uuid("b6e32910-521b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_BOLD_PEN_ID = Misc::uuid("bb41ef50-521b-11e0-b8af-0800200c9a66");


const boost::uuids::uuid IDS::GREEN_TIMESTEPS_PEN_ID = Misc::uuid("bf2f7d30-521b-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BODIAGRAM_FITNESS_PEN_ID = Misc::uuid("c1e85ba0-521b-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DISABLED_PEN_ID = Misc::uuid("c4f610d0-521b-11e0-b8af-0800200c9a66");
// ----- PENS END ------


// ------ BRUSHES ------
const boost::uuids::uuid IDS::NULL_BRUSH_ID = Misc::uuid("dcae80d0-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::TRANSPARENT_BRUSH_ID = Misc::uuid("e2128210-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::WINDOW_FOREGROUND_BRUSH_ID = Misc::uuid("e5958e50-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::WINDOW_BACKGROUND_BRUSH_ID = Misc::uuid("e88cd550-522b-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BO_DARK_BRUSH_ID = Misc::uuid("ec290ee0-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BO_BRIGHT_BRUSH_ID = Misc::uuid("effef610-522b-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::FORCE_LIST_BRUSH_ID = Misc::uuid("f3406570-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::FORCE_LIST_BUTTON_BRUSH_ID = Misc::uuid("f61d1f90-522b-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::UNIT_TYPE_0_BRUSH_ID = Misc::uuid("f8c00500-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_1_BRUSH_ID = Misc::uuid("fb908a20-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_2_BRUSH_ID = Misc::uuid("feaff290-522b-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_3_BRUSH_ID = Misc::uuid("01560c50-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_4_BRUSH_ID = Misc::uuid("041134b0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_5_BRUSH_ID = Misc::uuid("07dc9490-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_6_BRUSH_ID = Misc::uuid("0b104850-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_7_BRUSH_ID = Misc::uuid("0dff51f0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_8_BRUSH_ID = Misc::uuid("10bec010-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_9_BRUSH_ID = Misc::uuid("1422d2a0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::UNIT_TYPE_10_BRUSH_ID = Misc::uuid("17521990-522c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_BRUSH_ID = Misc::uuid("1ac10190-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_BRUSH_ID = Misc::uuid("1d981660-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_BRUSH_ID = Misc::uuid("208bb3e0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_BRUSH_ID = Misc::uuid("237c4420-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_BRUSH_ID = Misc::uuid("26352290-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_BRUSH_ID = Misc::uuid("28eb1ad0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_BRUSH_ID = Misc::uuid("2cae3d50-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_BRUSH_ID = Misc::uuid("2fb20770-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_BRUSH_ID = Misc::uuid("3316dd50-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_BRUSH_ID = Misc::uuid("3648e360-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_BRUSH_ID = Misc::uuid("39759240-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::VERY_BRIGHT_UNIT_TYPE_BRUSH_ID = Misc::uuid("3d6e43b0-522c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::CONTINUE_BUTTON_BRUSH_ID = Misc::uuid("41582810-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::DARK_CONTINUE_BUTTON_BRUSH_ID = Misc::uuid("4617abf0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BRIGHT_CONTINUE_BUTTON_BRUSH_ID = Misc::uuid("492c8d10-522c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::BODIAGRAM_BACK1_BRUSH_ID = Misc::uuid("4c60dd10-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_BACK2_BRUSH_ID = Misc::uuid("4f55b310-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_BAR_BRUSH_ID = Misc::uuid("52c02e40-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::BODIAGRAM_SUPPLY_BRUSH_ID = Misc::uuid("56e03dd0-522c-11e0-b8af-0800200c9a66");

// statistics window
const boost::uuids::uuid IDS::GENERATIONS_LEFT_BRUSH_ID = Misc::uuid("59b68f50-522c-11e0-b8af-0800200c9a66");	

const boost::uuids::uuid IDS::TOOLTIP_BRUSH_ID = Misc::uuid("5c5be5c0-522c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::DISABLED_BRUSH_ID = Misc::uuid("5f5d8d00-522c-11e0-b8af-0800200c9a66");
// ------ BRUSHES END -------


// ------ ANIMATIONS --------
const boost::uuids::uuid IDS::NULL_ANIMATION_ID = Misc::uuid("667cd2d0-522c-11e0-b8af-0800200c9a66");

const boost::uuids::uuid IDS::INTRO_MAIN_ANIMATION_ID = Misc::uuid("6a6a39a0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_ANIMATION_ID = Misc::uuid("6dbbae90-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_TTF_ANIMATION_ID = Misc::uuid("710904d0-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SDL_IMAGE_ANIMATION_ID = Misc::uuid("74018450-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_GUI_ANIMATION_ID = Misc::uuid("7766a850-522c-11e0-b8af-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SMPEG_ANIMATION_ID = Misc::uuid("7a81a3f0-522c-11e0-b8af-0800200c9a66");
#ifdef _FMOD_SOUND
const boost::uuids::uuid IDS::INTRO_FMOD_ANIMATION_ID = Misc::uuid("7dcc3b10-522c-11e0-b8af-0800200c9a66");
#elif _SDL_MIXER_SOUND
const boost::uuids::uuid IDS::INTRO_MIXER_ANIMATION_ID = Misc::uuid("80acecd0-522c-11e0-b8af-0800200c9a66");
#endif
// ------ END ANIMATIONS --------


// ------- BUTTON COLORS --------
/*	const boost::uuids::uuid IDS::UMS_BUTTON_ID = Misc::uuid("2e06837f-3053-4709-9ecc-ccdb07c891f9");
const boost::uuids::uuid IDS::TERRA_BUTTON_ID = Misc::uuid("51426624-fcdb-47b0-97fa-56e34ffab0e3");
const boost::uuids::uuid IDS::PROTOSS_BUTTON_ID = Misc::uuid("84141323-ef77-4de8-86a8-fd5ee7494455");
const boost::uuids::uuid IDS::ZERG_BUTTON_ID = Misc::uuid("9a126d48-9d75-41a3-b646-ec02bf6305ca");*/

const boost::uuids::uuid IDS::UNIT_TYPE_0_BUTTON_ID = Misc::uuid("a9fbf317-6eb9-400e-8bb6-2363333b2612");
const boost::uuids::uuid IDS::UNIT_TYPE_1_BUTTON_ID = Misc::uuid("46ba881f-02ed-44e6-9b58-db29e64c02b6");
const boost::uuids::uuid IDS::UNIT_TYPE_2_BUTTON_ID = Misc::uuid("46dbaa81-210a-4c25-9d0c-7824147c5eca");
const boost::uuids::uuid IDS::UNIT_TYPE_3_BUTTON_ID = Misc::uuid("30673e84-d4b5-43b1-a994-d8e888f67e64");
const boost::uuids::uuid IDS::UNIT_TYPE_4_BUTTON_ID = Misc::uuid("e3712eae-9456-4c39-b6b9-53127b477052");
const boost::uuids::uuid IDS::UNIT_TYPE_5_BUTTON_ID = Misc::uuid("c17cd94c-0f87-463a-ac9e-92969fb0e896");
const boost::uuids::uuid IDS::UNIT_TYPE_6_BUTTON_ID = Misc::uuid("602cdabf-f996-4ea2-9872-232e689db043");
const boost::uuids::uuid IDS::UNIT_TYPE_7_BUTTON_ID = Misc::uuid("8abb5a2f-01cc-49d9-b300-d59c1829ce60");
const boost::uuids::uuid IDS::UNIT_TYPE_8_BUTTON_ID = Misc::uuid("89426378-ab5d-4f76-b72f-6516b686ccb6");
const boost::uuids::uuid IDS::UNIT_TYPE_9_BUTTON_ID = Misc::uuid("eb881b70-1872-4bb0-b449-4b575e16ab62");
const boost::uuids::uuid IDS::UNIT_TYPE_10_BUTTON_ID = Misc::uuid("db5ea8bf-cc53-4849-bfc0-305182409b8e");

const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_0_BUTTON_ID = Misc::uuid("c6dad1df-a42c-407a-a709-238863e72757");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_1_BUTTON_ID = Misc::uuid("45583717-69ad-4374-918d-d8bab6b9970b");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_2_BUTTON_ID = Misc::uuid("54508d85-3a02-450e-aed4-1ac1de975523");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_3_BUTTON_ID = Misc::uuid("82fcc76f-6c60-4ee0-a29f-260f8b505771");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_4_BUTTON_ID = Misc::uuid("cc1cef4c-5511-4bc5-80d7-7d97fb54e776");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_5_BUTTON_ID = Misc::uuid("cd33bdd2-0b34-40f2-8b81-a5a9026ab557");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_6_BUTTON_ID = Misc::uuid("34c0e535-09b8-417f-963b-8c33e749a575");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_7_BUTTON_ID = Misc::uuid("d9ca7cc0-83d0-49a0-b056-f0aebd722b1e");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_8_BUTTON_ID = Misc::uuid("dbe8c7b8-0528-40d1-a810-a057ab359bc5");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_9_BUTTON_ID = Misc::uuid("04f70f4f-7d8a-484a-abae-69c2c5c83c00");
const boost::uuids::uuid IDS::BRIGHT_UNIT_TYPE_10_BUTTON_ID = Misc::uuid("8c3a884e-8f40-4c89-b194-cffb105e0cff");

const boost::uuids::uuid IDS::VERY_BRIGHT_UNIT_TYPE_BUTTON_ID = Misc::uuid("787a2ce5-8581-4046-8814-975e117e6e9b");

const boost::uuids::uuid IDS::STANDARD_BUTTON_ID = Misc::uuid("d9284ca8-665c-42ab-b548-9fd6f9caa0d5");
const boost::uuids::uuid IDS::FORCE_ENTRY_BUTTON_ID = Misc::uuid("0d219364-e931-4f83-b6dc-e5ff70e3b3e1");
const boost::uuids::uuid IDS::MODIFY_BUTTON_ID = Misc::uuid("8cc26e24-6550-45e5-b8ae-4aaf438a68d5");
const boost::uuids::uuid IDS::TAB_BUTTON_ID = Misc::uuid("6d345dbc-390e-416a-b70f-131107833ba4");
const boost::uuids::uuid IDS::MENU_ENTRY_BUTTON_ID = Misc::uuid("7a2b845c-4f74-4504-b402-dbc35064b2e1");
const boost::uuids::uuid IDS::EDIT_FIELD_BUTTON_ID = Misc::uuid("3d934a55-c6d4-4dc4-b7ce-ce2c390b0005");
const boost::uuids::uuid IDS::ARROW_BUTTON_ID = Misc::uuid("dd68ac28-e2b0-4971-be51-9c6e5d42fc06");
const boost::uuids::uuid IDS::GOAL_LOCATION_BUTTON_ID = Misc::uuid("eacfac2a-1880-4443-ae6e-62b6657a4f2e");
const boost::uuids::uuid IDS::GOAL_TIME_BUTTON_ID = Misc::uuid("6f7fb8e3-33c8-4780-9183-3a32e25aaad0");
const boost::uuids::uuid IDS::CHECK_BUTTON_ID = Misc::uuid("b08c825f-0325-4b13-a25a-203b95ea1a0c");
const boost::uuids::uuid IDS::OPEN_TREE_BUTTON_ID = Misc::uuid("1786b5b2-b640-4336-a6f0-6762213418e7");
const boost::uuids::uuid IDS::NON_GOAL_ENTRY_BUTTON_ID = Misc::uuid("d8a946ba-9ae1-4559-b663-5257b0f82b37");
const boost::uuids::uuid IDS::TEXT_BUTTON_ID = Misc::uuid("8ef614ba-5638-4aa5-b128-1d25b5481f8a");
const boost::uuids::uuid IDS::VISITED_TEXT_BUTTON_ID = Misc::uuid("6a1b9b13-1aea-4650-809c-67dfa7b7d84f");
const boost::uuids::uuid IDS::MENU_BUTTON_ID = Misc::uuid("6b28c6d0-bb49-4843-adc6-f2ad1b8255b5");
const boost::uuids::uuid IDS::HELP_BUTTON_ID = Misc::uuid("3bcf8d31-305b-4cd6-9829-7d425d4b2aa4");


const boost::uuids::uuid IDS::CLOSE_BUTTON_ID = Misc::uuid("39647445-9bea-429d-af4a-3ba76fc2993d");

//	COMPARE_GAME_BUTTON TODO
//	REMOVE_GAME_BUTTON_ID = Misc::uuid("815808b3-2103-41dc-bdbf-3f8e237b4659");

// ------- END BUTTON COLORS -------


const boost::uuids::uuid IDS::DEFAULT_BUILD_CONFIGURATION_ID = Misc::uuid("31e5c1e0-5e15-11e0-80e3-0800200c9a66");



// ------ SOUND -------
const boost::uuids::uuid IDS::NULL_SOUND_ID = Misc::uuid("4866c8a0-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::MOUSEOVER_SOUND_ID = Misc::uuid("4aee5de0-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::SWISHIN_SOUND_ID = Misc::uuid("4cbf4d50-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::SWISHOUT_SOUND_ID = Misc::uuid("4f335a90-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::SWISHLOCK_SOUND_ID = Misc::uuid("51088fc0-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::CLICKED_SOUND_ID = Misc::uuid("53608980-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::CLICK_SOUND_ID = Misc::uuid("55fb3190-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::COMPLETE_SOUND_ID = Misc::uuid("586e0650-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::ERROR_SOUND_ID = Misc::uuid("5a6c4750-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::RING_SOUND_ID = Misc::uuid("5c60c450-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_SOUND_ID = Misc::uuid("5ed9b390-5efc-11e0-80e3-0800200c9a66");
// ------- END SOUND -------

// ------- MUSIC --------
const boost::uuids::uuid IDS::NULL_MUSIC_ID = Misc::uuid("60afac10-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::GENETIC_MUSIC_ID = Misc::uuid("62b05e10-5efc-11e0-80e3-0800200c9a66");
const boost::uuids::uuid IDS::DIABLO_MUSIC_ID = Misc::uuid("64ae9f10-5efc-11e0-80e3-0800200c9a66");
// ------- END MUSIC --------


// ------ SOUND CONFIGURATION ------
const boost::uuids::uuid IDS::DEFAULT_SOUND_CONFIGURATION_ID = Misc::uuid("3122b200-6391-11e0-ae3e-0800200c9a66");
// ------ END SOUND CONFIGURATION ------


// ------- WINDOW LAYOUTS --------

const boost::uuids::uuid IDS::GAME_WINDOWLAYOUT_ID = Misc::uuid("749fe9d0-6549-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::SCORE_WINDOWLAYOUT_ID = Misc::uuid("76f376c0-6549-11e0-ae3e-0800200c9a66");

const boost::uuids::uuid IDS::PLAYER_WINDOWLAYOUT_ID = Misc::uuid("78d703d0-6549-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::FORCE_WINDOWLAYOUT_ID = Misc::uuid("7b66af60-6549-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::BUILDORDER_WINDOWLAYOUT_ID = Misc::uuid("7e7e4fa0-6549-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::BUILDORDERDIAGRAM_WINDOWLAYOUT_ID = Misc::uuid("807fec00-6549-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::BUILDORDERGRAPH_WINDOWLAYOUT_ID = Misc::uuid("83d77b70-6549-11e0-ae3e-0800200c9a66");

const boost::uuids::uuid IDS::MAIN_WINDOWLAYOUT_ID = Misc::uuid("c1619f10-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::INTRO_WINDOWLAYOUT_ID = Misc::uuid("c65cf370-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::MESSAGE_WINDOWLAYOUT_ID = Misc::uuid("c83adb30-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::HELP_WINDOWLAYOUT_ID = Misc::uuid("ca1d7de0-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::SETTINGS_WINDOWLAYOUT_ID = Misc::uuid("cc47d7f0-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::DATABASE_WINDOWLAYOUT_ID = Misc::uuid("ce566ca0-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::DATALIST_WINDOWLAYOUT_ID = Misc::uuid("d07506e0-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::MAP_WINDOWLAYOUT_ID = Misc::uuid("d2ffd070-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::INFO_WINDOWLAYOUT_ID = Misc::uuid("d4b8f220-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::TECHTREE_WINDOWLAYOUT_ID = Misc::uuid("d6a35d00-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::SAVEBOX_WINDOWLAYOUT_ID = Misc::uuid("d899fce0-6559-11e0-ae3e-0800200c9a66");
const boost::uuids::uuid IDS::DEBUG_WINDOWLAYOUT_ID = Misc::uuid("da6bafa0-6559-11e0-ae3e-0800200c9a66");
// ------- END WINDOW LAYOUTS --------


// ------- WINDOW COLORS -------
const boost::uuids::uuid IDS::STANDARD_WINDOWCOLORS_ID = Misc::uuid("ad65e312-7852-4c67-bf66-bd55a63c6430");
const boost::uuids::uuid IDS::TRANSPARENT_WINDOWCOLORS_ID = Misc::uuid("980af746-8e23-48eb-978e-ac6b4e835daa"); // transparent main window
// ------- END WINDOW COLORS --------


// ------- RESOLUTIONS ---------
const boost::uuids::uuid IDS::RESOLUTION_800x600_ID = Misc::uuid("a2cd754a-c27d-4729-951b-e7fbfadd412a");
const boost::uuids::uuid IDS::RESOLUTION_1920x1080_ID = Misc::uuid("ad476c98-6f87-4525-abce-fc608c7bc2ca");
// ------- END RESOLUTIONS ---------

// ------- RESOLUTIONS ---------
const boost::uuids::uuid RESOLUTION_640x480_ID = Misc::uuid("9d7e2f98-264a-46a8-a6ce-4e96cef7c711");
const boost::uuids::uuid RESOLUTION_800x600_ID = Misc::uuid("28953021-ad0f-4289-acbe-5b8538a94f10");
const boost::uuids::uuid RESOLUTION_1024x768_ID = Misc::uuid("40aefd63-894d-40ce-acb9-f463931eb1d3");
const boost::uuids::uuid RESOLUTION_1920x1080_ID = Misc::uuid("363e2e40-98df-4072-b6ac-a6672294cfd4");
// ------- END RESOLUTIONS ---------

// -------- OBJECT SIZES --------
const boost::uuids::uuid STANDARD_OBJECTSIZE_ID = Misc::uuid("b66c7e92-ce22-4be7-86ef-584a6e969c3d");
const boost::uuids::uuid CHILD_OBJECTSIZE_ID = Misc::uuid("ce0e61f7-a336-422b-a7a6-20f071a892a4");
// -------- END OBJECT SIZES ----------

// ------- THEMES ---------
const boost::uuids::uuid IDS::BLUE_THEME_ID = Misc::uuid("8537e258-03d5-460b-afe2-cbdb66de485e");
const boost::uuids::uuid IDS::GREY_THEME_ID = Misc::uuid("aac14dad-2120-4232-88dc-7890843b23fa");
// ------- END THEMES ---------