# main directories
SRC=src
TEST=test
FIXTURE=fixture

## individual project names

# sub projects (code)
GEOMETRY=geometry
GUI=gui
GUICORE=guicore
LANG=lang
MISC=misc
SDLWRAP=sdlwrap
AUDIO=audio

# sub projects (fixtures)
GEOMETRY_FIXTURE=geometryfixture
LANG_FIXTURE=langfixture
MISC_FIXTURE=miscfixture
SDLWRAP_FIXTURE=sdlwrapfixture
GUICORE_FIXTURE=guicorefixture
GUI_FIXTURE=guifixture
AUDIO_FIXTURE=audiofixture

# sub projects (tests)
GEOMETRY_TEST=geometrytest
LANG_TEST=langtest
MISC_TEST=misctest
SDLWRAP_TEST=sdlwraptest
GUICORE_TEST=guicoretest
GUI_TEST=guitest
AUDIO_TEST=audiotest

## directories

# sub projects (code)
GEOMETRY_DIR=$(SRC)/$(GEOMETRY)
GUI_DIR=$(SRC)/$(GUI)
GUICORE_DIR=$(SRC)/$(GUICORE)
LANG_DIR=$(SRC)/$(LANG)
MISC_DIR=$(SRC)/$(MISC)
SDLWRAP_DIR=$(SRC)/$(SDLWRAP)
AUDIO_DIR=$(SRC)/$(AUDIO)

# sub projects (fixtures)
GEOMETRY_FIXTURE_DIR=$(FIXTURE)/$(GEOMETRY_FIXTURE)
GOAL_FIXTURE_DIR=$(FIXTURE)/$(GOAL_FIXTURE)
LANG_FIXTURE_DIR=$(FIXTURE)/$(LANG_FIXTURE)
MISC_FIXTURE_DIR=$(FIXTURE)/$(MISC_FIXTURE)
SDLWRAP_FIXTURE_DIR=$(FIXTURE)/$(SDLWRAP_FIXTURE)
GUICORE_FIXTURE_DIR=$(FIXTURE)/$(GUICORE_FIXTURE)
GUI_FIXTURE_DIR=$(FIXTURE)/$(GUI_FIXTURE)
AUDIO_FIXTURE_DIR=$(FIXTURE)/$(AUDIO_FIXTURE)


# sub projects (tests)
GEOMETRY_TEST_DIR=$(TEST)/$(GEOMETRY_TEST)
LANG_TEST_DIR=$(TEST)/$(LANG_TEST)
MISC_TEST_DIR=$(TEST)/$(MISC_TEST)
SDLWRAP_TEST_DIR=$(TEST)/$(SDLWRAP_TEST)
GUICORE_TEST_DIR=$(TEST)/$(GUICORE_TEST)
GUI_TEST_DIR=$(TEST)/$(GUI_TEST)
AUDIO_TEST_DIR=$(TEST)/$(AUDIO_TEST)

BOOST_INCLUDES = -isystem /var/source/boost_1_44_0
LIBRARIES = -lSDL -lSDLmain -L/var/source/boost_1_44_0/stage/lib -lboost_serialization -lboost_program_options -lboost_thread -lboost_system -lboost_log -lboost_date_time -lboost_filesystem -lboost_signals -L/usr/local/lib -lSDL_ttf -lSDL_image -lSDL_mixer -lboost_unit_test_framework
#-lboost_unit_test_framework

PROJECT_INCLUDES = $(INCLUDES) -I $(SRC) -I $(TEST) -I $(FIXTURE)

#LD_FLAGS=-static
CPPFLAGS =
CXXFLAGS = $(LIBRARIES) $(BOOST_INCLUDES) $(PROJECT_INCLUDES) -D_SDL_MIXER_AUDIO -g -ansi -pedantic-errors -W -Wall -Wmissing-braces -Wredundant-decls -Wundef -Wunused -Wconversion -Woverloaded-virtual -Wmissing-noreturn -Wdisabled-optimization -Wsign-promo -Wwrite-strings -Wlong-long -Woverloaded-virtual -Wfloat-equal -Wreturn-type -Wparentheses -Wchar-subscripts -Wimplicit  -Wtrigraphs  -Wendif-labels -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Winline -Wold-style-cast -Wswitch-enum -Wswitch -Wswitch-default -Wno-unknown-pragmas -O0 -ftest-coverage -fprofile-arcs
#-Weffc++
#-Wunreachable-code
#-Wshadow
#-Waggregate-return
#-Wpadded

