REPO := dsu-cs-3005-examples-2020-40
WEB_REPO := dsu-cs-3005-cplusplus

all:

commit-push:
	x=`git status | grep 'nothing to commit' | wc -l`; \
	if [ "$$x" = "0" ]; then \
		EDITOR="emacs -nw -q" git commit -a; \
	fi;
	git push;

update-web:
	git add -A .
	x=`git status | grep 'nothing to commit' | wc -l`; \
	if [ "$$x" = "0" ]; then \
		git commit -m 'automated daily commit'; \
	fi;
	git push;
#	ssh cgl@helios "cd courses/$(REPO)/; git pull; make install-on-helios"

install-on-helios: zip-all
	( cd ../$(WEB_REPO); make install-examples )


ARCHIVES := code/code.zip code/code.tgz
SOURCE_CODE := \
	$(shell find code -name '*.cpp') \
	$(shell find code -name '*.h') \
	$(shell find code -name '*.md') \
	$(shell find code -name '*.txt') \
	$(shell find code -name 'Makefile')

zip-all: $(ARCHIVES)

$(ARCHIVES): code.zip code.tgz
	cp code.zip code/code.zip
	cp code.tgz code/code.tgz

code.zip: $(SOURCE_CODE)
	-rm -f $(ARCHIVES)
	zip -r code.zip code

code.tgz: $(SOURCE_CODE)
	-rm -f $(ARCHIVES)
	tar -zcf code.tgz code

