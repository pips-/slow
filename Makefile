# slow - slow down output
# See LICENSE file for copyright and license details.

include config.mk

SRC = slow.c
OBJ = ${SRC:.c=.o}

all: options slow

options:
	@echo slow build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.c.o:
	@echo CC $<
	@${CC} -c ${CFLAGS} $<

${OBJ}: config.mk

slow: ${OBJ}
	@echo CC -o $@
	@${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f slow ${OBJ} slow-${VERSION}.tar.gz

dist: clean
	@echo creating dist tarball
	@mkdir -p slow-${VERSION}
	@cp -R LICENSE Makefile config.mk ${SRC} slow.1 slow-${VERSION}
	@tar -cf slow-${VERSION}.tar slow-${VERSION}
	@gzip slow-${VERSION}.tar
	@rm -rf slow-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f slow ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/slow

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/slow

.PHONY: all options clean dist install uninstall