#FLAGS = -O3 -pipe -ftracer -ffast-math -march=pentium4 -fmerge-all-constants --param max-crossjump-edges=2000 --param max-gcse-memory=209715200 --param max-gcse-passes=40 --param max-pending-list-length=1000 --param max-delay-slot-insn-search=2000 --param max-delay-slot-live-search=4000 -ffast-math -enable-stack-protector

CXX = g++ 
COVERAGE = gcov


.SUFFIXES: .o .cpp

# VERY IMPORTANT: sequence is important! first is the library that is dependant on the latter libraries

# --- TEST DEPS --- 
GEOMETRY_TEST_DEPS = $(GEOMETRY_TEST_DIR)/$(GEOMETRY_TEST).a $(GEOMETRY_DIR)/$(GEOMETRY).a $(GEOMETRY_FIXTURE_DIR)/$(GEOMETRY_FIXTURE).a $(MISC_DIR)/$(MISC).a 

LANG_TEST_DEPS = $(LANG_TEST_DIR)/$(LANG_TEST).a $(LANG_FIXTURE_DIR)/$(LANG_FIXTURE).a $(LANG_DIR)/$(LANG).a $(MISC_DIR)/$(MISC).a

MISC_TEST_DEPS = $(MISC_TEST_DIR)/$(MISC_TEST).a $(MISC_FIXTURE_DIR)/$(MISC_FIXTURE).a $(MISC_DIR)/$(MISC).a

GUICORE_TEST_DEPS = $(GUICORE_TEST_DIR)/$(GUICORE_TEST).a $(GUICORE_FIXTURE_DIR)/$(GUICORE_FIXTURE).a $(GUICORE_DIR)/$(GUICORE).a $(SDLWRAP_FIXTURE_DIR)/$(SDLWRAP_FIXTURE).a $(SDLWRAP_DIR)/$(SDLWRAP).a $(GEOMETRY_DIR)/$(GEOMETRY).a $(MISC_DIR)/$(MISC).a $(LANG_DIR)/$(LANG).a

SDLWRAP_TEST_DEPS = $(SDLWRAP_TEST_DIR)/$(SDLWRAP_TEST).a $(SDLWRAP_FIXTURE_DIR)/$(SDLWRAP_FIXTURE).a $(SDLWRAP_DIR)/$(SDLWRAP).a $(GUICORE_DIR)/$(GUICORE).a $(GEOMETRY_DIR)/$(GEOMETRY).a $(MISC_DIR)/$(MISC).a $(LANG_DIR)/$(LANG).a

GUI_TEST_DEPS = $(GUI_TEST_DIR)/$(GUI_TEST).a $(GUI_FIXTURE_DIR)/$(GUI_FIXTURE).a $(GUI_DIR)/$(GUI).a $(GUICORE_FIXTURE_DIR)/$(GUICORE_FIXTURE).a $(SDLWRAP_DIR)/$(SDLWRAP).a $(GUICORE_DIR)/$(GUICORE).a $(LANG_DIR)/$(LANG).a $(GEOMETRY_DIR)/$(GEOMETRY).a $(MISC_DIR)/$(MISC).a 

AUDIO_TEST_DEPS = $(AUDIO_TEST_DIR)/$(AUDIO_TEST).a $(AUDIO_FIXTURE_DIR)/$(AUDIO_FIXTURE).a $(AUDIO_DIR)/$(AUDIO).a $(LANG_DIR)/$(LANG).a $(MISC_DIR)/$(MISC).a 


# --- TEST TARGETS ---
GEOMETRY_TEST_TARGETS = $(GEOMETRY_TEST) $(GEOMETRY) $(GEOMETRY_FIXTURE) $(MISC)

LANG_TEST_TARGETS = $(LANG) $(LANG_FIXTURE) $(LANG_TEST) $(MISC)

MISC_TEST_TARGETS = $(MISC_TEST) $(MISC) $(MISC_FIXTURE)

GUICORE_TEST_TARGETS = $(GUICORE_TEST) $(GUICORE_FIXTURE) $(SDLWRAP_FIXTURE) $(SDLWRAP) $(GUICORE) $(MISC) $(GEOMETRY)

SDLWRAP_TEST_TARGETS = $(SDLWRAP_TEST) $(SDLWRAP_FIXTURE) $(SDLWRAP) $(GUICORE) $(MISC) $(GEOMETRY) $(LANG)

