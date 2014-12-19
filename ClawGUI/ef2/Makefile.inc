# main directories
SRC=src
TEST=test
FIXTURE=fixture

BOOST_INCLUDES = -isystem /var/source/boost_1_44_0
CXXFLAGS = $(LIBRARIES) $(BOOST_INCLUDES) $(PROJECT_INCLUDES)

LIBRARIES = -lSDL -lSDLmain -L/var/source/boost_1_44_0/stage/lib -lboost_serialization -lboost_program_options -lboost_thread -lboost_system -lboost_log -lboost_date_time -lboost_filesystem -lboost_signals -L/usr/local/lib -lSDL_ttf -lSDL_image -lSDL_mixer -lboost_unit_test_framework
SDL_INCLUDES = -isystem /var/source/SDL-1.2.14/include -isystem /var/source/SDL_image-1.2.10 -isystem /var/source/SDL_ttf-2.0.10 -isystem /var/source/SDL_mixer-1.2.11
PROJECT_INCLUDES = -I $(SRC) -I $(TEST) -I $(FIXTURE)

CXXFLAGS = -D_SDL_MIXER_SOUND -g -O0 -ftest-coverage -fprofile-arcs $(LIBRARIES) $(INCLUDES) $(SDL_INCLUDES) $(BOOST_INCLUDES) -ansi -pedantic-errors -W -Wall -Wmissing-braces -Wredundant-decls -Wundef -Wunused -Wconversion -Woverloaded-virtual -Wmissing-noreturn -Wdisabled-optimization -Wsign-promo -Wwrite-strings -Wlong-long -Woverloaded-virtual -Wfloat-equal -Wreturn-type -Wparentheses -Wchar-subscripts -Wimplicit  -Wtrigraphs  -Wendif-labels -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Winline -Wold-style-cast -Wswitch-enum -Wswitch -Wswitch-default -Wno-unknown-pragmas  

$(PROG): $(PROG).a($(OBJS))

clean:
	@rm -vf *.o ${PROG}
	@rm -vf *.a
	@rm -vf *.bin
