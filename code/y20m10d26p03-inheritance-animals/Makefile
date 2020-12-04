SOURCES := $(wildcard *.cpp)
SOURCES_NO_MAIN := $(filter-out main.cpp dogs_rule.cpp example2.cpp,$(SOURCES))
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES_NO_MAIN))
TARGETS := main dogs_rule example2
DEBUG := -O2
#DEBUG := -g
CXXFLAGS := -Wall -Werror -Wpedantic -std=c++11 $(DEBUG)
LDFLAGS := -lpthread

all: $(TARGETS)

# $@ is the target
# $^ is the dependency list
# target: dependency list
main: main.o $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

example2: example2.o $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

dogs_rule: dogs_rule.o $(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $^ $(LDFLAGS)


######################################
# automatic dependency generation
#
DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@

%.o : %.cpp
%.o : %.cpp $(DEPDIR)/%.d
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(SOURCES))))
#
#
######################################

######################################
#
#
clean:
	-rm -f $(TARGETS)
	-rm -f *.o
	-rm -f *~
	-rm -rf $(DEPDIR)
#
#
######################################