GUI_TEST_TARGETS = $(GUI_TEST) $(GUI_FIXTURE) $(GUI) $(SDLWRAP) $(GUICORE_FIXTURE) $(GUICORE) $(MISC) $(GEOMETRY) $(LANG)

AUDIO_TEST_TARGETS = $(AUDIO_TEST) $(AUDIO_FIXTURE) $(AUDIO) $(LANG) $(MISC)

# --- Link programs ---

$(GEOMETRY_TEST).bin : $(GEOMETRY_TEST_TARGETS) $(GEOMETRY_TEST_DEPS)
	$(CXX) $(GEOMETRY_TEST_DEPS) $(CXXFLAGS) -o $(GEOMETRY_TEST_DIR)/$(GEOMETRY_TEST).bin

$(LANG_TEST).bin : $(LANG_TEST_TARGETS) $(LANG_TEST_DEPS)
	$(CXX) $(LANG_TEST_DEPS) $(CXXFLAGS) -o $(LANG_TEST_DIR)/$(LANG_TEST).bin

$(MISC_TEST).bin : $(MISC_TEST_TARGETS) $(MISC_TEST_DEPS)
	$(CXX) $(MISC_TEST_DEPS) $(CXXFLAGS) -o $(MISC_TEST_DIR)/$(MISC_TEST).bin
	
$(SDLWRAP_TEST).bin : $(SDLWRAP_TEST_TARGETS) $(SDLWRAP_TEST_DEPS)
	$(CXX) $(SDLWRAP_TEST_DEPS) $(CXXFLAGS) -o $(SDLWRAP_TEST_DIR)/$(SDLWRAP_TEST).bin

$(GUICORE_TEST).bin : $(GUICORE_TEST_TARGETS) $(GUICORE_TEST_DEPS)
	$(CXX) $(GUICORE_TEST_DEPS) $(CXXFLAGS) -o $(GUICORE_TEST_DIR)/$(GUICORE_TEST).bin

$(GUI_TEST).bin : $(GUI_TEST_TARGETS) $(GUI_TEST_DEPS)
	$(CXX) $(GUI_TEST_DEPS) $(CXXFLAGS) -o $(GUI_TEST_DIR)/$(GUI_TEST).bin

$(AUDIO_TEST).bin : $(AUDIO_TEST_TARGETS) $(AUDIO_TEST_DEPS)
	$(CXX) $(AUDIO_TEST_DEPS) $(CXXFLAGS) -o $(AUDIO_TEST_DIR)/$(AUDIO_TEST).bin

ALL_TESTS = trace_lang.info trace_geometry.info trace_misc.info trace_sdlwrap.info trace_guicore.info trace_gui.info trace_audio.info
#trace_ai.info trace_build.info trace_simulator.info trace_ui.info

all_tests: $(ALL_TESTS)


