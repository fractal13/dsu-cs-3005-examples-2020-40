SOURCES := $(wildcard *.cpp)
SOURCES_NO_MAIN := $(filter-out main.cpp dogs_rule.cpp,$(SOURCES))
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES_NO_MAIN))

all: main dogs_rule

# $@ is the target
# $^ is the dependency list
# target: dependency list
main: main.o $(OBJECTS)
	g++ -o $@ $^

dogs_rule: dogs_rule.o $(OBJECTS)
	g++ -o $@ $^


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