trace_lang.info:
	@lcov --zerocounters --directory .
	@$(LANG_TEST_DIR)/$(LANG_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_lang
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_geometry.info:
	@lcov --zerocounters --directory .
	@$(GEOMETRY_TEST_DIR)/$(GEOMETRY_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_geometry
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_misc.info:
	@lcov --zerocounters --directory .
	@$(MISC_TEST_DIR)/$(MISC_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_misc
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_sdlwrap.info:
	@lcov --zerocounters --directory .
	@$(SDLWRAP_TEST_DIR)/$(SDLWRAP_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_sdlwrap
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_guicore.info:
	@lcov --zerocounters --directory .
	@$(GUICORE_TEST_DIR)/$(GUICORE_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_guicore
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_gui.info:
	@lcov --zerocounters --directory .
	@$(GUI_TEST_DIR)/$(GUI_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_gui
	@lcov --extract $@ \*src\*  --output-file $@ ;

trace_audio.info:
	@lcov --zerocounters --directory .
	@$(AUDIO_TEST_DIR)/$(AUDIO_TEST).bin
	@lcov --capture --directory . --output-file $@ --test-name my_test_audio
	@lcov --extract $@ \*src\*  --output-file $@ ;


GENPNG = genpng
USE_GENPNG := $(shell $(GENPNG) --help >/dev/null 2>/dev/null; echo $$?)
ifeq ($(USE_GENPNG),0)
	FRAMES := --frames
else
	FRAMES :=
endif

output: 
	@LC_ALL=en_US
	@export LC_ALL
	@rm /var/www/coverage/* -rf
	@genhtml $(ALL_TESTS) --output-directory /var/www/coverage --title "ClawGUI Coverage" --show-details --description-file descriptions $(FRAMES) --legend
	@doxygen Doxyfile
	@rm /var/www/doxygen/* -rf
	@cp -r html/* /var/www/doxygen
       	
descriptions: descriptions.txt
	@gendesc descriptions.txt -o descriptions

# Compiling targets
$(GEOMETRY):
	@cd $(GEOMETRY_DIR) ; make $(GEOMETRY) ;

$(GUI):
	@cd $(GUI_DIR) ; make $(GUI) ;

$(GUICORE):
	@cd $(GUICORE_DIR) ; make $(GUICORE) ;

$(LANG):
	@cd $(LANG_DIR) ; make $(LANG) ;

$(MISC):
	@cd $(MISC_DIR) ; make $(MISC) ;

$(SDLWRAP):
	@cd $(SDLWRAP_DIR) ; make $(SDLWRAP) ;

$(AUDIO):
	@cd $(AUDIO_DIR) ; make $(AUDIO) ;

$(GEOMETRY_FIXTURE):
	@cd $(GEOMETRY_FIXTURE_DIR) ; make $(GEOMETRY_FIXTURE) ;

$(LANG_FIXTURE):
	@cd $(LANG_FIXTURE_DIR) ; make $(LANG_FIXTURE) ;

$(MISC_FIXTURE):
	@cd $(MISC_FIXTURE_DIR) ; make $(MISC_FIXTURE) ;

$(SDLWRAP_FIXTURE):
	@cd $(SDLWRAP_FIXTURE_DIR) ; make $(SDLWRAP_FIXTURE) ;

$(GUICORE_FIXTURE):
	@cd $(GUICORE_FIXTURE_DIR) ; make $(GUICORE_FIXTURE) ;

$(GUI_FIXTURE):
	@cd $(GUI_FIXTURE_DIR) ; make $(GUI_FIXTURE) ;

$(AUDIO_FIXTURE):
	@cd $(AUDIO_FIXTURE_DIR) ; make $(AUDIO_FIXTURE) ;



$(GEOMETRY_TEST):
	@cd $(GEOMETRY_TEST_DIR) ; make $(GEOMETRY_TEST) ;

$(LANG_TEST):
	@cd $(LANG_TEST_DIR) ; make $(LANG_TEST) ;

$(MISC_TEST):
	@cd $(MISC_TEST_DIR) ; make $(MISC_TEST) ;

$(SDLWRAP_TEST):
	@cd $(SDLWRAP_TEST_DIR) ; make $(SDLWRAP_TEST) ;

$(GUICORE_TEST):
	@cd $(GUICORE_TEST_DIR) ; make $(GUICORE_TEST) ;

$(GUI_TEST):
	@cd $(GUI_TEST_DIR) ; make $(GUI_TEST) ;

$(AUDIO_TEST):
	@cd $(AUDIO_TEST_DIR) ; make $(AUDIO_TEST) ;

clean:
	@cd $(GEOMETRY_DIR) ; make clean
	@cd $(GUI_DIR) ; make clean
	@cd $(GUICORE_DIR) ; make clean
	@cd $(LANG_DIR) ; make clean
	@cd $(MISC_DIR) ; make clean
	@cd $(SDLWRAP_DIR) ; make clean
	@cd $(AUDIO_DIR) ; make clean
	@cd $(GEOMETRY_FIXTURE_DIR) ; make clean
	@cd $(LANG_FIXTURE_DIR) ; make clean
	@cd $(MISC_FIXTURE_DIR) ; make clean
	@cd $(SDLWRAP_FIXTURE_DIR) ; make clean
	@cd $(GUICORE_FIXTURE_DIR) ; make clean
	@cd $(GUI_FIXTURE_DIR) ; make clean
	@cd $(AUDIO_FIXTURE_DIR) ; make clean
	@cd $(GEOMETRY_TEST_DIR) ; make clean
	@cd $(LANG_TEST_DIR) ; make clean
	@cd $(MISC_TEST_DIR) ; make clean
	@cd $(SDLWRAP_TEST_DIR) ; make clean
	@cd $(GUICORE_TEST_DIR) ; make clean
	@cd $(GUI_TEST_DIR) ; make clean
	@cd $(AUDIO_TEST_DIR) ; make clean
	@find . -name \*.gcov -type f -delete
	@find . -name \*.gcda -type f -delete
	@find . -name \*.gcno -type f -delete
	@rm -vf *.info	
	@echo "done."
